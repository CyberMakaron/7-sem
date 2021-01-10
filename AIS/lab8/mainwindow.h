#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "prodmodel.h"
#include "loadmodel.h"
#include "questions.h"
#include "questions2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_restart_clicked();
    void on_input_returnPressed();
    void on_task1_toggled(bool checked);
    void on_task2_toggled(bool checked);
    void startTask1();
    void startTask2();

private:
    Ui::MainWindow *ui;
    ProdModel model1, model2;
    QStringList wm;
    Questions questions;
    Questions2 questions2;
};
#endif // MAINWINDOW_H
