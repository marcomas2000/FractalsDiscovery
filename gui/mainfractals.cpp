#include "mainfractals.h"
#include "mainfractals_ui.h"
//#include "fractaltypes.h"
#include "../creators/juliasquared.h"
#include "../creators/juliacosh.h"
//#include "juliaexp.h"
//#include "attracthenon.h"
//#include "attractikeda.h"
//#include "juliapower4.h"
#include "juliasquaredfractalparams.h"
#include "juliacoshfractalparams.h"
//#include "lyapfractalparams.h"
//#include "mandelbrot.h"
//#include "lyapunov.h"
//#include <QFileDialog>
//#include <QPixmap>
//#include <QImageWriter>
//#include <QFile>
//#include <QXmlStreamWriter>
//#include <QHBoxLayout>
//#include <QGraphicsSceneMouseEvent>
//#include <QGraphicsItem>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <thread>

MainFractals::MainFractals(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainFractals)
{
    connect(this, &MainFractals::generationCompleted, this, &MainFractals::generationCompleted_triggered);
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

void MainFractals::generationCompleted_triggered()
{
    ui->actionGenerate->setEnabled(true);
}

void MainFractals::on_actionConfigure_triggered()
{
    int ret, ret2;

    switch (ui->buttonGroup->checkedId())
    {
        case (int) FRACTAL_DOMAIN::SQUARED:
            {
                qWarning() << "SQUARED";
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
                qWarning() << "HCOS";
                JuliaCosHFractalParams * juliaCosHParams = new JuliaCosHFractalParams;
                ret2 = juliaCosHParams->exec();
                if (ret2 == QDialog::Accepted)
                {
                    std::thread generation(&MainFractals::createJuliaCosHImage, this, juliaCosHParams);
                    generation.detach();
                }
            }                
            break;
        default:
            break;
    }
}

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
    im->storeImage();
    qWarning() << "Percentage converging points: "<< quote;
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
    im->storeImage();
    qWarning() << "Percentage converging points: "<< quote;
    emit generationCompleted();
}

/*************************
void MainFractals::showLyapImage()
{
    if (m_currentImage != 0)
    {
        delete m_currentImage;
    }
    m_lyapImage->setXres(m_lyapParams->getXres());
    m_lyapImage->setYres(m_lyapParams->getYres());
    m_lyapImage->setXmin(m_lyapParams->getXmin());
    m_lyapImage->setYmin(m_lyapParams->getYmin());
    m_lyapImage->setXmax(m_lyapParams->getXmax());
    m_lyapImage->setYmax(m_lyapParams->getYmax());
    m_lyapImage->setMaxiter(m_lyapParams->getMaxiter());
    m_lyapImage->setInitialPoint(m_lyapParams->getInitialPoint());
    m_lyapImage->setLyapSuccession(m_lyapParams->getLyapSuccession());

    m_lyapImage->createLyap();

    QPixmap * item = new QPixmap( QPixmap::fromImage(*(m_lyapImage->getImage())));
    m_currentImage = m_scene->addPixmap(*item);
    m_view->updateGeometry();

    m_generatedImageNotSaved = true;
    ui->actionSave->setEnabled(true);
}
*************************************/
/*********************************
void MainFractals::showAttractorImage()
{
    if (m_currentImage != 0)
    {
        delete m_currentImage;
    }
    m_attractImage->setXres(m_juliaParams->getXres());
    m_attractImage->setYres(m_juliaParams->getYres());
    m_attractImage->setXmin(m_juliaParams->getXmin());
    m_attractImage->setYmin(m_juliaParams->getYmin());
    m_attractImage->setXmax(m_juliaParams->getXmax());
    m_attractImage->setYmax(m_juliaParams->getYmax());
    m_attractImage->setMaxiter(m_juliaParams->getMaxiter());
    m_attractImage->setLx(m_juliaParams->getLx());
    m_attractImage->setLy(m_juliaParams->getLy());
    m_attractImage->setDivergencyFactor(m_juliaParams->getDivergencyFactor());

    m_attractImage->createAttractor();

    QPixmap * item = new QPixmap( QPixmap::fromImage(*(m_attractImage->getImage())));
    m_currentImage = m_scene->addPixmap(*item);
    m_view->updateGeometry();

    m_generatedImageNotSaved = true;
    ui->actionSave->setEnabled(true);
}
*************************************/
