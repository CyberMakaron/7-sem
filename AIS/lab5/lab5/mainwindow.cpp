#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QLegend>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , distance(MAX_CITIES)
{
    ui->setupUi(this);
    for (int i = 0; i < MAX_CITIES; i++)
        distance[i].resize(MAX_CITIES);
    init();
//    tmr = new QTimer();
//    tmr->setInterval(300);
//    connect(tmr, SIGNAL(timeout()), this, SLOT(timerTick()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init(){
    int from = 0, to;
    if (ui->refreshCities->isChecked() || cities.length() != MAX_CITIES){
        cities.clear();
        while (from < MAX_CITIES){
            City tmp;
            if (!cities.contains(tmp)){
                cities.append(tmp);
                for (to = 0; to < MAX_CITIES; to++)
                    distance[from][to] = 0.0;
                from++;
            }
        }
    } else{
        for (from = 0; from < MAX_CITIES; from++)
            for (to = 0; to < MAX_CITIES; to++)
                distance[from][to] = 0.0;
    }

    /* Вычисляем расстояние между городами */
    for (from = 0; from < MAX_CITIES; from++){
        for (to = 0; to < MAX_CITIES; to++){
            if ((to != from) && (distance[from][to] == 0.0)) {
                distance[from][to] = cities[from].calcDistance(cities[to]);
                distance[to][from] = distance[from][to];
            }
        }
    }
    curPop = 0;
}

bool addToSet(int* arr, int x, int l){
    for (int i = 0; i < l; i++)
        if (arr[i] == x)
            return false;
    arr[l] = x;
    return true;
}

void MainWindow::initMember(int pop, int index){
    populations[pop][index].fitness = 0.0;
    /* Случайным образом создаем новый путь */
    int i = 0;
    while (i < MAX_CITIES)
        if (addToSet(populations[pop][index].cities, getRand(MAX_CITIES), i))
            i++;
}

void MainWindow::initPopulation(){
    int index;
    /* Инициализируем каждую хромосому в популяции */
    for (index = 0 ; index < MAX_CHROMS ; index++) {
        initMember(curPop, index);
    }
}


void MainWindow::performFitness(){
    totFitness = 0.0;
    int chrom = 0, i = 0;
    maxFitness = 0.0;
    avgFitness = 0.0;
    minFitness = 0.0;

    double cur_dist;
    int A, B;
    for (chrom = 0 ; chrom < MAX_CHROMS; chrom++) {
        populations[curPop][chrom].fitness = 0.0;
        cur_dist = 0.0;
        for (i = 0 ;i < MAX_CITIES - 1; i++) {
            A = populations[curPop][chrom].cities[i];
            B = populations[curPop][chrom].cities[i+1];
            cur_dist += distance[A][B];
        }
        A = populations[curPop][chrom].cities[MAX_CHROMS-1];
        B = populations[curPop][chrom].cities[0];
        cur_dist += distance[A][B];
        // TODO
        //populations[curPop][chrom].fitness = -cur_dist;  /// тут жёсткий костыль для перехода к максимизации
        populations[curPop][chrom].fitness = MAX_CITIES * MAX_DISTANCE / cur_dist;

        /* Обновить значение общего здоровья популяции */
        totFitness += populations[curPop][chrom].fitness;

        if (chrom == 0){
            maxFitness = totFitness;
            minFitness = totFitness;
        } else
            if (populations[curPop][chrom].fitness > maxFitness){
                bestIndex = chrom;
                maxFitness = populations[curPop][chrom].fitness;
            }
            else
                if (populations[curPop][chrom].fitness < minFitness)
                    minFitness = populations[curPop][chrom].fitness;

    }
    /* Вычислить среднее здоровье популяции */
    avgFitness = totFitness / (float)MAX_CHROMS;
}

