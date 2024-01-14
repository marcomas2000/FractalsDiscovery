#ifndef JULIASQUAREDFRACTALPARAMS_H
#define JULIASQUAREDFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class JuliaSquaredFractalParams;
}

class JuliaSquaredFractalParams : public QDialog
{
    Q_OBJECT
    
public:
    explicit JuliaSquaredFractalParams(QWidget *parent = 0);
    virtual ~JuliaSquaredFractalParams();

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
    Ui::JuliaSquaredFractalParams *ui;
};

#endif // JULIASQUAREDFRACTALPARAMS_H
