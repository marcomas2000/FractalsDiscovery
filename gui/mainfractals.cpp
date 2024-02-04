#include "mainfractals.h"
#include "mainfractals_ui.h"
//#include "fractaltypes.h"
#include "../creators/bifurcation.h"
#include "../creators/unisin.h"
#include "../creators/unipisin.h"
#include "../creators/uni1minussquare.h"
#include "../creators/unixcubed.h"
#include "../creators/unixquater.h"
#include "../creators/unilyaplike.h"
#include "../creators/unitent.h"
//#include "../creators/juliasquared.h"
//#include "../creators/juliacosh.h"
//#include "../creators/juliaexp.h"
//#include "../creators/juliapower4.h"
//#include "../creators/mandelbrot.h"
//#include "../creators/lyapunov.h"
//#include "attracthenon.h"
//#include "attractikeda.h"
#include "juliasquaredfractalparams.h"
#include "juliacoshfractalparams.h"
#include "juliaexpfractalparams.h"
#include "juliapower4fractalparams.h"
#include "mandelbrotfractalparams.h"
#include "lyapfractalparams.h"
#include "bifurfractalparams.h"
//#include <QFileDialog>
//#include <QPixmap>
//#include <QImageWriter>
//#include <QFile>
//#include <QXmlStreamWriter>
//#include <QHBoxLayout>
//#include <QGraphicsSceneMouseEvent>
//#include <QGraphicsItem>
#include <QDir>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include <QStandardPaths>
#include <QtWidgets/QStatusBar>
#include <thread>

MainFractals::MainFractals(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainFractals)
{
    QDir pictureFolder(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    if (!pictureFolder.exists())
    {
        pictureFolder.mkpath(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    }
    ui->setupUi(this);

}

MainFractals::~MainFractals()
{
    delete ui;
}

void MainFractals::on_actionExit_triggered()
{
    exit(0);
}

void MainFractals::on_actionLoad_triggered()
{
    // exit(0);
}

void MainFractals::closeEvent(QCloseEvent *event)
{
    exit(0);
}

void MainFractals::dataGeneration(BifurFractalParams * bifurParams, BifurSet *im)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QApplication::processEvents();
    ui->statusBar->showMessage("Generating data. Please wait...");
    std::thread generation(&MainFractals::createBifurImage, this, bifurParams, im);
    generation.join();
    ui->statusBar->showMessage("...Data generation completed.");
    QApplication::restoreOverrideCursor();
}

void MainFractals::on_actionConfigure_triggered()
{
    int ret, ret2;

    switch (ui->buttonGroup->checkedId())
    {
        case (int) FRACTAL_DOMAIN::BIFURCATION:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                Bifurcation * im = new Bifurcation;
                std::string title = "Bifurcation Params: pow(x,2)+c";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;

        case (int) FRACTAL_DOMAIN::UNISIN:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                UniSin * im = new UniSin;
                std::string title = "Bifurcation Params: c sin(x)";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;

        case (int) FRACTAL_DOMAIN::UNIPISIN:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                UniPiSin * im = new UniPiSin;
                std::string title = "Bifurcation Params: sin(PI x)+ c";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;

        case (int) FRACTAL_DOMAIN::UNI1MINUSSQUARE:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                Uni1MinusSquare * im = new Uni1MinusSquare;
                std::string title = "Bifurcation Params: cx (1-pow(x,2))";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;
        case (int) FRACTAL_DOMAIN::UNIXCUBED:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                UniXCubed * im = new UniXCubed;
                std::string title = "Bifurcation Params: c pow(x,3)(1-x)";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;

        case (int) FRACTAL_DOMAIN::UNIXQUATER:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                UniXQuater * im = new UniXQuater;
                std::string title = "Bifurcation Params: c ( 1-pow((2x - 1),4))";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;

        case (int) FRACTAL_DOMAIN::UNILYAPLIKE:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                UniLyapLike * im = new UniLyapLike;
                std::string title = "Bifurcation Params: cx (1-x))";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;

        case (int) FRACTAL_DOMAIN::UNITENT:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                UniTent * im = new UniTent;
                std::string title = "Bifurcation Params: c (1 - 2 |x - 1/2|)";
                bifurParams->setWindowTitle(QCoreApplication::translate("BifurFractalParams", title.c_str(), nullptr));
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    dataGeneration(bifurParams, im);
                }
            }                
            break;

        /**********
        case (int) FRACTAL_DOMAIN::SQUARED:
            {
                JuliaSquaredFractalParams * juliaSqParams = new JuliaSquaredFractalParams;
                ret2 = juliaSqParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    std::thread generation(&MainFractals::createJuliaSquaredImage, this, juliaSqParams);
                    generation.detach();
                }
            }
            break;                
        case (int) FRACTAL_DOMAIN::HCOS:
            {
                JuliaCosHFractalParams * juliaCosHParams = new JuliaCosHFractalParams;
                ret2 = juliaCosHParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    std::thread generation(&MainFractals::createJuliaCosHImage, this, juliaCosHParams);
                    generation.detach();
                }
            }                
            break;
        case (int) FRACTAL_DOMAIN::EXPONENTIAL:
            {
                JuliaExpFractalParams * juliaExpParams = new JuliaExpFractalParams;
                ret2 = juliaExpParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    std::thread generation(&MainFractals::createJuliaExpImage, this, juliaExpParams);
                    generation.detach();
                }
            }                
            break;
        case (int) FRACTAL_DOMAIN::POWER4:
            {
                JuliaPower4FractalParams * juliaPower4Params = new JuliaPower4FractalParams;
                ret2 = juliaPower4Params->exec();
                if (ret2 == QDialog::Accepted)
                {
                    std::thread generation(&MainFractals::createJuliaPower4Image, this, juliaPower4Params);
                    generation.detach();
                }
            }                
            break;
        case (int) FRACTAL_DOMAIN::MANDELBROT:
            {
                MandelbrotFractalParams * mandelbrotParams = new MandelbrotFractalParams;
                ret2 = mandelbrotParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    std::thread generation(&MainFractals::createMandelbrotImage, this, mandelbrotParams);
                    generation.detach();
                }
            }                
            break;
        case (int) FRACTAL_DOMAIN::LYAPUNOV:
            {
                LyapFractalParams * lyapParams = new LyapFractalParams;
                ret2 = lyapParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    std::thread generation(&MainFractals::createLyapImage, this, lyapParams);
                    generation.detach();
                }
            }                
            break;
        *******/
        default:
            break;
    }
}

