#include "fractaltypes.h"
#include "ui_fractaltypesdlg.h"
#include <QMessageBox>

FractalTypes::FractalTypes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FractalTypesDlg),
    m_fractalType("")
{
    ui->setupUi(this);
}

FractalTypes::~FractalTypes()
{
    delete ui;
}

QString FractalTypes::getFractalType()
{
    m_fractalType = ui->buttonGroup->checkedButton()->text();
    return (m_fractalType);
}
