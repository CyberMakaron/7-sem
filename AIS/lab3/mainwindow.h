#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();
    void restartAnts();
    double antProduct(int from, int to);
    int selectNextCity(int ant);
    int simulateAnts();
    void updateTrails();
    void start();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    float alpha = 1.0;       /* Относительная значимость пути (значимость фермента на пути - вес) */
    float beta = 5.0;        /* Приоритет расстояния над количеством фермента - коэф. эвристики */
    float rho = 0.5;         /* Интенсивность / Испарение */
    float qval = 100;        /* Q  - кол-во фермента */

    QVector<City> cities;
    QVector<Ant> ants;
    QVector<QVector<double>> distance;
    QVector<QVector<double>> pheromone;
    double best;
    int bestIndex;
};
#endif // MAINWINDOW_H