void delay(int msec){
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::mainAlg(){
    int generation = 0, i;

    /* Инициализация генератора случайных чисел */
    srand(time(NULL));
    curPop = 0;

    /* Инициализируем начальную популяцию и проверяем здоровье хромосом в ней */
    initPopulation();
    performFitness();

    /* Цикл до максимального количества поколений */
    while (generation < MAX_GENERATIONS) {
        curCrossovers = curMutations = 0;
        /* Выбрать 2-х родителей, и, скрестив их, создать 2-х детей */
        performSelection();
        /* Смена поколений */
        curPop = (curPop == 0) ? 1 : 0;
        /* Вычислить здоровье новой популяции */
        performFitness();
        /* Вывести статистику (каждые 100 поколений) */
        if ((generation++ % SPLIT_COUNT) == 0) {
            qDebug() << "Поколение " << generation - 1;
            qDebug() << "Макс. Fitness: " << maxFitness;
            qDebug() << "Ср. Fitness: " << avgFitness;
            qDebug() << "Мин. Fitness: " << minFitness;
            qDebug() << "Скрещиваний: " << curCrossovers;
            qDebug() << "Мутаций: " << curMutations;
            qDebug() << "Процент мутаций: " << 100 - round(avgFitness / maxFitness) * 100 << endl << endl;
            if (isShowing){
                if (ui->onlyBest->isChecked())
                    ui->widget->setData(cities, populations[curPop][bestIndex]);
                else
                    ui->widget->setData(cities, populations[curPop]);
                ui->statusBar->showMessage(QString::number(generation - 1) + " / " + QString::number(MAX_GENERATIONS));
                update();
                delay(100);
            }
        }
        /* Проверить однородность популяции. Если популяция однородна, то выйти из программы */
        if ( generation > (MAX_GENERATIONS * 0.25) ) {
            if ((avgFitness / maxFitness) > 0.98) {
                qDebug() << "Популяция однородна";
                break;
            }
        }
    }
    /* Вывести окончательную статистику */
    qDebug() << "Поколение: " << generation - 1;
    qDebug() << "Макс. Fitness: " << maxFitness << maxFitness;
    qDebug() << "Ср. Fitness: " << avgFitness;
    qDebug() << "Мин. Fitness: " << minFitness;
    qDebug() << "Скрещиваний: " << curCrossovers;
    qDebug() << "Мутаций: " << curMutations;
    qDebug() << "Процент: " << round(avgFitness / maxFitness) * 100 << endl << endl;
    /* Вывести окончательную статистику */
//    for (i = 0 ; i < MAX_CHROMS ; i++) {
//        if (populations[curPop][i].fitness == maxFitness) {
//            bestIndex = i;
//            qDebug() << populations[curPop][i].cities;
//        }
//    }
    QString mes = "Скрещиваний: " + QString::number(curCrossovers) + "; Мутаций: " + QString::number(curMutations);
    mes += "; Среднее здоровье популяции: " + QString::number(MAX_CITIES * MAX_DISTANCE / avgFitness);
    mes += "; Особь с наибольшим здоровьем: " + QString::number(MAX_CITIES * MAX_DISTANCE / maxFitness);
    mes += "; Особь с наименьшим здоровьем: " + QString::number(MAX_CITIES * MAX_DISTANCE / minFitness);
    ui->statusBar->showMessage(mes);
    if (ui->onlyBest->isChecked())
        ui->widget->setData(cities, populations[curPop][bestIndex]);
    else
        ui->widget->setData(cities, populations[curPop]);
}


int MainWindow::performSelection() {
    int par1, par2;     // особи текущей популяции
    int child1, child2; // особи новой популяции
    int chrom;
    /* Цикл по хромосомам с шагом 2 */
    for (chrom = 0; chrom < MAX_CHROMS; chrom += 2) {
        /* Выбираем 2-х родителей случайным образом */
        par1 = selectParent();
        par2 = selectParent();
        /* Дети помещаются в массив по текущему индексу */
        child1 = chrom;
        child2 = chrom+1;
        /* Применение генетиеских операторов и получение потомстваы */
        performReproduction( par1, par2, child1, child2 );
    }
    return 0;
}

int MainWindow::selectParent() {
    double fit_sum = 0.0;
    double rand_val = totFitness * getSRand();
    for (int chrom = 0; chrom < MAX_CHROMS - 1; chrom++){
        fit_sum += populations[curPop][chrom].fitness;
        if (fit_sum > rand_val)
            return chrom;
    }
    return MAX_CHROMS - 1; // если не предыдущие, то последний
}

void MainWindow::performReproduction(int parentA, int parentB, int childA, int childB) {
    int nextPop = (curPop == 0) ? 1 : 0;
    // скрещивание либо происходит, либо особи копируются в следующее поколение
    if (getSRand() < ui->crossingProb->value()){
        curCrossovers++;
        crossing(parentA, parentB, childA, childB);
    }
    else
        for(int i = 0; i < MAX_CITIES; i++){
            populations[nextPop][childA].cities[i] = populations[curPop][parentA].cities[i];
            populations[nextPop][childB].cities[i] = populations[curPop][parentB].cities[i];
        }

    //мутация для всех хромосом по вероятности
    for (int i = 0; i < MAX_CITIES; i++)
        if (getSRand() < ui->mutationProb->value()){
            curMutations++;
            mutate(i);
        }
}

void swapInt(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}

int indexOfInt(int* arr, int key, int l){
    for (int i = 0; i < l; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

void MainWindow::crossing(int parentA, int parentB, int childA, int childB){
    int crossingCount = ui->crossingValue->value() * MAX_CITIES;
    if (crossingCount == 0) crossingCount = 1;
    else if (crossingCount == MAX_CITIES) crossingCount = MAX_CITIES - 1;

    int i = 0;
    int indexes1[MAX_CITIES], indexes2[MAX_CITIES];
    for (int i = 0; i < MAX_CITIES; i++){
        indexes1[i] = -1;
        indexes2[i] = -1;
    }

    while (i < crossingCount)
        if (addToSet(indexes1, getRand(MAX_CITIES), i))
            i++;
    for (int i = 0; i < crossingCount; i++)
        indexes2[i] = indexOfInt(populations[curPop][parentB].cities, populations[curPop][parentA].cities[indexes1[i]], MAX_CITIES);

    int nextPop = (curPop == 0) ? 1 : 0;
    int j = 0;
    //в чайлде В хромосома родителя В с заменой не выпавших в indexes2 на соответствующие из родителя А
    for (int i = 0; i < MAX_CITIES; i++){
        if (indexOfInt(indexes2, i, MAX_CITIES) != -1)
            populations[nextPop][childB].cities[i] = populations[curPop][parentB].cities[i];
        else
            for(;;){
                if (indexOfInt(indexes1, j, MAX_CITIES) == -1){
                    populations[nextPop][childB].cities[i] = populations[curPop][parentA].cities[j];
                     j++;
                    break;
                }
                 j++;
            }
    }

    j = 0;
    //в чайлде А хромосома родителя А с заменой выпавших в indexes1 на соответствующие из родителя В
    for (int i = 0; i < MAX_CITIES; i++){
        if (indexOfInt(indexes1, i, MAX_CITIES) == -1)
            populations[nextPop][childA].cities[i] = populations[curPop][parentA].cities[i];
        else
            for(;;){
                if (indexOfInt(indexes2, j, MAX_CITIES) != -1){
                    populations[nextPop][childA].cities[i] = populations[curPop][parentB].cities[j];
                     j++;
                    break;
                }
                 j++;
            }
    }
}

void MainWindow::mutate(int chrom){
    int x = getRand(MAX_CITIES);
    int y = getRand(MAX_CITIES);
    swapInt(populations[curPop][chrom].cities[x], populations[curPop][chrom].cities[y]);
}


void MainWindow::on_buttonStart_clicked(){
    init();
    mainAlg();
}

void MainWindow::on_onlyBest_stateChanged(int arg1){
    if (ui->onlyBest->isChecked())
        ui->widget->setData(cities, populations[curPop][bestIndex]);
    else
        ui->widget->setData(cities, populations[curPop]);
}

void MainWindow::on_buttonStartShow_clicked(){
//    curBufferIndex = 0;
//    tmr->start();
    isShowing = true;
    init();
    mainAlg();
    isShowing = false;
}

void MainWindow::timerTick(){

}
