#ifndef MAINFRACTALS_H
#define MAINFRACTALS_H

#include <QPointF>
#include <QMainWindow>

namespace Ui {
class MainFractals;
}

enum  class FRACTAL_DOMAIN {
        BIFURCATION = -2,
        SQUARED = -3,
        HCOS = -4,
        EXPONENTIAL = -5,
        POWER4 = -6,
        HENON = -7,
        IKEDA = -8,
        MANDELBROT = -9,
        LYAPUNOV = -10
    };


class JuliaSquaredFractalParams;
class JuliaCosHFractalParams;
class JuliaExpFractalParams;
class JuliaPower4FractalParams;
class MandelbrotFractalParams;
class LyapFractalParams;
class BifurFractalParams;

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
    void createLyapImage(LyapFractalParams * imParams);
    void createBifurImage(BifurFractalParams * imParams);
};

#endif // MAINFRACTALS_H
