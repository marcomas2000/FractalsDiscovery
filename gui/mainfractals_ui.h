/********************************************************************************
** Form generated from reading UI file 'mainfractals.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINFRACTALS_UI_H
#define MAINFRACTALS_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QButtonGroup>

QT_BEGIN_NAMESPACE

class Ui_MainFractals
{
public:
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionConfigure;
    QAction *actionGenerate;
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QStatusBar *statusBar;

    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton_5;
    QButtonGroup *buttonGroup;




    void setupUi(QMainWindow *MainFractals)
    {
        if (MainFractals->objectName().isEmpty())
            MainFractals->setObjectName("MainFractals");
        MainFractals->resize(400, 300);

        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        MainFractals->setSizePolicy(sizePolicy);

        actionLoad = new QAction(MainFractals);
        actionLoad->setObjectName("actionLoad");
        actionExit = new QAction(MainFractals);
        actionExit->setObjectName("actionExit");
        actionConfigure = new QAction(MainFractals);
        actionConfigure->setObjectName("actionConfigure");
        actionGenerate = new QAction(MainFractals);
        actionGenerate->setObjectName("actionGenerate");

        centralWidget = new QWidget(MainFractals);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setSizePolicy(sizePolicy);

        MainFractals->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainFractals);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName("menuTools");
        MainFractals->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainFractals);
        statusBar->setObjectName("statusBar");
        MainFractals->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuBar->addAction(menuTools->menuAction());
        menuTools->addAction(actionConfigure);
        actionGenerate->setDisabled(true);
        menuTools->addAction(actionGenerate);

        verticalLayoutWidget = new QWidget(MainFractals);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioButton = new QRadioButton(verticalLayoutWidget);
        buttonGroup = new QButtonGroup(MainFractals);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName("radioButton");
        radioButton->setChecked(true);
        
        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_6 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioButton_6);
        radioButton_6->setObjectName("radioButton_6");

        verticalLayout_2->addWidget(radioButton_6);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        radioButton_7 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioButton_7);
        radioButton_7->setObjectName("radioButton_7");

        verticalLayout_6->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioButton_8);
        radioButton_8->setObjectName("radioButton_8");

        verticalLayout_6->addWidget(radioButton_8);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        radioButton_4 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioButton_4);
        radioButton_4->setObjectName("radioButton_4");

        verticalLayout_3->addWidget(radioButton_4);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        radioButton_5 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioButton_5);
        radioButton_5->setObjectName("radioButton_5");

        verticalLayout_5->addWidget(radioButton_5);


        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_3);

        retranslateUi(MainFractals);

        QMetaObject::connectSlotsByName(MainFractals);
    } // setupUi

    void retranslateUi(QMainWindow *MainFractals)
    {
        MainFractals->setWindowTitle(QCoreApplication::translate("MainFractals", "Fractals Discovery", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainFractals", "Load", nullptr));
        actionExit->setText(QCoreApplication::translate("MainFractals", "Exit", nullptr));
        actionConfigure->setText(QCoreApplication::translate("MainFractals", "Configure", nullptr));
        actionGenerate->setText(QCoreApplication::translate("MainFractals", "Generate", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainFractals", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainFractals", "Tools", nullptr));
        label->setText(QCoreApplication::translate("MainFractals", "Julia Sets", nullptr));
        radioButton->setText(QCoreApplication::translate("MainFractals", "Squared", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainFractals", "HyperbolicCos", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainFractals", "Exponential", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainFractals", "Power4", nullptr));
        label_4->setText(QCoreApplication::translate("MainFractals", "Attractors", nullptr));
        radioButton_7->setText(QCoreApplication::translate("MainFractals", "Henon", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainFractals", "Ikeda", nullptr));
        label_2->setText(QCoreApplication::translate("MainFractals", "Mandelbrot Sets", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainFractals", "Mandelbrot", nullptr));
        label_3->setText(QCoreApplication::translate("MainFractals", "Lyapunov", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainFractals", "", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFractals: public Ui_MainFractals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINFRACTALS_UI_H
