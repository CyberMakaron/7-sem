#include "plot.h"

Plot::Plot(QWidget *parent) :
    QChartView(parent){
    this->setRenderHint(QPainter::Antialiasing);
}

Plot::~Plot(){}

void Plot::setData(QVector<City> cities, PopulationType* populations){
    QLineSeries *series1 = new QLineSeries();
    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("Cities");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(11.0);
    series0->setColor(Qt::black);

    for (int i = 0; i < cities.length(); i++){
        *series0 << QPointF(cities[i].x, cities[i].y);
    }
    for (int i = 0; i < MAX_CHROMS; i++){
        for (int j = 0; j < MAX_CITIES; j++){
            *series1 << QPointF(cities[populations[i].cities[j]].x, cities[populations[i].cities[j]].y);
        }
        *series1 << QPointF(cities[populations[i].cities[0]].x, cities[populations[i].cities[0]].y);
    }
    series1->setColor(Qt::red);

    QChart *chart1 = new QChart();
    chart1->addSeries(series0);
    chart1->addSeries(series1);
    chart1->legend()->hide();


    QValueAxis *axisX = new QValueAxis();
    axisX->setLabelFormat("%i");
    axisX->setTickCount(20);
    axisX->hide();
    chart1->addAxis(axisX, Qt::AlignBottom);
    series0->attachAxis(axisX);
    series1->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");
    axisY->setTickCount(20);
    axisY->hide();
    chart1->addAxis(axisY, Qt::AlignLeft);
    series0->attachAxis(axisY);
    series1->attachAxis(axisY);

    // для изменения размера графика
    axisX->setRange(-1, MAX_CITIES+1);
    axisY->setRange(-1, MAX_CITIES+1);

    this->setChart(chart1);
}

void Plot::setData(QVector<City> cities, PopulationType population){
    QLineSeries *series1 = new QLineSeries();
    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("Cities");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(11.0);
    series0->setColor(Qt::black);

    for (int i = 0; i < cities.length(); i++){
        *series0 << QPointF(cities[i].x, cities[i].y);
    }
    for (int j = 0; j < MAX_CITIES; j++)
        *series1 << QPointF(cities[population.cities[j]].x, cities[population.cities[j]].y);
    *series1 << QPointF(cities[population.cities[0]].x, cities[population.cities[0]].y);
    series1->setColor(Qt::darkGreen);

    QChart *chart1 = new QChart();
    chart1->addSeries(series0);
    chart1->addSeries(series1);
    chart1->legend()->hide();

    QValueAxis *axisX = new QValueAxis();

    axisX->setLabelFormat("%i");
    axisX->setTickCount(20);
    axisX->hide();
    chart1->addAxis(axisX, Qt::AlignBottom);
    series0->attachAxis(axisX);
    series1->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");
    axisY->setTickCount(20);
    axisY->hide();
    chart1->addAxis(axisY, Qt::AlignLeft);
    series0->attachAxis(axisY);
    series1->attachAxis(axisY);

    // для изменения размера графика
    axisX->setRange(-1, MAX_CITIES+1);
    axisY->setRange(-1, MAX_CITIES+1);

    this->setChart(chart1);
}
