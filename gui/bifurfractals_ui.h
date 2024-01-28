#ifndef BIFURFRACTALS_UI_H
#define BIFURFRACTALS_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
//#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
//#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>

#include "main_ui.h"

QT_BEGIN_NAMESPACE

class Ui_BifurFractalParams : public Ui_Main
{
public:
    QLabel *labelXmin;
    QDoubleSpinBox *doubleSpinBoxXmin;    
    QLabel *labelXmax;
    QDoubleSpinBox *doubleSpinBoxXmax;

    QLabel *labelCmin;
    QDoubleSpinBox *doubleSpinBoxCmin;
    QLabel *labelCmax;
    QDoubleSpinBox *doubleSpinBoxCmax;

    QLabel *labelInitialPoint;
    QDoubleSpinBox *doubleSpinBoxInitialPoint;
    QLabel *labelIterDiscarded;
    QDoubleSpinBox *doubleSpinBoxIterDiscarded;

    QLabel *labelMaxIter;
    QDoubleSpinBox *doubleSpinBoxMaxIter;
    QLabel *labelStability;
    QDoubleSpinBox *doubleSpinBoxStability;


    virtual void setupUi(QDialog *BifurFractalParams)
    {
        Ui_Main::setupUi(BifurFractalParams);

        /* X range */

        /* Xmin */
        labelXmin = new QLabel();
        labelXmin->setObjectName("labelXmin");

        doubleSpinBoxXmin = new QDoubleSpinBox();
        doubleSpinBoxXmin->setObjectName("doubleSpinBoxXmin");
        doubleSpinBoxXmin->setDecimals(6);
        doubleSpinBoxXmin->setMinimum(-2.0);
        doubleSpinBoxXmin->setMaximum(2.0);
        doubleSpinBoxXmin->setSingleStep(0.1);
        doubleSpinBoxXmin->setValue(-2.0);

        /* Xmax */
        labelXmax = new QLabel();
        labelXmax->setObjectName("labelXmax");

        doubleSpinBoxXmax = new QDoubleSpinBox();
        doubleSpinBoxXmax->setObjectName("doubleSpinBoxXmax");
        doubleSpinBoxXmax->setDecimals(6);
        doubleSpinBoxXmax->setMinimum(-2.0);
        doubleSpinBoxXmax->setMaximum(2.0);
        doubleSpinBoxXmax->setSingleStep(0.1);
        doubleSpinBoxXmax->setValue(2.0);

        /*  First window line */

        gridLayout->addWidget(labelXmin, 1, 0);
        gridLayout->addWidget(doubleSpinBoxXmin, 1, 1); 
        gridLayout->addWidget(labelXmax, 1, 2);
        gridLayout->addWidget(doubleSpinBoxXmax, 1, 3);

        /* C range */

        /* Cmin */
        labelCmin = new QLabel();
        labelCmin->setObjectName("labelCmin");

        doubleSpinBoxCmin = new QDoubleSpinBox();
        doubleSpinBoxCmin->setObjectName("doubleSpinBoxCmin");
        doubleSpinBoxCmin->setDecimals(5);
        doubleSpinBoxCmin->setMinimum(-2.0);
        doubleSpinBoxCmin->setMaximum(0.250);
        doubleSpinBoxCmin->setSingleStep(0.1);
        doubleSpinBoxCmin->setValue(-1.5);

        /* Cmax */
        labelCmax = new QLabel();
        labelCmax->setObjectName("labelCmax");

        doubleSpinBoxCmax = new QDoubleSpinBox();
        doubleSpinBoxCmax->setObjectName("doubleSpinBoxCmax");
        doubleSpinBoxCmax->setDecimals(5);
        doubleSpinBoxCmax->setMinimum(-2.0);
        doubleSpinBoxCmax->setMaximum(0.250);
        doubleSpinBoxCmax->setSingleStep(0.1);
        doubleSpinBoxCmax->setValue(-1.0);

        /*  Second window line */
        gridLayout->addWidget(labelCmin, 2, 0);
        gridLayout->addWidget(doubleSpinBoxCmin, 2, 1); 
        gridLayout->addWidget(labelCmax, 2, 2);
        gridLayout->addWidget(doubleSpinBoxCmax, 2, 3);

        /* Initial Point */
        labelIterDiscarded = new QLabel();
        labelIterDiscarded->setObjectName("labelIterDiscarded");

        doubleSpinBoxInitialPoint = new QDoubleSpinBox();
        doubleSpinBoxInitialPoint->setObjectName("doubleSpinBoxInitialPoint");
        doubleSpinBoxInitialPoint->setDecimals(2);
        doubleSpinBoxInitialPoint->setMinimum(-2.0);
        doubleSpinBoxInitialPoint->setMaximum(2.0);
        doubleSpinBoxInitialPoint->setSingleStep(0.1);
        doubleSpinBoxInitialPoint->setValue(0.0);

        /* # of iterations excluded */
        labelInitialPoint = new QLabel();
        labelInitialPoint->setObjectName("labelInitialPoint");

        doubleSpinBoxIterDiscarded = new QDoubleSpinBox();
        doubleSpinBoxIterDiscarded->setObjectName("doubleSpinBoxIterDiscarded");
        doubleSpinBoxIterDiscarded->setDecimals(0);
        doubleSpinBoxIterDiscarded->setMinimum(0);
        doubleSpinBoxIterDiscarded->setMaximum(100000);
        doubleSpinBoxIterDiscarded->setSingleStep(100);
        doubleSpinBoxIterDiscarded->setValue(4000);

        /*  Third window line */
        gridLayout->addWidget(labelIterDiscarded, 3, 0);
        gridLayout->addWidget(doubleSpinBoxInitialPoint, 3, 1); 
        gridLayout->addWidget(labelInitialPoint, 3, 2);
        gridLayout->addWidget(doubleSpinBoxIterDiscarded, 3, 3);

        /* Max Iteration */
        labelMaxIter = new QLabel();
        labelMaxIter->setObjectName("labelMaxIter");

        doubleSpinBoxMaxIter = new QDoubleSpinBox();
        doubleSpinBoxMaxIter->setObjectName("doubleSpinBoxMaxIter");
        doubleSpinBoxMaxIter->setDecimals(0);
        doubleSpinBoxMaxIter->setMinimum(1000);
        doubleSpinBoxMaxIter->setMaximum(100000);
        doubleSpinBoxMaxIter->setSingleStep(100);
        doubleSpinBoxMaxIter->setValue(10000);

        /* # of iterations excluded */
        labelStability = new QLabel();
        labelStability->setObjectName("labelStability");

        doubleSpinBoxStability = new QDoubleSpinBox();
        doubleSpinBoxStability->setObjectName("doubleSpinBoxStability");
        doubleSpinBoxStability->setDecimals(2);
        doubleSpinBoxStability->setMinimum(0);
        doubleSpinBoxStability->setMaximum(1);
        doubleSpinBoxStability->setSingleStep(1);
        doubleSpinBoxStability->setValue(0.6);

        /*  Fourth window line */
        gridLayout->addWidget(labelMaxIter, 4, 0);
        gridLayout->addWidget(doubleSpinBoxMaxIter, 4, 1); 
        gridLayout->addWidget(labelStability, 4, 2);
        gridLayout->addWidget(doubleSpinBoxStability, 4, 3);

        /* Exit box */
        buttonExitBox->setObjectName("buttonBox");
        buttonExitBox->setGeometry(QRect(30, 240, 341, 32));
        buttonExitBox->setOrientation(Qt::Horizontal);
        buttonExitBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonExitBox, 5, 0, 1, 4);

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
