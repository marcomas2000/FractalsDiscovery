#include "juliafractalparams.h"
#include "ui_juliafractalparams.h"

JuliaFractalParams::JuliaFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JuliaFractalParams)
{
    ui->setupUi(this);
}

JuliaFractalParams::~JuliaFractalParams()
{
    delete ui;
}

int JuliaFractalParams::getXres()
{
    return ui->spinBox->value();
}

int JuliaFractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double JuliaFractalParams::getXmin()
{
    return ui->doubleSpinBox->value();
}

double JuliaFractalParams::getYmin()
{
    return ui->doubleSpinBox_2->value();
}

double JuliaFractalParams::getXmax()
{
    return ui->doubleSpinBox_3->value();
}

double JuliaFractalParams::getYmax()
{
    return ui->doubleSpinBox_4->value();
}

int JuliaFractalParams::getMaxiter()
{
    return ui->spinBox_3->value();
}

double JuliaFractalParams::getLx()
{
    return ui->doubleSpinBox_5->value();
}

double JuliaFractalParams::getLy()
{
    return ui->doubleSpinBox_6->value();
}

double JuliaFractalParams::getDivergencyFactor()
{
    return ui->doubleSpinBox_7->value();
}
