#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "semanticnetwork.h"
#include "loadnetwork.h"
#include "parsertask3.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
    void parser1(QString str);
    void parser2(QString str);
    void parser3(QString str);

private slots:
    void on_in_returnPressed();
    void on_clear_clicked();
    void on_task1_toggled(bool checked);
    void on_task2_toggled(bool checked);
    void on_task3_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    SemanticNetwork network1;
    SemanticNetwork network2;
    SemanticNetwork network3;

};
#endif // MAINWINDOW_H
