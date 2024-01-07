#ifndef MAINFRACTALS_H
#define MAINFRACTALS_H

#include <QPointF>
#include <QMainWindow>

namespace Ui {
class MainFractals;
}

enum  class FRACTAL_DOMAIN {
        SQUARED = -2,
        HCOS = -3,
        EXPONENTIAL = -4,
        MANDELBROT = -5,
        SEQUENCE1 = -6,
        POWER4 = -7,
        HENON = -8,
        IKEDA = -9
    };


class JuliaSquaredFractalParams;
class JuliaCosHFractalParams;

class MainFractals : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainFractals(QWidget *parent = 0);
    ~MainFractals();
    
private slots:
    void on_actionExit_triggered();

    void on_actionLoad_triggered();

    void on_actionConfigure_triggered();

    void generationCompleted_triggered();

    void closeEvent(QCloseEvent * event);
signals:
    void generationCompleted();
private:
    Ui::MainFractals *ui;
    void createJuliaSquaredImage(JuliaSquaredFractalParams * imParams);
    void createJuliaCosHImage(JuliaCosHFractalParams * imParams);
};

#endif // MAINFRACTALS_H
