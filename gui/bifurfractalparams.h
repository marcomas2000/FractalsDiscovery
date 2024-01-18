#ifndef BIFURFRACTALPARAMS_H
#define BIFURFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class BifurFractalParams;
}

class BifurFractalParams : public QDialog
{
    Q_OBJECT

public:
    explicit BifurFractalParams(QWidget *parent = 0);
    ~BifurFractalParams();

    int getXres();
    int getYres();
    double getCmin();
    double getCmax();
    int getNoIterationsToExclude();
    double getInitialPoint();

private:
    Ui::BifurFractalParams *ui;
};

#endif // BIFURFRACTALPARAMS_H
