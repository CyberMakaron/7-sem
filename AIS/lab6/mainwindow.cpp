#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_task1_toggled(true);
    LoadNetwork::loadTask1(network1);
    LoadNetwork::loadTask2(network2);
    LoadNetwork::loadTask3(network3);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::parser1(QString str){
    int n = str.toInt();
    QStringList list;
    QString mes;
    switch (n){
        case 1:
            mes = "Ваш вопрос: Y, где partOf(Современные технологии тюнинга автомобилей, Y) и isA(Y, Название журнала)";
            ui->out->appendPlainText(mes);
            if (network1.query(QStringList("Современные технологии тюнинга автомобилей"), "2", QStringList("Название журнала"), "1", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
        case 2:
            mes = "Ваш вопрос: Y, где partOf(Мужчины, Y) и isA(Y, Название журнала)";
            ui->out->appendPlainText(mes);
            if (network1.query(QStringList("Мужчины"), "2", QStringList("Название журнала"), "1", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
        case 3:
            mes = "Ваш вопрос: Y, где partOf(100, Y) и isA(Y, Название журнала)";
            ui->out->appendPlainText(mes);
            if (network1.query(QStringList("100"), "2", QStringList("Название журнала"), "1", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
        case 4:
            mes = "Ваш вопрос: Y, где partOf(Да, Y) и isA(Y, Название журнала)";
            ui->out->appendPlainText(mes);
            if (network1.query(QStringList("Да"), "2", QStringList("Название журнала"), "1", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
    }
}

void MainWindow::parser2(QString str){
    int n = str.toInt();
    QStringList list;
    QString mes;
    switch (n){
        case 1:
            mes = "Ваш вопрос: X, где partOf(X, Отдел маркетинга) и isA(X, Начальник отдела)";
            ui->out->appendPlainText(mes);
            if (network2.query(QStringList("Отдел маркетинга"), "1", QStringList("Начальник отдела"), "1", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
        case 2:
            mes = "Ваш вопрос: X, где partOf(X, ООО \"Создвездие\") и isA(X, Задание)";
            ui->out->appendPlainText(mes);
            if (network2.query(QStringList("ООО \"Созвездие\""), "1", QStringList("Задание"), "1", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
        case 3:
            mes = "Ваш вопрос: Y и Z, где partOf(Иванов И.И., Y), isA(Иванов И.И., Z)";
            ui->out->appendPlainText(mes);
            if (network2.query(QStringList(), "", QStringList("Иванов И.И."), "2", list) == 0
                    && network2.query(QStringList("Иванов И.И."), "2", QStringList(), "", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
        case 4:
            mes = QString("Ваш вопрос: X и Z, где partOf(X, Программирование) и isA(X, Срок начала этапа) и partOf(X, Разработка Интернет - браузера \"Созвездие\"),") +
                  "partOf(Z, Программирование) и isA(Z, Срок окончания этапа) и partOf(Z, Разработка Интернет - браузера \"Созвездие\")";
            ui->out->appendPlainText(mes);
            QStringList l1("Программирование"); l1.append("Разработка Интернет - браузера \"Созвездие\"");
            if (network2.query(l1, "11", QStringList("Срок начала этапа"), "1", list) == 0
                    && network2.query(l1, "11", QStringList("Срок окончания этапа"), "1", list) == 0){
                ui->out->appendPlainText("Ответ:");
                for (int i = 0; i < list.size(); i++)
                    ui->out->appendPlainText(list[i]);
            }
            else
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            break;
    }
}

void MainWindow::parser3(QString str){
    ParserTask3 parser(network3);
    QStringList list;
    QVector<pars_struc> res;
    if (parser.parse(str, res)){
        for(int i = 0; i < res.size(); i++){
            if (network3.query(res[i].partOfList, res[i].p1, res[i].isAList, res[i].p2, list) != 0){
                ui->out->appendPlainText("Ошибка при обраотке вопроса");
            }
        }
        ui->out->appendPlainText("Ответ:");
        for (int i = 0; i < list.size(); i++)
            ui->out->appendPlainText(list[i]);
    } else
        ui->out->appendPlainText("Ошибка при парсинге вопроса");
}

void MainWindow::on_in_returnPressed(){
    if (ui->task1->isChecked()){
        parser1(ui->in->text());
    }
    if (ui->task2->isChecked()){
        parser2(ui->in->text());
    }
    if (ui->task3->isChecked()){
        parser3(ui->in->text());
    }
    ui->out->appendPlainText("");
}

void MainWindow::on_clear_clicked(){
    ui->out->clear();
}

void MainWindow::on_task1_toggled(bool checked){
    if (checked){
        on_clear_clicked();
        ui->out->appendPlainText("1. Какой журнал предоставляет информацию о современных технологиях тюнинга автомобилей?");
        ui->out->appendPlainText("2. Какие журналы предназначены для мужчин?");
        ui->out->appendPlainText("3. Какие журналы стоят 100 рублей?");
        ui->out->appendPlainText("4. На какие журналы можно оформить подписку?");
        ui->out->appendPlainText("");
    }
}

void MainWindow::on_task2_toggled(bool checked){
    if (checked){
        on_clear_clicked();
        ui->out->appendPlainText("1. Кто является начальником отдела маркетинга?");
        ui->out->appendPlainText("2. Какие задания выполняет ООО \"Созвездие\"?");
        ui->out->appendPlainText("3. Чем занимаетчя Иванов И.И.?");
        ui->out->appendPlainText("4. Какие сроки выполнения заданы для разработки Интернет-браузера?");
        ui->out->appendPlainText("");
    }
}

void MainWindow::on_task3_toggled(bool checked){
    if (checked){
        on_clear_clicked();
        ui->out->appendPlainText("Шаблоны вопросов (Названия объектов помещать в <>):");
        ui->out->appendPlainText("Кто является владельцем <Магазин>?");
        ui->out->appendPlainText("Какими магазинами владеет <Человек>?");
        ui->out->appendPlainText("Где находится магази <Магазин>?");
        ui->out->appendPlainText("На каком этаже находится <Магазин>?");
        ui->out->appendPlainText("Что продаётся в <Магазин>?");
        ui->out->appendPlainText("Какой режим работы магазина <Магазин>?");
        ui->out->appendPlainText("Где купить <Категория товаров>?");
        ui->out->appendPlainText("Какие способы оплаты доступны в <Магазин>?");
        ui->out->appendPlainText("В каких магизанах доступен <Способ оплаты> расчёт?");
        ui->out->appendPlainText("");
    }
}
