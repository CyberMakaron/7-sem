/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *crossingProb;
    QDoubleSpinBox *mutationProb;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonStart;
    QLabel *label_3;
    QDoubleSpinBox *crossingValue;
    QCheckBox *refreshCities;
    QCheckBox *onlyBest;
    QPushButton *buttonStartShow;
    QFrame *line;
    Plot *widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(877, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        crossingProb = new QDoubleSpinBox(centralwidget);
        crossingProb->setObjectName(QString::fromUtf8("crossingProb"));
        crossingProb->setDecimals(2);
        crossingProb->setMinimum(0.500000000000000);
        crossingProb->setMaximum(1.000000000000000);
        crossingProb->setSingleStep(0.050000000000000);
        crossingProb->setValue(0.900000000000000);

        gridLayout_2->addWidget(crossingProb, 1, 3, 1, 1);

        mutationProb = new QDoubleSpinBox(centralwidget);
        mutationProb->setObjectName(QString::fromUtf8("mutationProb"));
        mutationProb->setMaximum(0.500000000000000);
        mutationProb->setSingleStep(0.050000000000000);

        gridLayout_2->addWidget(mutationProb, 2, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 6, 1, 1);

        buttonStart = new QPushButton(centralwidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonStart->sizePolicy().hasHeightForWidth());
        buttonStart->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(buttonStart, 2, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 2, 1, 1);

        crossingValue = new QDoubleSpinBox(centralwidget);
        crossingValue->setObjectName(QString::fromUtf8("crossingValue"));
        crossingValue->setMinimum(0.000000000000000);
        crossingValue->setMaximum(1.000000000000000);
        crossingValue->setSingleStep(0.050000000000000);
        crossingValue->setValue(0.500000000000000);

        gridLayout_2->addWidget(crossingValue, 0, 3, 1, 1);

        refreshCities = new QCheckBox(centralwidget);
        refreshCities->setObjectName(QString::fromUtf8("refreshCities"));

        gridLayout_2->addWidget(refreshCities, 0, 0, 1, 1);

        onlyBest = new QCheckBox(centralwidget);
        onlyBest->setObjectName(QString::fromUtf8("onlyBest"));

        gridLayout_2->addWidget(onlyBest, 0, 1, 1, 1);

        buttonStartShow = new QPushButton(centralwidget);
        buttonStartShow->setObjectName(QString::fromUtf8("buttonStartShow"));
        sizePolicy.setHeightForWidth(buttonStartShow->sizePolicy().hasHeightForWidth());
        buttonStartShow->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(buttonStartShow, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget = new Plot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \342\204\2265 \320\232\320\273\320\265\321\201\320\276\320\262 \320\222\320\242-41", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\214 \321\201\320\272\321\200\320\265\321\211\320\270\320\262\320\260\320\275\320\270\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214 \321\201\320\272\321\200\320\265\321\211\320\270\320\262\320\260\320\275\320\270\321\217:", nullptr));
        buttonStart->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214 \320\274\321\203\321\202\320\260\321\206\320\270\320\270:", nullptr));
        refreshCities->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\217\321\202\321\214 \320\263\320\276\321\200\320\276\320\264\320\260", nullptr));
        onlyBest->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\214\320\272\320\276 \320\273\321\203\321\207\321\210\320\260\321\217 \320\276\321\201\320\276\320\261\321\214", nullptr));
        buttonStartShow->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\321\214 \321\201 \320\277\320\276\320\272\320\260\320\267\320\276\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
