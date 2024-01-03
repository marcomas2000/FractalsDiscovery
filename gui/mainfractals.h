#ifndef MAINFRACTALS_H
#define MAINFRACTALS_H

#include <QPointF>
#include <QMainWindow>

namespace Ui {
class MainFractals;
}

class JuliaSet;
class LyapSet;
class Attractors;
class JuliaSquaredFractalParams;
class LyapFractalParams;
class FractalTypes;

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

    //void on_actionNew_triggered();
    void closeEvent(QCloseEvent * event);
private:
    Ui::MainFractals *ui;
    /******
    void showJuliaImage();
    void showLyapImage();
    void showAttractorImage();
    LyapFractalParams *m_lyapParams;
    JuliaSet * m_juliaImage;
    LyapSet * m_lyapImage;
    Attractors * m_attractImage;
    QGraphicsPixmapItem * m_currentImage;
    */
};

#endif // MAINFRACTALS_H
