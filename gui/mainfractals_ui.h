/********************************************
 * Author: Marco Mascioli,  2024
 * Released under Apache License
 *******************************************/

#ifndef MAINFRACTALS_UI_H
#define MAINFRACTALS_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QGuiApplication>
#include <QtGui/QScreen>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QButtonGroup>

#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_MainFractals
{
public:
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionConfigure;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QStatusBar *statusBar;

    // Bifurcation
    QLabel *labelbifur;
    QRadioButton *radioBifur;

    // Universals
    QLabel *labelUniversal;
    QRadioButton *radioUniSin;
    QRadioButton *radioUniPiSin;
    QRadioButton *radioUni1MinusSquared;
    QRadioButton *radioUniXCubed;
    QRadioButton *radioUniXQuater;
    QRadioButton *radioUniLyapLike;
    QRadioButton *radioUniTent;

    // Julias 
    QLabel *labelJulia;
    QRadioButton *radioSquared;
    QRadioButton *radioCosh;
    QRadioButton *radioExp;
    QRadioButton *radioPower4;
    QLabel *labelAttract;
    QRadioButton *radioHenon;
    QRadioButton *radioIkeda;
    QLabel *labelMandel;
    QRadioButton *radioMandel;
    QLabel *labelLyap;
    QRadioButton *radioLyap;

    QButtonGroup *buttonGroup;

    QWidget *widget;
    QGridLayout *gridLayout;

    void setupUi(QMainWindow *MainFractals)
    {
        if (MainFractals->objectName().isEmpty())
            MainFractals->setObjectName("MainFractals");

        setupWindowsMenus(MainFractals);
        setupBifurcation(MainFractals);
        setupUniversal(MainFractals);
        //setupJulia(MainFractals);
        //setupAttract(MainFractals);
        //setupMandel(MainFractals);
        //setupLyap(MainFractals);

        retranslateUi(MainFractals);
        
        QMetaObject::connectSlotsByName(MainFractals);
    
    } // setupUi

    void retranslateUi(QMainWindow *MainFractals)
    {
        MainFractals->setWindowTitle(QCoreApplication::translate("MainFractals", "Fractals Discovery", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainFractals", "Load", nullptr));
        actionExit->setText(QCoreApplication::translate("MainFractals", "Exit", nullptr));
        actionConfigure->setText(QCoreApplication::translate("MainFractals", "Configure", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainFractals", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainFractals", "Tools", nullptr));
        // Bifurcation
        labelbifur->setText(QCoreApplication::translate("MainFractals", "Bifurcation", nullptr));
        radioBifur->setText(QCoreApplication::translate("MainFractals", "pow(x,2)+c", nullptr));
        // Universal
        labelUniversal->setText(QCoreApplication::translate("MainFractals", "Universality", nullptr));
        radioUniSin->setText(QCoreApplication::translate("MainFractals", "c sin x", nullptr));
        radioUniPiSin->setText(QCoreApplication::translate("MainFractals", "sin(Pi x)+c", nullptr));
        radioUni1MinusSquared->setText(QCoreApplication::translate("MainFractals", "cx(1-x)", nullptr));
        radioUniXCubed->setText(QCoreApplication::translate("MainFractals", "c pow(x,3)(1-x)", nullptr));
        radioUniXQuater->setText(QCoreApplication::translate("MainFractals", "c(1- pow((2x-1),4)", nullptr));
        radioUniLyapLike->setText(QCoreApplication::translate("MainFractals", "cx(1-x)", nullptr));
        radioUniTent->setText(QCoreApplication::translate("MainFractals", "c(1-2|x-1/2|)", nullptr));

        //labelJulia->setText(QCoreApplication::translate("MainFractals", "Julia Sets", nullptr));
        //radioSquared->setText(QCoreApplication::translate("MainFractals", "Squared", nullptr));
        //radioCosh->setText(QCoreApplication::translate("MainFractals", "HyperbolicCos", nullptr));
        //radioExp->setText(QCoreApplication::translate("MainFractals", "Exponential", nullptr));
        //radioPower4->setText(QCoreApplication::translate("MainFractals", "Power4", nullptr));
        //labelAttract->setText(QCoreApplication::translate("MainFractals", "Attractors", nullptr));
        //radioHenon->setText(QCoreApplication::translate("MainFractals", "Henon", nullptr));
        //radioIkeda->setText(QCoreApplication::translate("MainFractals", "Ikeda", nullptr));
        //labelMandel->setText(QCoreApplication::translate("MainFractals", "Mandelbrot Sets", nullptr));
        //radioMandel->setText(QCoreApplication::translate("MainFractals", "Mandelbrot", nullptr));
        //labelLyap->setText(QCoreApplication::translate("MainFractals", "Lyapunov", nullptr));
        //radioLyap->setText(QCoreApplication::translate("MainFractals", "", nullptr));
    } // retranslateUi

private:
    void setupWindowsMenus(QMainWindow *MainFractals)
    {
        MainFractals->setFixedSize(QGuiApplication::primaryScreen()->availableGeometry().size() * 0.3);

        actionLoad = new QAction(MainFractals);
        actionLoad->setObjectName("actionLoad");
        actionLoad->setDisabled(true);
        actionExit = new QAction(MainFractals);
        actionExit->setObjectName("actionExit");
        actionConfigure = new QAction(MainFractals);
        actionConfigure->setObjectName("actionConfigure");

        menuBar = new QMenuBar(MainFractals);
        menuBar->setObjectName("menuBar");
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

        buttonGroup = new QButtonGroup(MainFractals);
        buttonGroup->setObjectName("buttonGroup");

        gridLayout = new QGridLayout();

        QWidget* widget = new QWidget(MainFractals);
        widget->setLayout(gridLayout);
        MainFractals->setCentralWidget(widget);
    }

    void setupLyap(QMainWindow *MainFractals)
    {
        labelLyap = new QLabel();
        labelLyap->setObjectName("labelLyap");

        radioLyap = new QRadioButton();
        buttonGroup->addButton(radioLyap);
        radioLyap->setObjectName("radioLyap");

        gridLayout->addWidget(labelMandel, 8, 0);
        gridLayout->addWidget(radioMandel, 8, 1);
    }

    void setupJulia(QMainWindow *MainFractals)
    {
        labelJulia = new QLabel();
        labelJulia->setObjectName("labelJulia");

        radioSquared = new QRadioButton();
        buttonGroup->addButton(radioSquared);
        radioSquared->setObjectName("radioSquared");
        
        radioCosh = new QRadioButton();
        buttonGroup->addButton(radioCosh);
        radioCosh->setObjectName("radioCosh");

        radioExp = new QRadioButton();
        buttonGroup->addButton(radioExp);
        radioExp->setObjectName("radioExp");

        radioPower4 = new QRadioButton();
        buttonGroup->addButton(radioPower4);
        radioPower4->setObjectName("radioPower4");

        gridLayout->addWidget(labelJulia, 1, 0, 4, 1);
        gridLayout->addWidget(radioSquared, 1, 1);
        gridLayout->addWidget(radioCosh, 2, 1);
        gridLayout->addWidget(radioExp, 3, 1);
        gridLayout->addWidget(radioPower4, 4, 1);
    }

    void setupAttract(QMainWindow *MainFractals)
    {
        labelAttract = new QLabel();
        labelAttract->setObjectName("labelAttract");

        radioHenon = new QRadioButton();
        buttonGroup->addButton(radioHenon);
        radioHenon->setObjectName("radioHenon");

        radioIkeda = new QRadioButton();
        buttonGroup->addButton(radioIkeda);
        radioIkeda->setObjectName("radioIkeda");

        gridLayout->addWidget(labelAttract, 5, 0, 2, 1);
        gridLayout->addWidget(radioHenon, 5, 1);
        gridLayout->addWidget(radioIkeda, 6, 1);
    }

    void setupMandel(QMainWindow *MainFractals)
    {
        labelMandel = new QLabel();
        labelMandel->setObjectName("labelMandel");

        radioMandel = new QRadioButton();
        buttonGroup->addButton(radioMandel);
        radioMandel->setObjectName("radioMandel");

        gridLayout->addWidget(labelMandel, 7, 0);
        gridLayout->addWidget(radioMandel, 7, 1);

    }

    void setupBifurcation(QMainWindow *MainFractals)
    {
        labelbifur = new QLabel();
        labelbifur->setObjectName("labelbifur");

        radioBifur = new QRadioButton();
        buttonGroup->addButton(radioBifur);
        radioBifur->setObjectName("radioBifur");
        radioBifur->setChecked(true);

        gridLayout->addWidget(labelbifur, 0, 0);
        gridLayout->addWidget(radioBifur, 0, 1);
    }

    void setupUniversal(QMainWindow *MainFractals)
    {
        labelUniversal = new QLabel();
        labelUniversal->setObjectName("labelUniversal");

        radioUniSin = new QRadioButton();
        buttonGroup->addButton(radioUniSin);
        radioUniSin->setObjectName("radioUniSin");

        radioUniPiSin = new QRadioButton();
        buttonGroup->addButton(radioUniPiSin);
        radioUniPiSin->setObjectName("radioUniPiSin");

        radioUni1MinusSquared = new QRadioButton();
        buttonGroup->addButton(radioUni1MinusSquared);
        radioUni1MinusSquared->setObjectName("radioUni1MinusSquared");

        radioUniXCubed = new QRadioButton();
        buttonGroup->addButton(radioUniXCubed);
        radioUniXCubed->setObjectName("radioUniXCubed");

        radioUniXQuater = new QRadioButton();
        buttonGroup->addButton(radioUniXQuater);
        radioUniXQuater->setObjectName("radioUniXQuater");

        radioUniLyapLike = new QRadioButton();
        buttonGroup->addButton(radioUniLyapLike);
        radioUniLyapLike->setObjectName("radioUniLyapLike");

        radioUniTent = new QRadioButton();
        buttonGroup->addButton(radioUniTent);
        radioUniTent->setObjectName("radioUniTent");

        gridLayout->addWidget(labelUniversal, 1, 0, 7, 1);
        gridLayout->addWidget(radioUniSin, 1, 1);
        gridLayout->addWidget(radioUniPiSin, 2, 1);
        gridLayout->addWidget(radioUni1MinusSquared, 3, 1);
        gridLayout->addWidget(radioUniXCubed, 4, 1);
        gridLayout->addWidget(radioUniXQuater, 5, 1);
        gridLayout->addWidget(radioUniLyapLike, 6, 1);
        gridLayout->addWidget(radioUniTent, 7, 1);
    }
};

namespace Ui {
    class MainFractals: public Ui_MainFractals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINFRACTALS_UI_H
