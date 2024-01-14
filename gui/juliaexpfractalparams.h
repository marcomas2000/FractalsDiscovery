#ifndef JULIAEXPFRACTALPARAMS_H
#define JULIAEXPFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class JuliaExpFractalParams;
}

class JuliaExpFractalParams : public QDialog
{
    Q_OBJECT
    
public:
    explicit JuliaExpFractalParams(QWidget *parent = 0);
    virtual ~JuliaExpFractalParams();

    int getXres();
    int getYres();
    double getXmin();
    double getYmin();
    double getXmax();
    double getYmax();
    int getMaxiter();
    double getLx();
    double getLy();
    double getDivergencyFactor();

    
private:
    Ui::JuliaExpFractalParams *ui;
};

#endif // JULIAEXPFRACTALPARAMS_H
