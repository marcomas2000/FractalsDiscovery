#include "mainfractals.h"
#include "ui_mainfractals.h"
#include "fractaltypes.h"
#include "juliasquared.h"
#include "juliacosh.h"
#include "juliaexp.h"
#include "attracthenon.h"
#include "attractikeda.h"
#include "juliapower4.h"
#include "juliafractalparams.h"
#include "lyapfractalparams.h"
#include "mandelbrot.h"
#include "lyapunov.h"
#include <QFileDialog>
#include <QPixmap>
#include <QImageWriter>
#include <QMessageBox>
#include <QFile>
#include <QXmlStreamWriter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

MainFractals::MainFractals(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainFractals),
    m_fracDlg(new FractalTypes(this)),
    m_juliaImage(0),
    m_scene(0),
    m_view(0),
    m_hbox1(0),
    m_xLine(0),
    m_yLine(0),
    m_mousePos(QPointF(0,0)),
    m_vbox12(new QVBoxLayout()),
    m_juliaParams (new JuliaFractalParams(this)),
    m_lyapParams (new LyapFractalParams(this)),
    m_generatedImageNotSaved(false),
    m_currentImage(0)
{
    ui->setupUi(this);
    m_scene = new PaintScene;
    m_view = new PaintView(m_scene);
    connect(m_view, SIGNAL(routingSignal(QObject *, QMouseEvent *)), this, SLOT(fillCoordinates(QObject *, QMouseEvent *)));
    m_hbox1 = new QHBoxLayout();
    QVBoxLayout* vbox11 = new QVBoxLayout();
    QHBoxLayout* hbox111 = new QHBoxLayout();
    QHBoxLayout* hbox112 = new QHBoxLayout();
    QLabel * xlabel = new QLabel("X:");
    QLabel * ylabel = new QLabel("Y:");
    m_xLine = new QLineEdit();
    m_xLine->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_xLine->setMaxLength(9);
    m_xLine->setReadOnly(true);
    m_xLine->setAlignment(Qt::AlignRight);
    m_yLine = new QLineEdit();
    m_yLine->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_yLine->setMaxLength(9);
    m_yLine->setReadOnly(true);
    m_yLine->setAlignment(Qt::AlignRight);
    hbox111->addWidget(xlabel);
    hbox111->addWidget(m_xLine);
    vbox11->addLayout(hbox111);
    hbox112->addWidget(ylabel);
    hbox112->addWidget(m_yLine);
    vbox11->addLayout(hbox112);
    vbox11->setSizeConstraint(QLayout::SetFixedSize);
    vbox11->addSpacing(600);
    m_hbox1->addLayout(vbox11);
    m_vbox12->addWidget(m_view);
    m_hbox1->addLayout(m_vbox12);

    ui->frame->setLayout(m_hbox1);
}

MainFractals::~MainFractals()
{
    if(m_juliaImage != 0)
    {
        delete m_juliaImage;
        m_juliaImage = 0;
    }
    delete ui;
}

void MainFractals::on_actionExit_triggered()
{
    if (m_generatedImageNotSaved == true)
    {
        QMessageBox::StandardButton answer = QMessageBox::question(this, "Fractals", "The document has been modified. Do you want to save it?",
                             QMessageBox::StandardButtons( QMessageBox::Yes | QMessageBox::No ), QMessageBox::Yes);
        if(answer == QMessageBox::Yes)
        {
            on_actionSave_triggered();
        }
    }
    exit(0);
}

