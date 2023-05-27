#include <stdio.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "musicxmlreader.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTreeWidget>
#include <QProgressDialog>
#include <QThread>
#include <QTranslator>
#include <QLocale>
#include <QFile>
#include <QDebug>
#include <vector>
#include <set>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString locale = QLocale::system().name();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, tr("About XMLtoKMirck"), tr("XMLtoKMirck Release 0.1 \nCopyright 2010 Marco Mascioli\n\n"));
}

void MainWindow::on_pushButton_clicked()
{
    std::set <int>::iterator voiceIt;

    if (m_fileIn == "")
    {
        QMessageBox::warning(this, tr("XMLtoKMirck"), tr("Please select an input file"));
    }
    else
    {
        if (m_fileOut == "")
        {
            QMessageBox::warning(this, tr("XMLtoKMirck"), tr("Please select an output file"));
        }
        else
        {
            QMessageBox::information(this, tr("XMLtoKMirck"), tr("Exporting XML file:\n")+m_fileIn+tr("\nto\nPDF file:\n")+ m_fileOut);

            char xmlbuf[100];
            m_render = new RenderEngine(m_opts);
            m_render->setFileIn(m_fileIn);
            m_render->start();
            m_render->wait();
            if (m_render->getParserResult() == false)
            {
                sprintf(xmlbuf, "Parse error: %s", m_fileIn.toStdString().c_str());
                QMessageBox::information(this, tr("About XMLtoKMirck"), xmlbuf);
            }
            else
            {
                m_render->designStaff();
                std::vector < std::set <int> > voices = m_render->getNumberOfVoices();
                m_voicesDlg.enableSecondPartFirstVoiceLeftHandButton(false);
                m_voicesDlg.enableSecondPartFirstVoiceRightHandButton(false);
                m_voicesDlg.enableSecondPartSecondVoiceLeftHandButton(false);
                m_voicesDlg.enableSecondPartSecondVoiceRightHandButton(false);
                m_voicesDlg.enableSecondPartThirdVoiceLeftHandButton(false);
                m_voicesDlg.enableSecondPartThirdVoiceRightHandButton(false);
                m_voicesDlg.enableSecondPartFourthVoiceLeftHandButton(false);
                m_voicesDlg.enableSecondPartFourthVoiceRightHandButton(false);
                for (voiceIt=voices[0].begin();voiceIt !=voices[0].end(); voiceIt++ )
                {
                    if ((*voiceIt) <= 1)
                    {
                        m_voicesDlg.enableSecondPartFirstVoiceLeftHandButton(true);
                        m_voicesDlg.enableSecondPartFirstVoiceRightHandButton(true);
                    }
                    if ((*voiceIt) == 2)
                    {
                        m_voicesDlg.enableSecondPartSecondVoiceLeftHandButton(true);
                        m_voicesDlg.enableSecondPartSecondVoiceRightHandButton(true);
                    }
                    if ((*voiceIt) == 3)
                    {
                        m_voicesDlg.enableSecondPartThirdVoiceLeftHandButton(true);
                        m_voicesDlg.enableSecondPartThirdVoiceRightHandButton(true);
                    }
                    if ((*voiceIt) == 4)
                    {
                        m_voicesDlg.enableSecondPartFourthVoiceLeftHandButton(true);
                        m_voicesDlg.enableSecondPartFourthVoiceRightHandButton(true);
                    }
                    if ((*voiceIt) == 5)
                    {
                        m_voicesDlg.enableSecondPartFifthVoiceLeftHandButton(true);
                        m_voicesDlg.enableSecondPartFifthVoiceRightHandButton(true);
                    }
                    if ((*voiceIt) == 6)
                    {
                        m_voicesDlg.enableSecondPartSixthVoiceLeftHandButton(true);
                        m_voicesDlg.enableSecondPartSixthVoiceRightHandButton(true);
                    }
                    if ((*voiceIt) == 7)
                    {
                        m_voicesDlg.enableSecondPartSeventhVoiceLeftHandButton(true);
                        m_voicesDlg.enableSecondPartSeventhVoiceRightHandButton(true);
                    }
                }
                int ret = m_voicesDlg.exec();
                if (ret == QDialog::Accepted)
                {
                    for(int i=0;i<2;i++)
                    {
                        for(int j=0;j<7;j++)
                        {
                            m_handling[i][j] = -1;
                        }
                    }
                    for (voiceIt=voices[0].begin();voiceIt !=voices[0].end(); voiceIt++ )
                    {
                        if ((*voiceIt) <= 1)
                        {
                            m_handling[1][0] = m_voicesDlg.getSecondPartFirstVoiceHand();
                        }
                        if ((*voiceIt) == 2)
                        {
                            m_handling[1][1] = m_voicesDlg.getSecondPartSecondVoiceHand();
                        }
                        if ((*voiceIt) == 3)
                        {
                            m_handling[1][2] = m_voicesDlg.getSecondPartThirdVoiceHand();
                        }
                        if ((*voiceIt) == 4)
                        {
                            m_handling[1][3] = m_voicesDlg.getSecondPartFourthVoiceHand();
                        }
                        if ((*voiceIt) == 5)
                        {
                            m_handling[1][4] = m_voicesDlg.getSecondPartFifthVoiceHand();
                        }
                        if ((*voiceIt) == 6)
                        {
                            m_handling[1][5] = m_voicesDlg.getSecondPartSixthVoiceHand();
                        }
                        if ((*voiceIt) == 7)
                        {
                            m_handling[1][6] = m_voicesDlg.getSecondPartSeventhVoiceHand();
                        }
                    }
                    m_render->setHandling(m_handling);
                    m_render->createPDF(m_fileOut);
                }
                //m_render->debugPartsList();
            }
        }
    }
}

void MainWindow::on_actionOpen_triggered()
{
    m_fileIn = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("MusicXML Files (*.xml)"));
    if (m_fileIn.isEmpty() == false)
    {
            ui->actionSave_As->setEnabled(true);
            ui->label->setText(m_fileIn);
    }
}

void MainWindow::on_actionSave_As_triggered()
{

    m_fileOut = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("KS Midi Files (*.mid)"));

    if (m_fileOut.isEmpty() == false)
    {
        ui->label_2->setText(m_fileOut);
    }
}

void MainWindow::on_actionOptions_triggered()
{
    int ret = m_optionsDlg.exec();
    // 0 ==> papersize: A4
    // 1 ==> papersize: US Letter as it comes from the GUI
    if (ret == QDialog::Accepted)
    {
        //m_opts.papersize = m_optionsDlg.getPaperSize();
        //m_opts.margintop = m_optionsDlg.getMarginTop();
        //m_opts.marginbottom = m_optionsDlg.getMarginBottom();
        //m_opts.marginleft = m_optionsDlg.getMarginLeft();
        //m_opts.marginright = m_optionsDlg.getMarginRight();
        //m_opts.xscalefactor = m_optionsDlg.getXScaleFactor();
        //m_opts.yscalefactor = m_optionsDlg.getYScaleFactor();
        //m_opts.singlewhitekey = m_optionsDlg.getSingleWhiteKey();
        //m_opts.singlewhitekeymultiplier = m_optionsDlg.getSingleWhiteKeyMultiplier();
    }

}
