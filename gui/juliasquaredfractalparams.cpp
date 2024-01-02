#include "juliasquaredfractalparams.h"
#include "juliasquaredfractals_ui.h"

JuliaSquaredFractalParams::JuliaSquaredFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JuliaSquaredFractalParams)
{
    ui->setupUi(this);
}

JuliaSquaredFractalParams::~JuliaSquaredFractalParams()
{
    delete ui;
}

int JuliaSquaredFractalParams::getXres()
{
    return ui->spinBox->value();
}

int JuliaSquaredFractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double JuliaSquaredFractalParams::getXmin()
{
    return ui->doubleSpinBox->value();
}

double JuliaSquaredFractalParams::getYmin()
{
    return ui->doubleSpinBox_2->value();
}

double JuliaSquaredFractalParams::getXmax()
{
    return ui->doubleSpinBox_3->value();
}

double JuliaSquaredFractalParams::getYmax()
{
    return ui->doubleSpinBox_4->value();
}

int JuliaSquaredFractalParams::getMaxiter()
{
    return ui->spinBox_3->value();
}

double JuliaSquaredFractalParams::getLx()
{
    return ui->doubleSpinBox_5->value();
}

double JuliaSquaredFractalParams::getLy()
{
    return ui->doubleSpinBox_6->value();
}

double JuliaSquaredFractalParams::getDivergencyFactor()
{
    return ui->doubleSpinBox_7->value();
}
