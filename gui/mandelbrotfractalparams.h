#ifndef MANDELBROTFRACTALPARAMS_H
#define MANDELBROTFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class MandelbrotFractalParams;
}

class MandelbrotFractalParams : public QDialog
{
    Q_OBJECT
    
public:
    explicit MandelbrotFractalParams(QWidget *parent = 0);
    virtual ~MandelbrotFractalParams();

    int getXres();
    int getYres();
    double getXmin();
    double getYmin();
    double getXmax();
    double getYmax();
    int getMaxiter();
    double getDivergencyFactor();

    
private:
    Ui::MandelbrotFractalParams *ui;
};

#endif // MANDELBROTFRACTALPARAMS_H
