#ifndef MAINFRACTALS_H
#define MAINFRACTALS_H

#include <QPointF>
#include <QMainWindow>

namespace Ui {
class MainFractals;
}

enum  class FRACTAL_DOMAIN {
        BIFURCATION = -2,
        UNISIN = -3,
        UNIPISIN = -4,
        UNI1MINUSSQUARE = -5,
        UNIXCUBED = -6,
        UNIXQUATER = -7,
        UNILYAPLIKE = -8,
        UNITENT = -9,
        SQUARED = -10,
        HCOS = -11,
        EXPONENTIAL = -12,
        POWER4 = -13,
        HENON = -14,
        IKEDA = -15,
        MANDELBROT = -16,
        LYAPUNOV = -17
    };


class JuliaSquaredFractalParams;
class JuliaCosHFractalParams;
class JuliaExpFractalParams;
class JuliaPower4FractalParams;
class MandelbrotFractalParams;
class LyapFractalParams;
class BifurFractalParams;
class BifurSet;

class MainFractals : public QMainWindow
{
    Q_OBJECT
    
public:

    /**
     * @brief Constructor
     * @param parent parent window
     */
    explicit MainFractals(QWidget *parent = 0);

    /**
     * @brief Denstructor
     */
    virtual ~MainFractals();
    
private slots:
    void on_actionExit_triggered();

    void on_actionLoad_triggered();

    void on_actionConfigure_triggered();

    void closeEvent(QCloseEvent * event);
private:
    Ui::MainFractals *ui;
    void createJuliaSquaredImage(JuliaSquaredFractalParams * imParams);
    void createJuliaCosHImage(JuliaCosHFractalParams * imParams);
    void createJuliaExpImage(JuliaExpFractalParams * imParams);
    void createJuliaPower4Image(JuliaPower4FractalParams * imParams);
    void createMandelbrotImage(MandelbrotFractalParams * imParams);
    void createLyapImage(LyapFractalParams * imParams);
    void createBifurImage(BifurFractalParams * imParams, BifurSet * im);

    /**
     * @brief dataGeneration function to generate data in a separate thread
     * @param im function for which data are generated
     */
    void dataGeneration(BifurFractalParams * bifurParams, BifurSet *im);

};

#endif // MAINFRACTALS_H
