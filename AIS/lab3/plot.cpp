#include "plot.h"

Plot::Plot(QWidget *parent) :
    QChartView(parent){
    this->setRenderHint(QPainter::Antialiasing);
}

Plot::~Plot(){}

void Plot::setData(QVector<City> cities, QVector<Ant> ants){
    QLineSeries *series1 = new QLineSeries();
    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("Cities");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(10.0);

    for (int i = 0; i < cities.length(); i++){
        *series0 << QPointF(cities[i].x, cities[i].y);
    }
    for (int i = 0; i < ants.length(); i++){
        for (int j = 0; j < MAX_CITIES; j++){
            *series1 << QPointF(cities[ants[i].path[j]].x, cities[ants[i].path[j]].y);
        }
        *series1 << QPointF(cities[ants[i].path[0]].x, cities[ants[i].path[0]].y);
    }

    QChart *chart1 = new QChart();
    chart1->addSeries(series0);
    chart1->addSeries(series1);
    chart1->legend()->hide();

    QValueAxis *axisX = new QValueAxis();
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

    this->setChart(chart1);
}

void Plot::setData(QVector<City> cities, Ant &ant){
    QLineSeries *series1 = new QLineSeries();
    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("Cities");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(10.0);

    for (int i = 0; i < cities.length(); i++){
        *series0 << QPointF(cities[i].x, cities[i].y);
    }
    for (int j = 0; j < MAX_CITIES; j++)
        *series1 << QPointF(cities[ant.path[j]].x, cities[ant.path[j]].y);
    *series1 << QPointF(cities[ant.path[0]].x, cities[ant.path[0]].y);

    QChart *chart1 = new QChart();
    chart1->addSeries(series0);
    chart1->addSeries(series1);
    chart1->legend()->hide();

    QValueAxis *axisX = new QValueAxis();
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

    this->setChart(chart1);
}
