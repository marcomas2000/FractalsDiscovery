#include "juliapower4fractalparams.h"
#include "juliapower4fractals_ui.h"

JuliaPower4FractalParams::JuliaPower4FractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JuliaPower4FractalParams)
{
    ui->setupUi(this);
}

JuliaPower4FractalParams::~JuliaPower4FractalParams()
{
    delete ui;
}

int JuliaPower4FractalParams::getXres()
{
    return ui->spinBox->value();
}

int JuliaPower4FractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double JuliaPower4FractalParams::getXmin()
{
    return ui->doubleSpinBox->value();
}

double JuliaPower4FractalParams::getYmin()
{
    return ui->doubleSpinBox_2->value();
}

double JuliaPower4FractalParams::getXmax()
{
    return ui->doubleSpinBox_3->value();
}

double JuliaPower4FractalParams::getYmax()
{
    return ui->doubleSpinBox_4->value();
}

int JuliaPower4FractalParams::getMaxiter()
{
    return ui->spinBox_3->value();
}

double JuliaPower4FractalParams::getLx()
{
    return ui->doubleSpinBox_5->value();
}

double JuliaPower4FractalParams::getLy()
{
    return ui->doubleSpinBox_6->value();
}

double JuliaPower4FractalParams::getDivergencyFactor()
{
    return ui->doubleSpinBox_7->value();
}
