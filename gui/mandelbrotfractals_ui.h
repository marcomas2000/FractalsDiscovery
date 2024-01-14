#ifndef MANDELBROTFRACTALS_UI_H
#define MANDELBROTFRACTALS_UI_H

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

#include "main_ui.h"

QT_BEGIN_NAMESPACE

class Ui_MandelbrotFractalParams : public Ui_Main
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
    QLabel *label_9;
    QSpinBox *spinBox_3;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_7;

    virtual void setupUi(QDialog *MandelbrotFractalParams)
    {
        Ui_Main::setupUi(MandelbrotFractalParams);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setDecimals(19);
        doubleSpinBox->setMinimum(-1000.000000000000000);
        doubleSpinBox->setMaximum(1000.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(-2.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        doubleSpinBox_2 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setDecimals(19);
        doubleSpinBox_2->setMinimum(-1000.000000000000000);
        doubleSpinBox_2->setMaximum(1000.000000000000000);
        doubleSpinBox_2->setSingleStep(0.100000000000000);
        doubleSpinBox_2->setValue(-2.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_2);


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
        doubleSpinBox_3->setValue(2.000000000000000);

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
        doubleSpinBox_4->setValue(2.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_4);

        verticalLayout->addLayout(horizontalLayout_3);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_5->addWidget(label_9);

        spinBox_3 = new QSpinBox(verticalLayoutWidget);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(30000);
        spinBox_3->setSingleStep(1);
        spinBox_3->setValue(30);

        horizontalLayout_5->addWidget(spinBox_3);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName("label_10");

        horizontalLayout_5->addWidget(label_10);

        doubleSpinBox_7 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_7->setObjectName("doubleSpinBox_7");
        doubleSpinBox_7->setMaximum(100000.000000000000000);
        doubleSpinBox_7->setValue(3.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_7);

        verticalLayout->addLayout(horizontalLayout_5);

        retranslateUi(MandelbrotFractalParams);

        QMetaObject::connectSlotsByName(MandelbrotFractalParams);
    } // setupUi

    virtual void retranslateUi(QDialog *MandelbrotFractalParams)
    {
        Ui_Main::retranslateUi(MandelbrotFractalParams);
        MandelbrotFractalParams->setWindowTitle(QCoreApplication::translate("MandelbrotFractalParams", "Julia Squared Params", nullptr));
        label_3->setText(QCoreApplication::translate("MandelbrotFractalParams", "F(x) xmin", nullptr));
        label_4->setText(QCoreApplication::translate("MandelbrotFractalParams", "F(x) ymin", nullptr));
        label_5->setText(QCoreApplication::translate("MandelbrotFractalParams", "F(x) xmax", nullptr));
        label_6->setText(QCoreApplication::translate("MandelbrotFractalParams", "F(x) ymax", nullptr));
        label_9->setText(QCoreApplication::translate("MandelbrotFractalParams", "MaxIter", nullptr));
        label_10->setText(QCoreApplication::translate("MandelbrotFractalParams", "Divergency", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MandelbrotFractalParams: public Ui_MandelbrotFractalParams{};
} // namespace Ui

QT_END_NAMESPACE

#endif // MANDELBROTFRACTALS_UI_H
