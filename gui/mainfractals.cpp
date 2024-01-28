#include "mainfractals.h"
#include "mainfractals_ui.h"
//#include "fractaltypes.h"
//#include "../creators/juliasquared.h"
//#include "../creators/juliacosh.h"
//#include "../creators/juliaexp.h"
//#include "../creators/juliapower4.h"
//#include "../creators/mandelbrot.h"
//#include "../creators/lyapunov.h"
#include "../creators/bifurcation.h"
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

void MainFractals::on_actionConfigure_triggered()
{
    int ret, ret2;

    switch (ui->buttonGroup->checkedId())
    {
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
        case (int) FRACTAL_DOMAIN::BIFURCATION:
            {
                BifurFractalParams * bifurParams = new BifurFractalParams;
                ret2 = bifurParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    QApplication::setOverrideCursor(Qt::WaitCursor);
                    QApplication::processEvents();
                    ui->statusBar->showMessage("Generating data. Please wait...");
                    std::thread generation(&MainFractals::createBifurImage, this, bifurParams);
                    generation.join();
                    ui->statusBar->showMessage("...Data generation completed.");
                    QApplication::restoreOverrideCursor();
                }
            }                
            break;
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

void MainFractals::createBifurImage(BifurFractalParams * imParams)
{

    Bifurcation * im = new Bifurcation;
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