void MainFractals::closeEvent(QCloseEvent *event)
{
    if (m_generatedImageNotSaved == true)
    {
        QMessageBox::StandardButton answer = QMessageBox::question(this, "Fractals", "The document has been modified. Do you want to save it?",
                             QMessageBox::StandardButtons( QMessageBox::Yes | QMessageBox::No ), QMessageBox::Yes);
        if(answer == QMessageBox::Yes)
        {
            on_actionSave_triggered();
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
    exit(0);
}
void MainFractals::on_actionSave_triggered()
{
    QString fileOut = QFileDialog::getSaveFileName(this, tr("Save File"), "");

    if (fileOut.isEmpty() == false)
    {
        if((m_fracDlg->getFractalType() == "Squared")
                || (m_fracDlg->getFractalType() == "HyperbolicCos")
                || (m_fracDlg->getFractalType() == "Exponential")
                || (m_fracDlg->getFractalType() == "Mandelbrot"))
        {
            QImageWriter writer(fileOut, "png");
            writer.setText("Author", "Marco Mascioli");
            writer.write(*(m_juliaImage->getImage()));

            QString fileNameXML = fileOut + ".xml";
            QFile output;
            output.setFileName(fileNameXML);
            output.open(QIODevice::WriteOnly);
            QXmlStreamWriter stream(&output);
            stream.setAutoFormatting(true);
            stream.writeStartDocument();
            stream.writeStartElement("Fractal");
            stream.writeTextElement("FractalType", m_fracDlg->getFractalType());
            stream.writeStartElement("ImageResolution");
            stream.writeTextElement("Xres", QString::number(m_juliaParams->getXres()));
            stream.writeTextElement("Yres", QString::number(m_juliaParams->getYres()));
            stream.writeEndElement();
            stream.writeStartElement("FunctionDomain");
            stream.writeStartElement("TopLeftCorner");
            stream.writeTextElement("Xmin", QString::number(m_juliaParams->getXmin(), 'g'));
            stream.writeTextElement("Ymin", QString::number(m_juliaParams->getYmin(), 'g'));
            stream.writeEndElement();
            stream.writeStartElement("BottomRight");
            stream.writeTextElement("Xmax", QString::number(m_juliaParams->getXmax(), 'g'));
            stream.writeTextElement("Ymax", QString::number(m_juliaParams->getYmax(), 'g'));
            stream.writeEndElement();
            stream.writeEndElement();
            stream.writeTextElement("MaxIterations", QString::number(m_juliaParams->getMaxiter()));
            stream.writeTextElement("XDeviation", QString::number(m_juliaParams->getLx(), 'g'));
            stream.writeTextElement("YDeviation", QString::number(m_juliaParams->getLy(), 'g'));
            stream.writeTextElement("DivergencyFactor", QString::number(m_juliaParams->getDivergencyFactor(), 'g'));
            stream.writeEndElement(); // Fractal
            stream.writeEndDocument();
            output.close();
        }
        else if (m_fracDlg->getFractalType() == "Sequence1")
        {
            QImageWriter writer(fileOut, "png");
            writer.setText("Author", "Marco Mascioli");
            writer.write(*(m_lyapImage->getImage()));

            QString fileNameXML = fileOut + ".xml";
            QFile output;
            output.setFileName(fileNameXML);
            output.open(QIODevice::WriteOnly);
            QXmlStreamWriter stream(&output);
            stream.setAutoFormatting(true);
            stream.writeStartDocument();
            stream.writeStartElement("Fractal");
            stream.writeTextElement("FractalType", m_fracDlg->getFractalType());
            stream.writeStartElement("ImageResolution");
            stream.writeTextElement("Xres", QString::number(m_lyapParams->getXres()));
            stream.writeTextElement("Yres", QString::number(m_lyapParams->getYres()));
            stream.writeEndElement();
            stream.writeStartElement("FunctionDomain");
            stream.writeStartElement("TopLeftCorner");
            stream.writeTextElement("Xmin", QString::number(m_lyapParams->getXmin(), 'g'));
            stream.writeTextElement("Ymin", QString::number(m_lyapParams->getYmin(), 'g'));
            stream.writeEndElement();
            stream.writeStartElement("BottomRight");
            stream.writeTextElement("Xmax", QString::number(m_lyapParams->getXmax(), 'g'));
            stream.writeTextElement("Ymax", QString::number(m_lyapParams->getYmax(), 'g'));
            stream.writeEndElement();
            stream.writeEndElement();
            stream.writeTextElement("MaxIterations", QString::number(m_lyapParams->getMaxiter()));
            stream.writeTextElement("InitialPoint", QString::number(m_lyapParams->getInitialPoint()));
            stream.writeTextElement("Succession", m_lyapParams->getLyapSuccession());
            stream.writeEndElement(); // Fractal
            stream.writeEndDocument();
            output.close();
        }
        else if ((m_fracDlg->getFractalType() == "Henon")
            || (m_fracDlg->getFractalType() == "Ikeda"))
        {
            QImageWriter writer(fileOut, "png");
            writer.setText("Author", "Marco Mascioli");
            writer.write(*(m_attractImage->getImage()));

            QString fileNameXML = fileOut + ".xml";
            QFile output;
            output.setFileName(fileNameXML);
            output.open(QIODevice::WriteOnly);
            QXmlStreamWriter stream(&output);
            stream.setAutoFormatting(true);
            stream.writeStartDocument();
            stream.writeStartElement("Fractal");
            stream.writeTextElement("FractalType", m_fracDlg->getFractalType());
            stream.writeStartElement("ImageResolution");
            stream.writeTextElement("Xres", QString::number(m_juliaParams->getXres()));
            stream.writeTextElement("Yres", QString::number(m_juliaParams->getYres()));
            stream.writeEndElement();
            stream.writeStartElement("FunctionDomain");
            stream.writeStartElement("TopLeftCorner");
            stream.writeTextElement("Xmin", QString::number(m_juliaParams->getXmin(), 'g'));
            stream.writeTextElement("Ymin", QString::number(m_juliaParams->getYmin(), 'g'));
            stream.writeEndElement();
            stream.writeStartElement("BottomRight");
            stream.writeTextElement("Xmax", QString::number(m_juliaParams->getXmax(), 'g'));
            stream.writeTextElement("Ymax", QString::number(m_juliaParams->getYmax(), 'g'));
            stream.writeEndElement();
            stream.writeEndElement();
            stream.writeTextElement("MaxIterations", QString::number(m_juliaParams->getMaxiter()));
            stream.writeTextElement("XDeviation", QString::number(m_juliaParams->getLx(), 'g'));
            stream.writeTextElement("YDeviation", QString::number(m_juliaParams->getLy(), 'g'));
            stream.writeTextElement("DivergencyFactor", QString::number(m_juliaParams->getDivergencyFactor(), 'g'));
            stream.writeEndElement(); // Fractal
            stream.writeEndDocument();
            output.close();
        }
        m_generatedImageNotSaved = false;
    }
    ui->actionSave->setEnabled(false);
    delete m_juliaImage;
    m_juliaImage = 0;
}

void MainFractals::on_actionNew_2_triggered()
{
    int ret, ret2;
    if (m_generatedImageNotSaved == true)
    {
        QMessageBox::StandardButton answer = QMessageBox::question(this, "Fractals", "The document has been modified. Do you want to save it?",
                             QMessageBox::StandardButtons( QMessageBox::Yes | QMessageBox::No ), QMessageBox::Yes);
        if(answer == QMessageBox::Yes)
        {
            on_actionSave_triggered();
        }
    }
    ret = m_fracDlg->exec();
    if (ret == QDialog::Accepted)
    {
        if(m_fracDlg->getFractalType() == "Squared")
        {
            ret2 = m_juliaParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_juliaImage = new JuliaSquared();
                showJuliaImage();
            }
        }
        else if (m_fracDlg->getFractalType() == "HyperbolicCos")
        {
            ret2 = m_juliaParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_juliaImage = new JuliaCosH();
                showJuliaImage();
            }
        }
        else if (m_fracDlg->getFractalType() == "Exponential")
        {
            ret2 = m_juliaParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_juliaImage = new JuliaExp();
                showJuliaImage();
            }
        }
        else if (m_fracDlg->getFractalType() == "Mandelbrot")
        {
            ret2 = m_juliaParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_juliaImage = new Mandelbrot();
                showJuliaImage();
            }
        }
        else if (m_fracDlg->getFractalType() == "Sequence1")
        {
            ret2 = m_lyapParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_lyapImage = new Lyapunov();
                showLyapImage();
            }
        }
        else if (m_fracDlg->getFractalType() == "Power4")
        {
            ret2 = m_juliaParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_juliaImage = new JuliaPower4();
                showJuliaImage();
            }
        }
        else if (m_fracDlg->getFractalType() == "Henon")
        {
            ret2 = m_juliaParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_attractImage = new AttractHenon();
                showAttractorImage();
            }
        }
        else if (m_fracDlg->getFractalType() == "Ikeda")
        {
            ret2 = m_juliaParams->exec();
            if (ret2 == QDialog::Accepted)
            {
                m_attractImage = new AttractIkeda();
                showAttractorImage();
            }
        }
        else
        {
        }
    }
}

