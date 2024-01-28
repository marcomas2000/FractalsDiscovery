#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QDialogButtonBox *buttonExitBox;
    QLabel *labelXres;
    QSpinBox *spinBoxXres;
    QLabel *labelYres;
    QSpinBox *spinBoxYres;

    QGridLayout *gridLayout;

    virtual void setupUi(QDialog *MainParamsUI)
    {
        if (MainParamsUI->objectName().isEmpty())
            MainParamsUI->setObjectName("MainParamsUI");

        MainParamsUI->setFixedSize(QGuiApplication::primaryScreen()->availableGeometry().size() * 0.3);

        /* layout main window */
    
        gridLayout = new QGridLayout();
        MainParamsUI->setLayout(gridLayout);

        /* Xres */   
        labelXres = new QLabel();
        labelXres->setObjectName("xres");

        spinBoxXres = new QSpinBox();
        spinBoxXres->setObjectName("spinBoxXres");
        spinBoxXres->setMinimum(320);
        spinBoxXres->setMaximum(30000);
        spinBoxXres->setSingleStep(100);
        spinBoxXres->setValue(1024);

        gridLayout->addWidget(labelXres, 0, 0);
        gridLayout->addWidget(spinBoxXres, 0, 1);


        /* Yres */
        labelYres = new QLabel();
        labelYres->setObjectName("labelYres");

        spinBoxYres = new QSpinBox();
        spinBoxYres->setObjectName("yresvalue");
        spinBoxYres->setMinimum(200);
        spinBoxYres->setMaximum(20000);
        spinBoxYres->setSingleStep(100);
        spinBoxYres->setValue(768);

        gridLayout->addWidget(labelYres, 0, 2);
        gridLayout->addWidget(spinBoxYres, 0, 3);

        buttonExitBox = new QDialogButtonBox(MainParamsUI);
        QObject::connect(buttonExitBox, &QDialogButtonBox::accepted, MainParamsUI, qOverload<>(&QDialog::accept));
        QObject::connect(buttonExitBox, &QDialogButtonBox::rejected, MainParamsUI, qOverload<>(&QDialog::reject));
        QMetaObject::connectSlotsByName(MainParamsUI);

    } // setupUi

    virtual void retranslateUi(QDialog *MainParamsUI)
    {
        labelXres->setText(QObject::tr("H Res"));
        labelYres->setText(QObject::tr("Y Res"));
    } // retranslateUi

};


QT_END_NAMESPACE

#endif // UI_MAIN_H
