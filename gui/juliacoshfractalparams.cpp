#include "juliacoshfractalparams.h"
#include "juliacoshfractals_ui.h"

JuliaCosHFractalParams::JuliaCosHFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JuliaCosHFractalParams)
{
    ui->setupUi(this);
}

JuliaCosHFractalParams::~JuliaCosHFractalParams()
{
    delete ui;
}

int JuliaCosHFractalParams::getXres()
{
    return ui->spinBox->value();
}

int JuliaCosHFractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double JuliaCosHFractalParams::getXmin()
{
    return ui->doubleSpinBox->value();
}

double JuliaCosHFractalParams::getYmin()
{
    return ui->doubleSpinBox_2->value();
}

double JuliaCosHFractalParams::getXmax()
{
    return ui->doubleSpinBox_3->value();
}

double JuliaCosHFractalParams::getYmax()
{
    return ui->doubleSpinBox_4->value();
}

int JuliaCosHFractalParams::getMaxiter()
{
    return ui->spinBox_3->value();
}

double JuliaCosHFractalParams::getLx()
{
    return ui->doubleSpinBox_5->value();
}

double JuliaCosHFractalParams::getLy()
{
    return ui->doubleSpinBox_6->value();
}

double JuliaCosHFractalParams::getDivergencyFactor()
{
    return ui->doubleSpinBox_7->value();
}