void MainFractals::showRow()
{
    static QPixmap * item = new QPixmap( QPixmap::fromImage(*(m_lyapImage->getImage())));
    m_currentImage = m_scene->addPixmap(*item);
    m_view->updateGeometry();

}

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

void MainFractals::showJuliaImage()
{
    if (m_currentImage != 0)
    {
        delete m_currentImage;
    }
    m_juliaImage->setXres(m_juliaParams->getXres());
    m_juliaImage->setYres(m_juliaParams->getYres());
    m_juliaImage->setXmin(m_juliaParams->getXmin());
    m_juliaImage->setYmin(m_juliaParams->getYmin());
    m_juliaImage->setXmax(m_juliaParams->getXmax());
    m_juliaImage->setYmax(m_juliaParams->getYmax());
    m_juliaImage->setMaxiter(m_juliaParams->getMaxiter());
    m_juliaImage->setLx(m_juliaParams->getLx());
    m_juliaImage->setLy(m_juliaParams->getLy());
    m_juliaImage->setDivergencyFactor(m_juliaParams->getDivergencyFactor());

    m_juliaImage->createJulia();

    QPixmap * item = new QPixmap( QPixmap::fromImage(*(m_juliaImage->getImage())));
    m_currentImage = m_scene->addPixmap(*item);
    m_view->updateGeometry();

    m_generatedImageNotSaved = true;
    ui->actionSave->setEnabled(true);
}

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


void MainFractals::fillCoordinates(QObject *, QMouseEvent * event)
{
    m_mousePos = event->pos();
    m_xLine->setText(QString::number((m_mousePos.x()/(double)m_scene->width()*(m_juliaParams->getXmax()-m_juliaParams->getXmin()))+m_juliaParams->getXmin()));
    m_yLine->setText(QString::number((m_mousePos.y()/(double)m_scene->height()*(m_juliaParams->getYmax()-m_juliaParams->getYmin()))+m_juliaParams->getYmin()));
}
