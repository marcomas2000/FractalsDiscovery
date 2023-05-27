#ifndef JULIAFRACTALPARAMS_H
#define JULIAFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class JuliaFractalParams;
}

class JuliaFractalParams : public QDialog
{
    Q_OBJECT
    
public:
    explicit JuliaFractalParams(QWidget *parent = 0);
    ~JuliaFractalParams();

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
    Ui::JuliaFractalParams *ui;
};

#endif // JULIAFRACTALPARAMS_H
