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
        POWER4 = -5,
        HENON = -6,
        IKEDA = -7,
        MANDELBROT = -8,
        SEQUENCE1 = -9
    };


class JuliaSquaredFractalParams;
class JuliaCosHFractalParams;
class JuliaExpFractalParams;
class JuliaPower4FractalParams;
class MandelbrotFractalParams;

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
    void createJuliaExpImage(JuliaExpFractalParams * imParams);
    void createJuliaPower4Image(JuliaPower4FractalParams * imParams);
    void createMandelbrotImage(MandelbrotFractalParams * imParams);
};

#endif // MAINFRACTALS_H
