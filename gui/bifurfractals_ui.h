#ifndef BIFURFRACTALS_UI_H
#define BIFURFRACTALS_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>

#include "main_ui.h"

QT_BEGIN_NAMESPACE

class Ui_BifurFractalParams : public Ui_Main
{
public:
    QHBoxLayout *HLayoutXRange;
    QLabel *labelXmin;
    QDoubleSpinBox *doubleSpinBoxXmin;    
    QLabel *labelXmax;
    QDoubleSpinBox *doubleSpinBoxXmax;


    QHBoxLayout *HLayoutCRange;
    QLabel *labelCmin;
    QDoubleSpinBox *doubleSpinBoxCmin;
    QLabel *labelCmax;
    QDoubleSpinBox *doubleSpinBoxCmax;

    QHBoxLayout *HLayoutStartParams;
    QLabel *labelInitialPoint;
    QDoubleSpinBox *doubleSpinBoxInitialPoint;
    QLabel *labelIterDiscarded;
    QDoubleSpinBox *doubleSpinBoxIterDiscarded;

    QHBoxLayout *HLayoutStability;
    QLabel *labelMaxIter;
    QDoubleSpinBox *doubleSpinBoxMaxIter;
    QLabel *labelStability;
    QDoubleSpinBox *doubleSpinBoxStability;


