#include "mandelbrotfractalparams.h"
#include "mandelbrotfractals_ui.h"

MandelbrotFractalParams::MandelbrotFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MandelbrotFractalParams)
{
    ui->setupUi(this);
}

MandelbrotFractalParams::~MandelbrotFractalParams()
{
    delete ui;
}

int MandelbrotFractalParams::getXres()
{
    return ui->spinBox->value();
}

int MandelbrotFractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double MandelbrotFractalParams::getXmin()
{
    return ui->doubleSpinBox->value();
}

double MandelbrotFractalParams::getYmin()
{
    return ui->doubleSpinBox_2->value();
}

double MandelbrotFractalParams::getXmax()
{
    return ui->doubleSpinBox_3->value();
}

double MandelbrotFractalParams::getYmax()
{
    return ui->doubleSpinBox_4->value();
}

int MandelbrotFractalParams::getMaxiter()
{
    return ui->spinBox_3->value();
}

double MandelbrotFractalParams::getDivergencyFactor()
{
    return ui->doubleSpinBox_7->value();
}
