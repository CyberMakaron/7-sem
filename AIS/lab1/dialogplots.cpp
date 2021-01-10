#include "dialogplots.h"
#include "ui_dialogplots.h"

DialogPlots::DialogPlots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPlots)
{
    ui->setupUi(this);
}

DialogPlots::~DialogPlots()
{
    delete ui;
}

void DialogPlots::setData(QVector<float> temp, QVector<uint> bad_count, QVector<uint> best_energy){
    QChartView *chartView = new QChartView(this),
               *chartView2 = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView2->setRenderHint(QPainter::Antialiasing);

    ui->layout_plots->addWidget(chartView);
    ui->layout_plots->addWidget(chartView2);
    QLineSeries *series1 = new QLineSeries(),
                *series2 = new QLineSeries();

    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("Cities");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(10.0);

    for (int i = 0; i < temp.length(); i++){
        *series0 << QPointF(temp[i], bad_count[i]);
        *series1 << QPointF(temp[i], bad_count[i]);
        *series2 << QPointF(temp[i], best_energy[i]);
    }

    QChart *chart1 = new QChart();
    chart1->addSeries(series0);
    chart1->addSeries(series1);
    chart1->legend()->hide();
    chart1->setTitle("Количество принятых плохих решений");

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Температура");
    axisX->setLabelFormat("%i");
    axisX->setTickCount(5);
    chart1->addAxis(axisX, Qt::AlignBottom);
    series0->attachAxis(axisX);
    series1->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");
    axisY->setTickCount(10);
    chart1->addAxis(axisY, Qt::AlignLeft);
    series0->attachAxis(axisY);
    series1->attachAxis(axisY);


    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->legend()->hide();
    chart2->setTitle("Энергия лучшего решения");

    QValueAxis *axisX2 = new QValueAxis();
    axisX2->setTitleText("Температура");
    axisX2->setLabelFormat("%i");
    axisX2->setTickCount(5);
    chart2->addAxis(axisX2, Qt::AlignBottom);
    series2->attachAxis(axisX2);

    QValueAxis *axisY2 = new QValueAxis();
    axisY2->setLabelFormat("%i");
    axisY2->setTickCount(10);
    chart2->addAxis(axisY2, Qt::AlignLeft);
    series2->attachAxis(axisY2);

    chartView->setChart(chart1);
    chartView2->setChart(chart2);
}
