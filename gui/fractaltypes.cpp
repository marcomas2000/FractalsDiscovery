#include "fractaltypes.h"
#include "fractaltypesdlg_ui.h"
#include <QMessageBox>

FractalTypes::FractalTypes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FractalTypesDlg),
    m_fractalType(-1)
{
    ui->setupUi(this);
}

FractalTypes::~FractalTypes()
{
    delete ui;
}

int FractalTypes::getFractalType()
{
    m_fractalType = ui->buttonGroup->checkedId();
    return (m_fractalType);
}
