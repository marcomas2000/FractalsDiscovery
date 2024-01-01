#ifndef FRACTALTYPES_H
#define FRACTALTYPES_H

#include <QDialog>

namespace Ui {
class FractalTypesDlg;
}

enum  class FRACTAL_DOMAIN {
        SQUARED = -2,
        HYPERBOLICCOS = -3,
        EXPONENTIAL = -4,
        MANDELBROT = -5,
        SEQUENCE1 = -6,
        POWER4 = -7,
        HENON = -8,
        IKEDA = -9
    };


class FractalTypes : public QDialog
{
    Q_OBJECT
public:
    explicit FractalTypes(QWidget *parent = 0);
    ~FractalTypes();

    int getFractalType();

private:
    Ui::FractalTypesDlg *ui;
    int m_fractalType;
};

#endif // FRACTALTYPES_H
