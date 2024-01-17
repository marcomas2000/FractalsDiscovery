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
    //QWidget *centralWidget;
    QFormLayout *formLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QStatusBar *statusBar;

    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *julia_HLayout;
    QLabel *labelJulia;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioSquared;
    QRadioButton *radioCosh;
    QRadioButton *radioExp;
    QRadioButton *radioPower4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelAttract;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioHenon;
    QRadioButton *radioIkeda;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelMandel;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioMandel;
    QHBoxLayout *lyap_HLayout;
    QVBoxLayout *labelLyapVLayout;
    QLabel *labelLyap;
    QVBoxLayout *radioLyapVLayout;
    QRadioButton *radioLyap;
    QButtonGroup *buttonGroup;

    QHBoxLayout *bifurcationLayout;
    QLabel *labelbifur;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *radioBifur;



    void setupUi(QMainWindow *MainFractals)
    {
        if (MainFractals->objectName().isEmpty())
            MainFractals->setObjectName("MainFractals");

        setupWindowsMenus(MainFractals);
        setupBifurcation(MainFractals);
        setupJulia(MainFractals);
        setupAttract(MainFractals);
        setupMandel(MainFractals);
        setupLyap(MainFractals);

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
        labelJulia->setText(QCoreApplication::translate("MainFractals", "Julia Sets", nullptr));
        radioSquared->setText(QCoreApplication::translate("MainFractals", "Squared", nullptr));
        radioCosh->setText(QCoreApplication::translate("MainFractals", "HyperbolicCos", nullptr));
        radioExp->setText(QCoreApplication::translate("MainFractals", "Exponential", nullptr));
        radioPower4->setText(QCoreApplication::translate("MainFractals", "Power4", nullptr));
        labelAttract->setText(QCoreApplication::translate("MainFractals", "Attractors", nullptr));
        radioHenon->setText(QCoreApplication::translate("MainFractals", "Henon", nullptr));
        radioIkeda->setText(QCoreApplication::translate("MainFractals", "Ikeda", nullptr));
        labelMandel->setText(QCoreApplication::translate("MainFractals", "Mandelbrot Sets", nullptr));
        radioMandel->setText(QCoreApplication::translate("MainFractals", "Mandelbrot", nullptr));
        labelLyap->setText(QCoreApplication::translate("MainFractals", "Lyapunov", nullptr));
        radioLyap->setText(QCoreApplication::translate("MainFractals", "", nullptr));
        labelbifur->setText(QCoreApplication::translate("MainFractals", "Bifurcation", nullptr));
        radioBifur->setText(QCoreApplication::translate("MainFractals", "", nullptr));
    } // retranslateUi

private:
    void setupWindowsMenus(QMainWindow *MainFractals)
    {
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

        buttonGroup = new QButtonGroup(MainFractals);
        buttonGroup->setObjectName("buttonGroup");
    }

    void setupLyap(QMainWindow *MainFractals)
    {
        lyap_HLayout = new QHBoxLayout();
        lyap_HLayout->setObjectName("lyap_HLayout");
        labelLyapVLayout = new QVBoxLayout();
        labelLyapVLayout->setObjectName("labelLyapVLayout");
        labelLyap = new QLabel(verticalLayoutWidget);
        labelLyap->setObjectName("labelLyap");

        labelLyapVLayout->addWidget(labelLyap);

        lyap_HLayout->addLayout(labelLyapVLayout);

        radioLyapVLayout = new QVBoxLayout();
        radioLyapVLayout->setObjectName("radioLyapVLayout");
        radioLyap = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioLyap);
        radioLyap->setObjectName("radioLyap");

        radioLyapVLayout->addWidget(radioLyap);
        lyap_HLayout->addLayout(radioLyapVLayout);
        verticalLayout->addLayout(lyap_HLayout);
    }

    void setupJulia(QMainWindow *MainFractals)
    {
        julia_HLayout = new QHBoxLayout();
        julia_HLayout->setObjectName("julia_HLayout");
        labelJulia = new QLabel(verticalLayoutWidget);
        labelJulia->setObjectName("labelJulia");

        julia_HLayout->addWidget(labelJulia);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioSquared = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioSquared);
        radioSquared->setObjectName("radioSquared");
        radioSquared->setChecked(true);
        
        verticalLayout_2->addWidget(radioSquared);
        radioCosh = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioCosh);
        radioCosh->setObjectName("radioCosh");

        verticalLayout_2->addWidget(radioCosh);

        radioExp = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioExp);
        radioExp->setObjectName("radioExp");

        verticalLayout_2->addWidget(radioExp);

        radioPower4 = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioPower4);
        radioPower4->setObjectName("radioPower4");

        verticalLayout_2->addWidget(radioPower4);
        julia_HLayout->addLayout(verticalLayout_2);
        verticalLayout->addLayout(julia_HLayout);
    }

    void setupAttract(QMainWindow *MainFractals)
    {
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        labelAttract = new QLabel(verticalLayoutWidget);
        labelAttract->setObjectName("labelAttract");

        horizontalLayout_4->addWidget(labelAttract);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        radioHenon = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioHenon);
        radioHenon->setObjectName("radioHenon");

        verticalLayout_6->addWidget(radioHenon);

        radioIkeda = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioIkeda);
        radioIkeda->setObjectName("radioIkeda");

        verticalLayout_6->addWidget(radioIkeda);
        horizontalLayout_4->addLayout(verticalLayout_6);
        verticalLayout->addLayout(horizontalLayout_4);
    }

    void setupMandel(QMainWindow *MainFractals)
    {
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelMandel = new QLabel(verticalLayoutWidget);
        labelMandel->setObjectName("labelMandel");

        horizontalLayout_2->addWidget(labelMandel);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        radioMandel = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioMandel);
        radioMandel->setObjectName("radioMandel");

        verticalLayout_3->addWidget(radioMandel);
        horizontalLayout_2->addLayout(verticalLayout_3);
        verticalLayout->addLayout(horizontalLayout_2);
    }

    void setupBifurcation(QMainWindow *MainFractals)
    {

        bifurcationLayout = new QHBoxLayout();
        bifurcationLayout->setObjectName("bifurcationlLayout");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        labelbifur = new QLabel(verticalLayoutWidget);
        labelbifur->setObjectName("labelbifur");
        verticalLayout_7->addWidget(labelbifur);
        bifurcationLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        radioBifur = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(radioBifur);
        radioBifur->setObjectName("radioBifur");

        verticalLayout_8->addWidget(radioBifur);
        bifurcationLayout->addLayout(verticalLayout_8);
        verticalLayout->addLayout(bifurcationLayout);
    }
};

namespace Ui {
    class MainFractals: public Ui_MainFractals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINFRACTALS_UI_H
