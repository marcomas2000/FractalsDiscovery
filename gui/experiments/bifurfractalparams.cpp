#include "bifurfractalparams.h"
#include "bifurfractals_ui.h"

BifurFractalParams::BifurFractalParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BifurFractalParams),
    m_windowFunction("")
{
    ui->setupUi(this);
}

BifurFractalParams::~BifurFractalParams()
{
    delete ui;
}

int BifurFractalParams::getXres()
{
    return ui->spinBoxXres->value();
}

int BifurFractalParams::getYres()
{
    return ui->spinBoxYres->value();
}

double BifurFractalParams::getXmin()
{
    return ui->doubleSpinBoxXmin->value();
}

double BifurFractalParams::getXmax()
{
    return ui->doubleSpinBoxXmax->value();
}

double BifurFractalParams::getCmin()
{
    return ui->doubleSpinBoxCmin->value();
}

double BifurFractalParams::getCmax()
{
    return ui->doubleSpinBoxCmax->value();
}

int BifurFractalParams::getNoIterationsToExclude()
{
    return ui->doubleSpinBoxIterDiscarded->value();
}

double BifurFractalParams::getInitialPoint()
{
    return ui->doubleSpinBoxInitialPoint->value();
}

int BifurFractalParams::getMaxIter()
{
    return ui->doubleSpinBoxMaxIter->value();
}

double BifurFractalParams::getStability()
{
    return ui->doubleSpinBoxStability->value();
}
