#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadModel::loadTask1(model1);
    loadModel::loadTask2(model2);
    on_task1_toggled(true);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_restart_clicked(){
    questions.reset();
    questions2.reset();
    wm.clear();
    ui->output->clear();
    if(ui->task1->isChecked())
        startTask1();
    else
        startTask2();
}

void MainWindow::on_input_returnPressed(){
    QString str, mes;
    ui->output->appendPlainText(ui->input->text());
    if (ui->task1->isChecked()){
        str = ui->input->text();
        if (questions.checkAnswer(str, mes))
            if (mes != "")
                wm << mes;
        str.clear();
        if (questions.getNextQuestion(str)){
            ui->output->appendPlainText(str);
        }
        else{
            QStringList response;
            ui->output->appendPlainText("Прямая цепочка рассуждений:");
            model1.directConclusion(wm, response);
            for (int i = 0; i < response.size(); i++)
                ui->output->appendPlainText(response[i]);
        }
    } else{
        str = ui->input->text();
        if (questions2.checkAnswer(str, mes))
            if (mes != "")
                wm << mes;
        str.clear();
        if (questions2.getNextQuestion(str)){
            ui->output->appendPlainText(str);
        }
        else{
            QStringList response;
            ui->output->appendPlainText("Прямая цепочка рассуждений:");
            model2.directConclusion(wm, response);
            for (int i = 0; i < response.size(); i++)
                ui->output->appendPlainText(response[i]);
        }
    }
    ui->input->clear();
}

void MainWindow::on_task1_toggled(bool checked){
    if (checked){
        on_restart_clicked();
    }
}

void MainWindow::on_task2_toggled(bool checked){
    if (checked){
        on_restart_clicked();
    }
}

void MainWindow::startTask1(){
    QString str;
    questions.getNextQuestion(str);
    ui->output->appendPlainText(str);
}

void MainWindow::startTask2(){
    QString str;
    questions2.getNextQuestion(str);
    ui->output->appendPlainText(str);
}
