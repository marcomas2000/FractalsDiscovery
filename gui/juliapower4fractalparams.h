#ifndef JULIAPOWER4FRACTALPARAMS_H
#define JULIAPOWER4FRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class JuliaPower4FractalParams;
}

class JuliaPower4FractalParams : public QDialog
{
    Q_OBJECT
    
public:
    explicit JuliaPower4FractalParams(QWidget *parent = 0);
    virtual ~JuliaPower4FractalParams();

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
    Ui::JuliaPower4FractalParams *ui;
};

#endif // JULIAPOWER4FRACTALPARAMS_H
