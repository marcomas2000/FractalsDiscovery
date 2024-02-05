#ifndef JULIACOSHFRACTALPARAMS_H
#define JULIACOSHFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class JuliaCosHFractalParams;
}

class JuliaCosHFractalParams : public QDialog
{
    Q_OBJECT
    
public:
    explicit JuliaCosHFractalParams(QWidget *parent = 0);
    virtual ~JuliaCosHFractalParams();

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
    Ui::JuliaCosHFractalParams *ui;
};

#endif // JULIACOSHFRACTALPARAMS_H
