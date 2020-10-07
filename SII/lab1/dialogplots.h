#ifndef DIALOGPLOTS_H
#define DIALOGPLOTS_H

#include <QDialog>
#include <QVector>
#include <QtCharts>
#include <QChartView>

namespace Ui {
    class DialogPlots;
}

class DialogPlots : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPlots(QWidget *parent = nullptr);
    ~DialogPlots();
    void setData(QVector<float> temp, QVector<uint> bad_count, QVector<uint> best_energy);

private:
    Ui::DialogPlots *ui;
};

#endif // DIALOGPLOTS_H
