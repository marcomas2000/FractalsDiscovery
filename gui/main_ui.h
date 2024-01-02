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
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;

    virtual void setupUi(QDialog *MainParamsUI)
    {
        if (MainParamsUI->objectName().isEmpty())
            MainParamsUI->setObjectName("MainParamsUI");
        MainParamsUI->resize(547, 300);
        buttonBox = new QDialogButtonBox(MainParamsUI);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(MainParamsUI);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 531, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
   
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("xres");

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName("xresvalue");
        spinBox->setMinimum(320);
        spinBox->setMaximum(9100);
        spinBox->setSingleStep(1);
        spinBox->setValue(1280);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("yres");

        horizontalLayout->addWidget(label_2);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName("yresvalue");
        spinBox_2->setMinimum(200);
        spinBox_2->setMaximum(6500);
        spinBox_2->setSingleStep(1);
        spinBox_2->setValue(768);

        horizontalLayout->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MainParamsUI, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MainParamsUI, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MainParamsUI);
    } // setupUi

    virtual void retranslateUi(QDialog *MainParamsUI)
    {
        label->setText(QObject::tr("Xres"));
        label_2->setText(QObject::tr("Yres"));
    } // retranslateUi

};


QT_END_NAMESPACE

#endif // UI_MAIN_H
