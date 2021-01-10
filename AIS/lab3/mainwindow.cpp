#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //, cities(MAX_CITIES)
    , ants(MAX_ANTS)
    , distance(MAX_CITIES)
    , pheromone(MAX_CITIES)
{
    ui->setupUi(this);
    for (int i = 0; i < MAX_CITIES; i++){
        distance[i].resize(MAX_CITIES);
        pheromone[i].resize(MAX_CITIES);
    }

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init(void){
    best = (double)MAX_TOUR;
    int from = 0, to, ant;
    if (ui->checkBox->isChecked() || cities.length() != MAX_CITIES){
        cities.clear();
        while (from < MAX_CITIES){
            City tmp;
            if (!cities.contains(tmp)){
                cities.append(tmp);
                for (to = 0; to < MAX_CITIES; to++){
                    distance[from][to] = 0.0;
                    pheromone[from][to] = INIT_PHEROMONE;
                }
                from++;
            }
        }
    } else{
        for (from = 0; from < MAX_CITIES; from++)
            for (to = 0; to < MAX_CITIES; to++){
                distance[from][to] = 0.0;
                pheromone[from][to] = INIT_PHEROMONE;
            }
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

    /* Инициализация муравьев */
    to = 0;
    for (ant = 0; ant < MAX_ANTS; ant++) {
        /* Распределяем муравьев по городам равномерно */
        if (to == MAX_CITIES)
            to = 0;
        ants[ant].curCity = to++;
        for (from = 0; from < MAX_CITIES; from++){
            ants[ant].tabu[from] = 0;
            ants[ant].path[from] = -1;
        }
        ants[ant].pathIndex = 1;
        ants[ant].path[0] = ants[ant].curCity;
        ants[ant].nextCity = -1;
        ants[ant].tourLength = 0.0;
        /* Помещаем исходный город, в котором находится муравей, в список табу */
        ants[ant].tabu[ants[ant].curCity] = 1;
    }
}

void MainWindow::restartAnts(void){
    int ant, i, to=0;
    for (ant = 0; ant < MAX_ANTS; ant++){
        if (ants[ant].tourLength < best){
            best = ants[ant].tourLength;
            bestIndex = ant;
        }
        ants[ant].nextCity = -1;
        ants[ant].tourLength = 0.0;
        for (i = 0; i < MAX_CITIES; i++){
            ants[ant].tabu[i] = 0;
            ants[ant].path[i] = -1;
        }
        if (to == MAX_CITIES)
            to = 0;
        ants[ant].curCity = to++;
        ants[ant].pathIndex = 1;
        ants[ant].path[0] = ants[ant].curCity;
        ants[ant].tabu[ants[ant].curCity] = 1;
    }
}

double MainWindow::antProduct(int from, int to){
    return ((qPow(pheromone[from][to], alpha) * qPow((1.0 / distance[from][to]), beta)));
}

int MainWindow::selectNextCity(int ant){
    int from, to, max_to;
    double max_p = 0;
    double denom = 0.0;
    /* Выбрать следующий город */
    from = ants[ant].curCity;
    /* Расчет знаменателя */
    for (to = 0; to < MAX_CITIES; to++)
        if (ants[ant].tabu[to] == 0)
            denom += antProduct(from, to);
    do {
        double p;
        to++;
        if (to >= MAX_CITIES)
            to = 0;
        if (ants[ant].tabu[to] == 0){
            p = antProduct(from, to)/denom;
            if (p > max_p){
                max_p = p;          // для 1/2 муравьёв по наибольшей вероятности
                max_to = to;
            }
            if (rand() / (double)RAND_MAX < p && ant % 2 == 0) break;  //для 1/2 муравьёв случайно на основе ферментов
        }
    } while ((to != MAX_CITIES - 1 && ant % 2 != 0) || ant % 2 == 0);
    if (ant % 2 == 0)
        return to;
    else
        return max_to;
}

int MainWindow::simulateAnts(void){
    int k;
    int moving = 0;
    for (k = 0; k < MAX_ANTS; k++){
        /* Убедиться, что у муравью есть куда идти */
        if (ants[k].pathIndex < MAX_CITIES){
            ants[k].nextCity = selectNextCity(k);
            ants[k].tabu[ants[k].nextCity] = 1;
            ants[k].path[ants[k].pathIndex++] = ants[k].nextCity;
            ants[k].tourLength += distance[ants[k].curCity][ants[k].nextCity];
            /* Обработка окончания путешествия (из последнего города в первый) */
            if (ants[k].pathIndex == MAX_CITIES)
                ants[k].tourLength += distance[ants[k].path[MAX_CITIES-1]][ants[k].path[0]];
            ants[k].curCity = ants[k].nextCity;
            moving++;
        }
    }
    return moving;
}

void MainWindow::updateTrails(void){
    int from, to, i, ant;
    /* Испарение фермента */
    for (from = 0; from < MAX_CITIES; from++)
        for (to = 0; to < MAX_CITIES; to++)
            if (from != to) {
                pheromone[from][to] *= (1.0 - rho);
                if (pheromone[from][to] < 0.0)
                    pheromone[from][to] = INIT_PHEROMONE;
            }
    /* Нанесение нового фермента */
    /* Для пути каждого муравья */
    for (ant = 0; ant < MAX_ANTS; ant++){
        /* Обновляем каждый шаг пути */
        for (i = 0; i < MAX_CITIES; i++){
            if (i < MAX_CITIES - 1){
                from = ants[ant].path[i];
                to = ants[ant].path[i+1];
            } else {
                from = ants[ant].path[i];
                to = ants[ant].path[0];
            }
            pheromone[from][to] += (qval / ants[ant].tourLength);
            pheromone[to][from] = pheromone[from][to];
        }
    }
    for (from = 0 ; from < MAX_CITIES ; from++) {
        for (to = 0 ; to < MAX_CITIES ; to++) {
            pheromone[from][to] *= rho;
        }
    }
}

void MainWindow::start(){
    alpha = ui->SpinBox_alpha->value();
    beta = ui->SpinBox_beta->value();
    rho = ui->SpinBox_rho->value();
    int curTime = 0;
    srand(time(NULL));
    init();
    while (curTime++ < MAX_TIME){
        if (simulateAnts() == 0){
            updateTrails();
            if (curTime != MAX_TIME)
                restartAnts();
            qDebug() << "Time is: " << curTime << "best: " << best;

        }
    }
    if (ui->checkBox_2->isChecked())
        ui->widget->setData(cities, ants);
    else
        ui->widget->setData(cities, ants[bestIndex]);
    qDebug() << "best tour: " << best;
}

void MainWindow::on_pushButton_clicked(){
    start();
}
