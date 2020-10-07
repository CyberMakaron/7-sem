#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->board_layout->setHorizontalSpacing(0);
    ui->board_layout->setVerticalSpacing(0);
    best_sol = nullptr;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::tweakSolution(Member &mem){
    int x, y;
    x = rand()% N;
    while(y = rand() % N == x);
    int tmp = mem.sol[x];
    mem.sol[x] = mem.sol[y];
    mem.sol[y] = tmp;
}

void MainWindow::initializeSolution(Member &mem){
    if (best_sol == nullptr){
        for (int i = 0; i < N; i++)
            mem.sol[i] = i;
        for (int i = 0; i < N; i++)
            tweakSolution(mem);
    }
    else
        copySolution(mem, *best_sol);
}

void MainWindow::computeEnergy(Member &mem){
    int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, 1, 1, -1};
    int x, y, tmpx, tmpy;
    int conflicts = 0;
    for (int i = 0; i < N; i++){
        mem.conflicting[i] = false;
        x = i; y = mem.sol[i];
        for (int j = 0; j < 4; j++){
            tmpx = x; tmpy = y;
            while(true){
                tmpx += dx[j];
                tmpy += dy[j];
                if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= N)
                    break;
                if (mem.sol[tmpx] == tmpy){
                    conflicts++;
                    mem.conflicting[i] = true;
                }
            }
        }
    }
    mem.energy = conflicts;
    }

void MainWindow::copySolution(Member &dest, Member &src){
    dest.sol = src.sol;
    dest.energy = src.energy;
    dest.conflicting = src.conflicting;
}

void MainWindow::mainAlgorithm(){
    ///пока не будет 0 конфликтов
    temp.clear();
    bad_count.clear();
    best_energy.clear();
    int T = Tmax;
    bool sol = false;
    srand(QTime::currentTime().msec());
    Member current(N), working(N), best(N);
    best.energy = INT32_MAX;
    initializeSolution(current);
    computeEnergy(current);
    copySolution(working, current);
    while (T > Tmin){
        temp << T;
        bad_count << 0;
        int accepted = 0;
        for (int step = 0; step < steps; step++){
            bool useNew = false;
            tweakSolution(working);
            computeEnergy(working);
            if (working.energy < current.energy)
                useNew = true;
            else{
                float test = (rand()%1000) / 1000.0;
                float calc = exp(-(working.energy - current.energy) / T);
                if (calc < test){
                    accepted++;
                    useNew = true;
                }
            }
            if (useNew){
                useNew = false;
                copySolution(current, working);
                if (current.energy < best.energy){
                    copySolution(best, current);
                    sol = true;
                }
            }
            else{
                bad_count.last()++;
                copySolution(working, current);
            }
        }
        best_energy << best.energy;
        T *= alpha;
    }
    if (!sol)
        QMessageBox::information(nullptr, "Нежданчик", "Решение не найдено!");
    else{
        if (best_sol != nullptr) delete best_sol;
        best_sol = new Member(N);
        copySolution(*best_sol, best);
        printResult(best);
    }
}

void MainWindow::printResult(Member &mem){
    ui->line_conflicts->setText(QString::number(mem.energy));
    QLabel *label;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            label = new QLabel();
            label->setMinimumSize(20, 20);
            label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            if (mem.sol[i] == j)
                if (mem.conflicting[i])
                    label->setStyleSheet("border: 1px solid black; background: red");
                else
                    label->setStyleSheet("border: 1px solid black; background: black");

            else
                label->setStyleSheet("border: 1px solid black; background: white");
            ui->board_layout->addWidget(label, i, j);
        }
}


void MainWindow::on_button_start_clicked(){
    if (!ready) return;
    ready = false;
    Tmax = ui->spin_tmax->value();
    Tmin = ui->spin_tmin->value();
    if (N != ui->spin_n->value()){
        if (best_sol != nullptr)
            delete  best_sol;
        best_sol = nullptr;
    }
    N = ui->spin_n->value();
    steps = ui->spin_steps->value();
    alpha = ui->spin_alpha->value();
    mainAlgorithm();
    ready = true;
}


void MainWindow::on_button_showplots_clicked(){
    if (temp.size() < 1) return;
    DialogPlots plots;
    plots.setData(temp, bad_count, best_energy);
    plots.exec();
}
