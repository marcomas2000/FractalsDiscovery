#ifndef MAINFRACTALS_H
#define MAINFRACTALS_H

#include "paintscene.h"
#include "paintview.h"
#include <QPointF>
#include <QMainWindow>

namespace Ui {
class MainFractals;
}

class JuliaSet;
class LyapSet;
class Attractors;
class JuliaFractalParams;
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

    //void on_actionSave_triggered();

    void on_actionNew_2_triggered();
    void closeEvent(QCloseEvent * event);
    void fillCoordinates(QObject *, QMouseEvent *event);
    //void showRow();
private:
    Ui::MainFractals *ui;
    QPointF m_mousePos;
    FractalTypes *m_fracDlg;
    /******
    void showJuliaImage();
    void showLyapImage();
    void showAttractorImage();
    JuliaFractalParams *m_juliaParams;
    LyapFractalParams *m_lyapParams;
    JuliaSet * m_juliaImage;
    LyapSet * m_lyapImage;
    Attractors * m_attractImage;
    QGraphicsPixmapItem * m_currentImage;
    */
    PaintScene* m_scene;
    PaintView* m_view;
    /**
     * @brief m_generatedImage generated image not saved
     */
    bool m_generatedImageNotSaved;
};

#endif // MAINFRACTALS_H
