#include "bifurfractalparams.h"
#include "bifurfractals_ui.h"

BifurFractalParams::BifurFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BifurFractalParams)
{
    ui->setupUi(this);
}

BifurFractalParams::~BifurFractalParams()
{
    delete ui;
}

int BifurFractalParams::getXres()
{
    return ui->spinBox->value();
}

int BifurFractalParams::getYres()
{
    return ui->spinBox_2->value();
}

double BifurFractalParams::getCmin()
{
    return ui->doubleSpinBox->value();
}

double BifurFractalParams::getCmax()
{
    return ui->doubleSpinBox_2->value();
}

int BifurFractalParams::getNoIterationsToExclude()
{
    return ui->doubleSpinBox_6->value();
}

double BifurFractalParams::getInitialPoint()
{
    return ui->doubleSpinBox_5->value();
}
