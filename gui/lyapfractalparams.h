#ifndef LYAPFRACTALPARAMS_H
#define LYAPFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class LyapFractalParams;
}

class LyapFractalParams : public QDialog
{
    Q_OBJECT

public:
    explicit LyapFractalParams(QWidget *parent = 0);
    ~LyapFractalParams();

    int getXres();
    int getYres();
    double getXmin();
    double getYmin();
    double getXmax();
    double getYmax();
    int getMaxiter();
    double getInitialPoint();
    QString getLyapSuccession();

private:
    Ui::LyapFractalParams *ui;
};

#endif // LYAPFRACTALPARAMS_H
