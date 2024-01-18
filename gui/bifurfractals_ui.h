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
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_5;

    virtual void setupUi(QDialog *BifurFractalParams)
    {
        Ui_Main::setupUi(BifurFractalParams);

        /* Cmin */

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setDecimals(2);
        doubleSpinBox->setMinimum(-2.0);
        doubleSpinBox->setMaximum(0.250);
        doubleSpinBox->setSingleStep(0.1);
        doubleSpinBox->setValue(-1.5);

        horizontalLayout_2->addWidget(doubleSpinBox);

        /* Cmax */

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        doubleSpinBox_2 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setDecimals(2);
        doubleSpinBox_2->setMinimum(-2.0);
        doubleSpinBox_2->setMaximum(0.250);
        doubleSpinBox_2->setSingleStep(0.1);
        doubleSpinBox_2->setValue(-1.0);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        verticalLayout->addLayout(horizontalLayout_2);

        /* Initial Point */
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_4->addWidget(label_8);

        doubleSpinBox_5 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_5->setObjectName("doubleSpinBox_5");
        doubleSpinBox_5->setDecimals(2);
        doubleSpinBox_5->setMinimum(-2.0);
        doubleSpinBox_5->setMaximum(2.0);
        doubleSpinBox_5->setSingleStep(0.1);
        doubleSpinBox_5->setValue(0.0);

        horizontalLayout_4->addWidget(doubleSpinBox_5);

        /* # of iterations excluded */
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        doubleSpinBox_6 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_6->setObjectName("doubleSpinBox_6");
        doubleSpinBox_6->setDecimals(0);
        doubleSpinBox_6->setMinimum(0);
        doubleSpinBox_6->setMaximum(10000);
        doubleSpinBox_6->setSingleStep(100);
        doubleSpinBox_6->setValue(4000);

        horizontalLayout_4->addWidget(doubleSpinBox_6);

        verticalLayout->addLayout(horizontalLayout_4);

        /*************

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        doubleSpinBox_3 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setDecimals(19);
        doubleSpinBox_3->setMinimum(-1000.000000000000000);
        doubleSpinBox_3->setMaximum(1000.000000000000000);
        doubleSpinBox_3->setSingleStep(0.100000000000000);
        doubleSpinBox_3->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_3);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        doubleSpinBox_4 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setDecimals(19);
        doubleSpinBox_4->setMinimum(-1000.000000000000000);
        doubleSpinBox_4->setMaximum(1000.000000000000000);
        doubleSpinBox_4->setSingleStep(0.100000000000000);
        doubleSpinBox_4->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_4);


        verticalLayout->addLayout(horizontalLayout_3);


        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_4->addWidget(label_8);

        doubleSpinBox_6 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_6->setObjectName("doubleSpinBox_6");
        doubleSpinBox_6->setDecimals(6);
        doubleSpinBox_6->setMinimum(-100.000000000000000);
        doubleSpinBox_6->setMaximum(100.000000000000000);
        doubleSpinBox_6->setSingleStep(0.100000000000000);
        doubleSpinBox_6->setValue(0.40000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_5->addWidget(label_9);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMaxLength(29);

        horizontalLayout_5->addWidget(lineEdit);

        verticalLayout->addLayout(horizontalLayout_5);
*****************/
        retranslateUi(BifurFractalParams);

        QMetaObject::connectSlotsByName(BifurFractalParams);
    } // setupUi

    virtual void retranslateUi(QDialog *BifurFractalParams)
    {
        Ui_Main::retranslateUi(BifurFractalParams);
        BifurFractalParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", "Bifurcation Params", nullptr));
        label_3->setText(QCoreApplication::translate("BifurFractalParams", "C min", nullptr));
        label_5->setText(QCoreApplication::translate("BifurFractalParams", "C max", nullptr));
        label_7->setText(QCoreApplication::translate("BifurFractalParams", "# of iterations to be discarded", nullptr));
        label_8->setText(QCoreApplication::translate("BifurFractalParams", "Initial Point", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BifurFractalParams: public Ui_BifurFractalParams{};
} // namespace Ui

QT_END_NAMESPACE

#endif // BIFURFRACTALS_UI_H
