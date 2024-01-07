#include "juliaexpfractalparams.h"
#include "juliaexpfractals_ui.h"

JuliaExpFractalParams::JuliaExpFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JuliaExpFractalParams)
{
    ui->setupUi(this);
}

JuliaExpFractalParams::~JuliaExpFractalParams()
{
    delete ui;
}

int JuliaExpFractalParams::getXres()
{
    return ui->spinBox->value();
}

int JuliaExpFractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double JuliaExpFractalParams::getXmin()
{
    return ui->doubleSpinBox->value();
}

double JuliaExpFractalParams::getYmin()
{
    return ui->doubleSpinBox_2->value();
}

double JuliaExpFractalParams::getXmax()
{
    return ui->doubleSpinBox_3->value();
}

double JuliaExpFractalParams::getYmax()
{
    return ui->doubleSpinBox_4->value();
}

int JuliaExpFractalParams::getMaxiter()
{
    return ui->spinBox_3->value();
}

double JuliaExpFractalParams::getLx()
{
    return ui->doubleSpinBox_5->value();
}

double JuliaExpFractalParams::getLy()
{
    return ui->doubleSpinBox_6->value();
}

double JuliaExpFractalParams::getDivergencyFactor()
{
    return ui->doubleSpinBox_7->value();
}
