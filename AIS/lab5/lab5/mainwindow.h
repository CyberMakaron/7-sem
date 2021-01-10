#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMath>
#include <QVector>
#include <QString>
#include "city.h"
#include "includes.h"
#include "plot.h"
#include <QTimer>

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
    void mainAlg();
    void initPopulation();
    void initMember(int pop, int index);
    void performFitness();
    int performSelection();
    int selectParent();
    void performReproduction(int parentA, int parentB, int childA, int childB);
    void mutate(int chrom);
    void crossing(int parentA, int parentB, int childA, int childB);

private slots:
    void on_buttonStart_clicked();
    void on_onlyBest_stateChanged(int arg1);
    void on_buttonStartShow_clicked();
    void timerTick();

private:
    Ui::MainWindow *ui;

    QVector<City> cities;
    QVector<QVector<double>> distance;
    PopulationType populations[2][MAX_CHROMS]; // популяция старая и новая
    int curPop;                                 // текущая популяция
    double maxFitness;
    double avgFitness;
    double minFitness;
    double totFitness;
    int curCrossovers, curMutations, bestIndex;
//    QTimer *tmr;
//    PopulationType populationsBuffer[MAX_CHROMS];
    bool isShowing = false;
//    PopulationType curBufferIndex[SPLIT_COUNT];
};

#endif // MAINWINDOW_H