    virtual void setupUi(QDialog *BifurFractalParams)
    {
        Ui_Main::setupUi(BifurFractalParams);

        /* X range */
        HLayoutXRange = new QHBoxLayout();
        HLayoutXRange->setObjectName("HLayoutXRange");

        /* Xmin */
        labelXmin = new QLabel(mainVerticalLayoutWidget);
        labelXmin->setObjectName("labelXmin");

        HLayoutXRange->addWidget(labelXmin);

        doubleSpinBoxXmin = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxXmin->setObjectName("doubleSpinBoxXmin");
        doubleSpinBoxXmin->setDecimals(6);
        doubleSpinBoxXmin->setMinimum(-2.0);
        doubleSpinBoxXmin->setMaximum(2.0);
        doubleSpinBoxXmin->setSingleStep(0.1);
        doubleSpinBoxXmin->setValue(-2.0);

        HLayoutXRange->addWidget(doubleSpinBoxXmin);

        /* Xmax */
        labelXmax = new QLabel(mainVerticalLayoutWidget);
        labelXmax->setObjectName("labelXmax");

        HLayoutXRange->addWidget(labelXmax);

        doubleSpinBoxXmax = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxXmax->setObjectName("doubleSpinBoxXmax");
        doubleSpinBoxXmax->setDecimals(2);
        doubleSpinBoxXmax->setMinimum(-2.0);
        doubleSpinBoxXmax->setMaximum(2.0);
        doubleSpinBoxXmax->setSingleStep(0.1);
        doubleSpinBoxXmax->setValue(2.0);

        HLayoutXRange->addWidget(doubleSpinBoxXmax);

        /*  First window line */
        mainVerticalLayout->addLayout(HLayoutXRange);



        /* C range */
        HLayoutCRange = new QHBoxLayout();
        HLayoutCRange->setObjectName("HLayoutCRange");

        /* Cmin */
        labelCmin = new QLabel(mainVerticalLayoutWidget);
        labelCmin->setObjectName("labelCmin");

        HLayoutCRange->addWidget(labelCmin);

        doubleSpinBoxCmin = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxCmin->setObjectName("doubleSpinBoxCmin");
        doubleSpinBoxCmin->setDecimals(2);
        doubleSpinBoxCmin->setMinimum(-2.0);
        doubleSpinBoxCmin->setMaximum(0.250);
        doubleSpinBoxCmin->setSingleStep(0.1);
        doubleSpinBoxCmin->setValue(-1.5);

        HLayoutCRange->addWidget(doubleSpinBoxCmin);

        /* Cmax */
        labelCmax = new QLabel(mainVerticalLayoutWidget);
        labelCmax->setObjectName("labelCmax");

        HLayoutCRange->addWidget(labelCmax);

        doubleSpinBoxCmax = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxCmax->setObjectName("doubleSpinBoxCmax");
        doubleSpinBoxCmax->setDecimals(2);
        doubleSpinBoxCmax->setMinimum(-2.0);
        doubleSpinBoxCmax->setMaximum(0.250);
        doubleSpinBoxCmax->setSingleStep(0.1);
        doubleSpinBoxCmax->setValue(-1.0);

        HLayoutCRange->addWidget(doubleSpinBoxCmax);

        /*  Second window line */
        mainVerticalLayout->addLayout(HLayoutCRange);

        /* Initial Point */
        HLayoutStartParams = new QHBoxLayout();
        HLayoutStartParams->setObjectName("HLayoutStartParams");
        labelIterDiscarded = new QLabel(mainVerticalLayoutWidget);
        labelIterDiscarded->setObjectName("labelIterDiscarded");

        HLayoutStartParams->addWidget(labelIterDiscarded);

        doubleSpinBoxInitialPoint = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxInitialPoint->setObjectName("doubleSpinBoxInitialPoint");
        doubleSpinBoxInitialPoint->setDecimals(2);
        doubleSpinBoxInitialPoint->setMinimum(-2.0);
        doubleSpinBoxInitialPoint->setMaximum(2.0);
        doubleSpinBoxInitialPoint->setSingleStep(0.1);
        doubleSpinBoxInitialPoint->setValue(0.0);

        HLayoutStartParams->addWidget(doubleSpinBoxInitialPoint);

        /* # of iterations excluded */
        labelInitialPoint = new QLabel(mainVerticalLayoutWidget);
        labelInitialPoint->setObjectName("labelInitialPoint");

        HLayoutStartParams->addWidget(labelInitialPoint);

        doubleSpinBoxIterDiscarded = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxIterDiscarded->setObjectName("doubleSpinBoxIterDiscarded");
        doubleSpinBoxIterDiscarded->setDecimals(0);
        doubleSpinBoxIterDiscarded->setMinimum(0);
        doubleSpinBoxIterDiscarded->setMaximum(10000);
        doubleSpinBoxIterDiscarded->setSingleStep(100);
        doubleSpinBoxIterDiscarded->setValue(4000);

        HLayoutStartParams->addWidget(doubleSpinBoxIterDiscarded);

        /*  Third window line */
        mainVerticalLayout->addLayout(HLayoutStartParams);

        /* Max Iteration */
        HLayoutStability = new QHBoxLayout();
        HLayoutStability->setObjectName("HLayoutStability");
        labelMaxIter = new QLabel(mainVerticalLayoutWidget);
        labelMaxIter->setObjectName("labelMaxIter");

        HLayoutStability->addWidget(labelMaxIter);

        doubleSpinBoxMaxIter = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxMaxIter->setObjectName("doubleSpinBoxMaxIter");
        doubleSpinBoxMaxIter->setDecimals(0);
        doubleSpinBoxMaxIter->setMinimum(1000);
        doubleSpinBoxMaxIter->setMaximum(30000);
        doubleSpinBoxMaxIter->setSingleStep(100);
        doubleSpinBoxMaxIter->setValue(10000);

        HLayoutStability->addWidget(doubleSpinBoxMaxIter);

        /* # of iterations excluded */
        labelStability = new QLabel(mainVerticalLayoutWidget);
        labelStability->setObjectName("labelStability");

        HLayoutStability->addWidget(labelStability);

        doubleSpinBoxStability = new QDoubleSpinBox(mainVerticalLayoutWidget);
        doubleSpinBoxStability->setObjectName("doubleSpinBoxStability");
        doubleSpinBoxStability->setDecimals(2);
        doubleSpinBoxStability->setMinimum(0);
        doubleSpinBoxStability->setMaximum(1);
        doubleSpinBoxStability->setSingleStep(1);
        doubleSpinBoxStability->setValue(0.6);

        HLayoutStability->addWidget(doubleSpinBoxStability);

        /*  Fourth window line */
        mainVerticalLayout->addLayout(HLayoutStability);

        retranslateUi(BifurFractalParams);

        QMetaObject::connectSlotsByName(BifurFractalParams);
    } // setupUi

    virtual void retranslateUi(QDialog *BifurFractalParams)
    {
        Ui_Main::retranslateUi(BifurFractalParams);
        BifurFractalParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", "Bifurcation Params", nullptr));
        labelXmin->setText(QCoreApplication::translate("BifurFractalParams", "X min", nullptr));
        labelXmax->setText(QCoreApplication::translate("BifurFractalParams", "X max", nullptr));
        labelCmin->setText(QCoreApplication::translate("BifurFractalParams", "C min", nullptr));
        labelCmax->setText(QCoreApplication::translate("BifurFractalParams", "C max", nullptr));
        labelInitialPoint->setText(QCoreApplication::translate("BifurFractalParams", "To be discarded", nullptr));
        labelIterDiscarded->setText(QCoreApplication::translate("BifurFractalParams", "Initial Point", nullptr));
        labelMaxIter->setText(QCoreApplication::translate("BifurFractalParams", "Iterations", nullptr));
        labelStability->setText(QCoreApplication::translate("BifurFractalParams", "Perc.Stable Orbits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BifurFractalParams: public Ui_BifurFractalParams{};
} // namespace Ui

QT_END_NAMESPACE

#endif // BIFURFRACTALS_UI_H
