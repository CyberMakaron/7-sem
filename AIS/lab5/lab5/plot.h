#ifndef DIALOGPLOTS_H
#define DIALOGPLOTS_H

#include <QDialog>
#include <QVector>
#include <QtCharts>
#include <QChartView>
#include "includes.h"
#include "city.h"

class Plot : public QChartView
{
    Q_OBJECT

public:
    explicit Plot(QWidget *parent = nullptr);
    ~Plot();
    void setData(QVector<City> cities, PopulationType* populations);
    void setData(QVector<City> cities, PopulationType population);
};

    ///ui->layout_plots->addWidget(chartView);
    ///
#endif // DIALOGPLOTS_H
