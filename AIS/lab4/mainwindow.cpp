#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , buttons_grid(PIXELS_Y, PIXELS_X, 25)
{
    ui->setupUi(this);
    srand(time(NULL));
    init();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init(){
    isLearn = false;
    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);
    QPushButton *but;
    for (int i = 0; i < PIXELS_Y; i++)
        for (int j = 0; j < PIXELS_X; j++) {
            but = buttons_grid.getPixel(i, j);
            ui->gridLayout->addWidget(but, i, j);
            connect(but, SIGNAL(clicked()), this, SLOT(button_grid_clicked()));
        }
    for (int i = 0; i < OUTPUT_NEURONS; i++)
        ui->listWidget->addItem(words[i]);
}

void MainWindow::assignRandomWeights(){
    int hid, inp, out;
    for (inp = 0; inp < INPUT_NEURONS+1; inp++) {
        for (hid = 0; hid < HIDDEN_NEURONS; hid++) {
            wih[inp][hid] = RAND_WEIGHT;
        }
    }
    for (hid = 0 ; hid < HIDDEN_NEURONS+1 ; hid++) {
        for (out = 0 ; out < OUTPUT_NEURONS ; out++) {
            who[hid][out] = RAND_WEIGHT;
        }
    }
}

double MainWindow::sigmoid(double val){
    return (1.0 / (1.0 + exp(-val)));
}

double MainWindow::sigmoidDerivative(double val){
    return (val * (1.0 - val));
}

//проход вперёд
void MainWindow::feedForward(){
    int inp, hid, out;
    double sum;
    /* Вычислить вход в скрытый слой */
    for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
        sum = 0.0;
        for (inp = 0; inp < INPUT_NEURONS; inp++) {
            sum += inputs[inp] * wih[inp][hid];
        }
        /* Добавить смещение */
        sum += wih[INPUT_NEURONS][hid];
        hidden[hid] = sigmoid(sum);
    }
    /* Вычислить вход в выходной слой */
    for (out = 0; out < OUTPUT_NEURONS; out++) {
        sum = 0.0;
        for (hid = 0; hid < HIDDEN_NEURONS; hid++) {
            sum += hidden[hid] * who[hid][out];
        }
        /* Добавить смещение */
        sum += who[HIDDEN_NEURONS][out];
        actual[out] = sigmoid(sum);
    }
}

//обратное распространение
void MainWindow::backPropagate(){
    int inp, hid, out;
    /* Вычислить ошибку выходного слоя (шаг 3 для выходных ячеек) */
    for (out = 0; out < OUTPUT_NEURONS; out++) {
        erro[out] = (target[out] - actual[out]) * sigmoidDerivative(actual[out]);
    }
    /* Вычислить ошибку скрытого слоя (шаг 3 для скрытого слоя) */
    for (hid = 0; hid < HIDDEN_NEURONS; hid++) {
        errh[hid] = 0.0;
        for (out = 0; out < OUTPUT_NEURONS; out++) {
            errh[hid] += erro[out] * who[hid][out];
        }
        errh[hid] *= sigmoidDerivative(hidden[hid]);
    }
    /* Обновить веса для выходного слоя (шаг 4 для выходных ячеек) */
    for (out = 0; out < OUTPUT_NEURONS; out++) {
        for (hid = 0; hid < HIDDEN_NEURONS; hid++) {
            who[hid][out] += (learn_rate * erro[out] * hidden[hid]);
        }
        /* Обновить смещение */
        who[HIDDEN_NEURONS][out] += (learn_rate * erro[out]);
    }
    /* Обновить веса для скрытого слоя (шаг 4 для скрытого слоя) */
    for (hid = 0; hid < HIDDEN_NEURONS; hid++) {
        for (inp = 0; inp < INPUT_NEURONS; inp++) {
            wih[inp][hid] += (learn_rate * errh[hid] * inputs[inp]);
        }
        /* Обновить смещение */
        wih[INPUT_NEURONS][hid] += (learn_rate * errh[hid]);
    }
}

//«победитель получает все»
int MainWindow::action(double *vector){
    int index, sel;
    double max;
    sel = 0;
    max = vector[sel];
    for (index = 1; index < OUTPUT_NEURONS; index++) {
        if (vector[index] > max) {
            max = vector[index]; sel = index;
        }
    }
    return sel;
}


void MainWindow::on_button_start_clicked(){
    assignRandomWeights();
    int sample = -1;
    learn_rate = ui->rho->value();
    era = 0;
    while (era++ < ui->era_number->value()){
        if (++sample == LEARN_EX_NUM * OUTPUT_NEURONS) sample = 0;
        for (int i = 0; i < INPUT_NEURONS; i++){
            inputs[i] = learning_examples[sample][i];
        }
        for (int i = 0; i < OUTPUT_NEURONS; i++)
            target[i] = targets[sample][i];
        feedForward();
        backPropagate();
    }
    ui->statusBar->showMessage("Обучение завершено!");
    isLearn = true;
}

void MainWindow::button_grid_clicked(/*QPushButton *but*/){
    qDebug() << "Clicked";
    buttons_grid.inversePixel(QObject::sender()->objectName().toInt());
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow){
    buttons_grid.setImage(main_examples[currentRow]);
}

void MainWindow::on_button_clear_clicked(){
    buttons_grid.clear();
}

void MainWindow::on_button_identify_clicked(){
    if (!isLearn){
        ui->statusBar->showMessage("Сначала нужно обучить нейросеть!");
        return;
    }
    ui->listWidget_res->clear();
    buttons_grid.getImage(inputs);
    feedForward();
    for (int i = 0; i < OUTPUT_NEURONS; i++) {
        ui->listWidget_res->addItem(words[i] + " " + QString::number(actual[i]));
    }
    int sel = action(actual);
    ui->statusBar->showMessage("Скорее всего это буква... Знаю, " + words[sel] + "!");
    ui->listWidget_res->item(sel)->setBackground(QBrush(QColor(144, 238, 144)));
}
