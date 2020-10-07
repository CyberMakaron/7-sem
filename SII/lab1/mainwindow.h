#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include <QVector>
#include <QMessageBox>
#include <QTime>
#include <QGridLayout>
#include "dialogplots.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Member{
public:
    QVector<int> sol;
    QVector<bool> conflicting;
    int energy = -1;
    Member(int N): sol(N), conflicting(N){
        for(int i = 0; i < N; i++)
            conflicting[i] = false;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void tweakSolution(Member &mem);
    void initializeSolution(Member &mem);
    void computeEnergy(Member &mem);
    void copySolution(Member &dest, Member &src);
    void mainAlgorithm();
    void printResult(Member &mem);

private slots:
    void on_button_start_clicked();
    void on_button_showplots_clicked();

private:
    Ui::MainWindow *ui;
    float Tmax, Tmin, alpha;
    int N = -1, steps;
    bool ready = true;
    QTime time;
    QVector<float> temp;
    QVector<uint> bad_count, best_energy;
    Member* best_sol;
};

#endif // MAINWINDOW_H
