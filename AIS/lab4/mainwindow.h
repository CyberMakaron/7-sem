#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>
#include <QString>
#include  "defines.h"
#include <QPushButton>
#include <QVector>
#include <QDebug>
#include "pixels.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void assignRandomWeights();
    void init();
    double sigmoid(double val);
    double sigmoidDerivative(double val);
    void feedForward();
    void backPropagate();
    int action(double *vector);

private slots:
    void on_button_start_clicked();
    void button_grid_clicked();
    void on_listWidget_currentRowChanged(int currentRow);
    void on_button_clear_clicked();
    void on_button_identify_clicked();

private:
    Ui::MainWindow *ui;
    /* Коэффициент обучения */
    double learn_rate;
    /* Веса */
    /* Вход скрытых ячеек (со смещением) */
    double wih[INPUT_NEURONS+1][HIDDEN_NEURONS];
    /* Вход выходных ячеек (со смещением) */
    double who[HIDDEN_NEURONS+1][OUTPUT_NEURONS];
    /* Активаторы */
    double inputs[INPUT_NEURONS];
    double hidden[HIDDEN_NEURONS];
    double target[OUTPUT_NEURONS];
    double actual[OUTPUT_NEURONS];
    /* Ошибки */
    double erro[OUTPUT_NEURONS];
    double errh[HIDDEN_NEURONS];
    Pixels buttons_grid;
    int era;
    bool isLearn;
};

#endif // MAINWINDOW_H
