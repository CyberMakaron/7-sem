#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define MAX_ITEMS 11        // ограничение на длину вектора признаков
#define MAX_CUSTOMERS 10    // ограничение на количество участков
#define TOTAL_PROTOTYPE_VECTORS 10

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialize();
    int createNewPrototypeVector(int *example);
    void updatePrototypeVectors(int cluster);
    int performART1();
    void printResult();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;

    float beta = 1.0;         // бэта параметр - небоьшое положительное число
    float vigilance = 0.9;    // 0 <= внимательность < 1
    int numPrototypeVectors = 0;    // Количество векторов прототипов
    int prototypeVector[TOTAL_PROTOTYPE_VECTORS][MAX_ITEMS];
    // Количество членов в кластерах
    int members[TOTAL_PROTOTYPE_VECTORS];
    // Номер кластера, к которому принадлежит поставка
    int membership[MAX_CUSTOMERS];
    // Строковые названия элементов векторов
    QString itemName[MAX_ITEMS] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K" };
    /* Массив векторов признаков. Поля представляют поставляемое оборудование.
    *  Нуль – товар не поставляется в данной поставке */
    int database[MAX_CUSTOMERS][MAX_ITEMS] = {{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                                              { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                                              { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
                                              { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},
                                              { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                                              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                                              { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                              { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                                              { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                                              { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}};

};
#endif // MAINWINDOW_H
