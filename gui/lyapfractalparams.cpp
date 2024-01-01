#include "lyapfractalparams.h"
#include "ui_lyapfractalparams.h"

LyapFractalParams::LyapFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LyapFractalParams)
{
    ui->setupUi(this);
}

LyapFractalParams::~LyapFractalParams()
{
    delete ui;
}

int LyapFractalParams::getXres()
{
    return ui->spinBox->value();
}

int LyapFractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double LyapFractalParams::getXmin()
{
    return ui->doubleSpinBox->value();
}

double LyapFractalParams::getYmin()
{
    return ui->doubleSpinBox_2->value();
}

double LyapFractalParams::getXmax()
{
    return ui->doubleSpinBox_3->value();
}

double LyapFractalParams::getYmax()
{
    return ui->doubleSpinBox_4->value();
}

int LyapFractalParams::getMaxiter()
{
    return ui->spinBox_3->value();
}

double LyapFractalParams::getInitialPoint()
{
    return ui->doubleSpinBox_5->value();
}

QString LyapFractalParams::getLyapSuccession()
{
    return ui->lineEdit->text();
}
