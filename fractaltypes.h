#ifndef FRACTALTYPES_H
#define FRACTALTYPES_H

#include <QDialog>

namespace Ui {
class FractalTypesDlg;
}

class FractalTypes : public QDialog
{
    Q_OBJECT

public:
    explicit FractalTypes(QWidget *parent = 0);
    ~FractalTypes();

    QString getFractalType();

private:
    Ui::FractalTypesDlg *ui;
    QString m_fractalType;
};

#endif // FRACTALTYPES_H