/****
void MainFractals::createJuliaSquaredImage(JuliaSquaredFractalParams * imParams)
{
    JuliaSquared * im = new JuliaSquared;
    im->setXres(imParams->getXres());
    im->setYres(imParams->getYres());
    im->setXmin(imParams->getXmin());
    im->setYmin(imParams->getYmin());
    im->setXmax(imParams->getXmax());
    im->setYmax(imParams->getYmax());
    im->setMaxiter(imParams->getMaxiter());
    im->setLx(imParams->getLx());
    im->setLy(imParams->getLy());
    im->setDivergencyFactor(imParams->getDivergencyFactor());

    double quote=im->createJulia();
    im->storeImage((QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toStdString().c_str());
    emit generationCompleted();
}

void MainFractals::createJuliaCosHImage(JuliaCosHFractalParams * imParams)
{
    JuliaCosH * im = new JuliaCosH;
    im->setXres(imParams->getXres());
    im->setYres(imParams->getYres());
    im->setXmin(imParams->getXmin());
    im->setYmin(imParams->getYmin());
    im->setXmax(imParams->getXmax());
    im->setYmax(imParams->getYmax());
    im->setMaxiter(imParams->getMaxiter());
    im->setLx(imParams->getLx());
    im->setLy(imParams->getLy());
    im->setDivergencyFactor(imParams->getDivergencyFactor());

    double quote=im->createJulia();
    im->storeImage((QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toStdString().c_str());
    emit generationCompleted();
}

void MainFractals::createJuliaExpImage(JuliaExpFractalParams * imParams)
{
    JuliaExp * im = new JuliaExp;
    im->setXres(imParams->getXres());
    im->setYres(imParams->getYres());
    im->setXmin(imParams->getXmin());
    im->setYmin(imParams->getYmin());
    im->setXmax(imParams->getXmax());
    im->setYmax(imParams->getYmax());
    im->setMaxiter(imParams->getMaxiter());
    im->setLx(imParams->getLx());
    im->setLy(imParams->getLy());
    im->setDivergencyFactor(imParams->getDivergencyFactor());

    double quote=im->createJulia();
    im->storeImage((QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toStdString().c_str());
    emit generationCompleted();
}

void MainFractals::createJuliaPower4Image(JuliaPower4FractalParams * imParams)
{
    JuliaPower4 * im = new JuliaPower4;
    im->setXres(imParams->getXres());
    im->setYres(imParams->getYres());
    im->setXmin(imParams->getXmin());
    im->setYmin(imParams->getYmin());
    im->setXmax(imParams->getXmax());
    im->setYmax(imParams->getYmax());
    im->setMaxiter(imParams->getMaxiter());
    im->setLx(imParams->getLx());
    im->setLy(imParams->getLy());
    im->setDivergencyFactor(imParams->getDivergencyFactor());

    double quote=im->createJulia();
    im->storeImage((QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toStdString().c_str());
    emit generationCompleted();
}

void MainFractals::createMandelbrotImage(MandelbrotFractalParams * imParams)
{
    Mandelbrot * im = new Mandelbrot;
    im->setXres(imParams->getXres());
    im->setYres(imParams->getYres());
    im->setXmin(imParams->getXmin());
    im->setYmin(imParams->getYmin());
    im->setXmax(imParams->getXmax());
    im->setYmax(imParams->getYmax());
    im->setMaxiter(imParams->getMaxiter());
    im->setDivergencyFactor(imParams->getDivergencyFactor());

    double quote=im->createMandelbrot();
    im->storeImage((QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toStdString().c_str());
    emit generationCompleted();
}

void MainFractals::createLyapImage(LyapFractalParams * imParams)
{
    Lyapunov * im = new Lyapunov;
    im->setXres(imParams->getXres());
    im->setYres(imParams->getYres());
    im->setXmin(imParams->getXmin());
    im->setYmin(imParams->getYmin());
    im->setXmax(imParams->getXmax());
    im->setYmax(imParams->getYmax());
    im->setMaxiter(imParams->getMaxiter());
    im->setInitialPoint(imParams->getInitialPoint());
    im->setLyapSuccession(imParams->getLyapSuccession().toStdString().c_str());

    double quote=im->createLyap();
    im->storeImage((QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toStdString().c_str());
    emit generationCompleted();
}
*******/

void MainFractals::createBifurImage(BifurFractalParams * imParams, BifurSet * im)
{
    im->setXres(imParams->getXres());
    im->setYres(imParams->getYres());
    im->setXmin(imParams->getXmin());
    im->setXmax(imParams->getXmax());
    im->setCmin(imParams->getCmin());
    im->setCmax(imParams->getCmax());
    im->setNoIterationsToExclude(imParams->getNoIterationsToExclude());
    im->setInitialPoint(imParams->getInitialPoint());
    im->setMaxIter(imParams->getMaxIter());
    im->setStability(imParams->getStability());

    double quote=im->createBifur();
    im->storeImage((QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)).toStdString().c_str());
}