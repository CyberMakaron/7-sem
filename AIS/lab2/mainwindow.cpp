#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize(){
    numPrototypeVectors = 0;

    int i, j;
    // Очистка векторов прототипов
    for (i = 0; i < TOTAL_PROTOTYPE_VECTORS; i++){
        for (j = 0; j < MAX_ITEMS; j++){
            prototypeVector[i][j] = 0;
            ///sumVector[i][j] = 0;
        }
        members[i] = 0;
    }
    // Сброс значения принадлежности векторов к кластерам
    for (j = 0 ; j < MAX_CUSTOMERS ; j++)
        membership[j] = -1;
}

int vectorMagnitude(int *vector){
    int j, total = 0;
    for (j = 0; j < MAX_ITEMS; j++)
        if (vector[j] == 1) total++;
    return total;
}

void vectorBitwiseAnd(int *result, int *v, int *w){
    int i;
    for (i = 0; i < MAX_ITEMS; i++)
        result[i] = (v[i] && w[i]);
    return;
}

int MainWindow::createNewPrototypeVector(int *example){
    int i, cluster;
    for (cluster = 0; cluster < TOTAL_PROTOTYPE_VECTORS; cluster++)
        if (members[cluster] == 0) break;
    numPrototypeVectors++;
    for (i = 0; i < MAX_ITEMS; i++){
        prototypeVector[cluster][i] = example[i];
    }
    members[cluster] = 1;
    return cluster;
}

void MainWindow::updatePrototypeVectors(int cluster){
    int item, customer, first = 1;
    for (item = 0; item < MAX_ITEMS; item++)
        prototypeVector[cluster][item] = 0;
    for (customer = 0; customer < MAX_CUSTOMERS; customer++){
        if (membership[customer] == cluster){
            if (first){
                for (item = 0; item < MAX_ITEMS; item++)
                    prototypeVector[cluster][item] = database[customer][item];
                first = 0;
            } else {
                for (item = 0; item < MAX_ITEMS; item++)
                    prototypeVector[cluster][item] = prototypeVector[cluster][item] && database[customer][item];
            }
        }
    }
    return;
}

int MainWindow::performART1(){
    int andresult[MAX_ITEMS];
    int pvec, magPE, magP, magE;
    float result, test;
    int index, done = 0;
    int count = 50;
    while (!done){
        done = 1;
        /* По всем производственным участкам */
        for (index = 0; index < MAX_CUSTOMERS; index++){
            for (pvec = 0; pvec < TOTAL_PROTOTYPE_VECTORS; pvec++){
                /* Есть ли в этом кластере элементы? */
                if (members[pvec]){
                    //vectorBitwiseAnd(andresult, &database[index][0], &prototypeVector[pvec][0]);
                    vectorBitwiseAnd(andresult, database[index], prototypeVector[pvec]);
                    magPE = vectorMagnitude(andresult);
                    //magP = vectorMagnitude(&prototypeVector[pvec][0]);
                    magP = vectorMagnitude(prototypeVector[pvec]);
                    //magE = vectorMagnitude(&database[index][0]);
                    magE = vectorMagnitude(database[index]);
                    result = (float)magPE / (beta + (float)magP);
                    test = (float)magE / (beta + (float)MAX_ITEMS);
                    /* Тест на схожесть / Выражение 3.2 */
                    if (result > test){
                        /* Тест на внимательность / (Выражение 3.3) */
                        if (((float)magPE/(float)magE) < vigilance){
                            int old;
                            /* Убедиться, что это другой кластер */
                            if (membership[index] != pvec){
                                /* Переместить элемент в другой кластер */
                                old = membership[index];
                                membership[index] = pvec;
                                if (old >= 0){
                                    members[old]--;
                                    if (members[old] == 0) numPrototypeVectors--;
                                    updatePrototypeVectors(old);
                                }
                                members[pvec]++;
                                /* Пересчитать векторы прототипы для всех кластеров */
//                                if ((old >= 0) && (old < TOTAL_PROTOTYPE_VECTORS))
//                                    updatePrototypeVectors(old);
                                updatePrototypeVectors(pvec);
                                done = 0;
                                break;
                            } else {
                                /* Уже в этом кластере */
                            }
                        } /* Тест на внимательность */
                    }
                }
            } /* Цикл по векторам */
            /* Проверяем, обработан ли вектор */
            if (membership[index] == -1){
                /* Не был найден подходящий кластер – создаем новый кластер для этого вектора признаков */
                if(numPrototypeVectors == TOTAL_PROTOTYPE_VECTORS - 1)
                    QMessageBox::warning(this, "Ошибка", "Для правильной работы алгоритма требуется больше кластеров!");
                membership[index] = createNewPrototypeVector(&database[index][0]);
                done = 0;
            }
        } /* Цикл по производственным участкам */
        if (!count--) break;
    } /* Закончили */
    return 0;
}
void MainWindow::on_pushButton_clicked(){
    beta = ui->beta->value();
    vigilance = ui->rho->value();
    initialize();
    performART1();
    printResult();
}
QString formateVector(int* vec){
    QString str;
    for (int i = 0; i < MAX_ITEMS; i++)
        str += "| " + QString::number(vec[i]) + " ";
    return str;
}

void MainWindow::printResult(){
    QString names;
    for(int i = 0; i < MAX_ITEMS; i++){
        names += "| " + itemName[i] + " ";
    }
    QString str = "Базад данных - поставки:\nПоставка " + names + "\n";
    for (int i = 0; i < MAX_CUSTOMERS; i++)
        str += "        " + QString::number(i) + "       " + formateVector(database[i]) + "\n";
    ui->textEdit->append(str);
    ui->textEdit->append("\nРезультат работы алгоритма:");

    for(int i = 0; i < numPrototypeVectors; i++){
        str = "Вектор прототип:\n";
        str += "    " + names + "\n";
        str += "    " + formateVector(prototypeVector[i]) + "\n";
        str += "    --------------------------------------------\n";
        for(int j = 0; j < MAX_CUSTOMERS; j++){
            if(membership[j] == i)
                str += " " + QString::number(j) + " " + formateVector(database[j]) + "\n";
        }
        str += "\n";
        ui->textEdit->append(str);
    }
    str = "\n*************************************************************************************************\n";
    ui->textEdit->append(str);
}

void MainWindow::on_pushButton_clear_clicked(){
    ui->textEdit->clear();
}
