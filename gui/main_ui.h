#ifndef UI_MAIN_H
#define UI_MAIN_H

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

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QDialogButtonBox *buttonExitBox;
    QWidget *mainVerticalLayoutWidget;
    QVBoxLayout *mainVerticalLayout;
    QHBoxLayout *HLayoutXres;
    QLabel *labelXres;
    QSpinBox *spinBoxXres;
    QLabel *labelYres;
    QSpinBox *spinBoxYres;

    virtual void setupUi(QDialog *MainParamsUI)
    {
        if (MainParamsUI->objectName().isEmpty())
            MainParamsUI->setObjectName("MainParamsUI");

        MainParamsUI->resize(547, 300);
        /* Exit box */
        buttonExitBox = new QDialogButtonBox(MainParamsUI);
        buttonExitBox->setObjectName("buttonBox");
        buttonExitBox->setGeometry(QRect(30, 240, 341, 32));
        buttonExitBox->setOrientation(Qt::Horizontal);
        buttonExitBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        /* layout main window */
        mainVerticalLayoutWidget = new QWidget(MainParamsUI);
        mainVerticalLayoutWidget->setObjectName("mainVerticalLayoutWidget");
        mainVerticalLayoutWidget->setGeometry(QRect(10, 10, 531, 231));
        mainVerticalLayout = new QVBoxLayout(mainVerticalLayoutWidget);
        mainVerticalLayout->setObjectName("mainVerticalLayout");
        mainVerticalLayout->setContentsMargins(0, 0, 0, 0);
    
        /* Xres */
        HLayoutXres = new QHBoxLayout();
        HLayoutXres->setObjectName("HLayoutXres");
   
        labelXres = new QLabel(mainVerticalLayoutWidget);
        labelXres->setObjectName("xres");

        HLayoutXres->addWidget(labelXres);

        spinBoxXres = new QSpinBox(mainVerticalLayoutWidget);
        spinBoxXres->setObjectName("spinBoxXres");
        spinBoxXres->setMinimum(320);
        spinBoxXres->setMaximum(9100);
        spinBoxXres->setSingleStep(1);
        spinBoxXres->setValue(1280);

        HLayoutXres->addWidget(spinBoxXres);

        /* Yres */
        labelYres = new QLabel(mainVerticalLayoutWidget);
        labelYres->setObjectName("labelYres");

        HLayoutXres->addWidget(labelYres);

        spinBoxYres = new QSpinBox(mainVerticalLayoutWidget);
        spinBoxYres->setObjectName("yresvalue");
        spinBoxYres->setMinimum(200);
        spinBoxYres->setMaximum(6500);
        spinBoxYres->setSingleStep(1);
        spinBoxYres->setValue(768);

        HLayoutXres->addWidget(spinBoxYres);


        mainVerticalLayout->addLayout(HLayoutXres);
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
