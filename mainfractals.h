#ifndef MAINFRACTALS_H
#define MAINFRACTALS_H

#include "paintscene.h"
#include "paintview.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QHBoxLayout>

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

    void on_actionSave_triggered();

    void on_actionNew_2_triggered();
    void closeEvent(QCloseEvent * event);
    void fillCoordinates(QObject *, QMouseEvent *event);
    void showRow();
private:
    void showJuliaImage();
    void showLyapImage();
    void showAttractorImage();
    FractalTypes *m_fracDlg;
    JuliaFractalParams *m_juliaParams;
    LyapFractalParams *m_lyapParams;
    Ui::MainFractals *ui;
    JuliaSet * m_juliaImage;
    LyapSet * m_lyapImage;
    PaintScene* m_scene;
    PaintView* m_view;
    Attractors * m_attractImage;
    QPointF m_mousePos;
    QLineEdit* m_xLine;
    QLineEdit* m_yLine;
    QHBoxLayout* m_hbox1;
    QVBoxLayout* m_vbox12;
    QGraphicsPixmapItem * m_currentImage;
    /**
     * @brief m_generatedImage generated image not saved
     */
    bool m_generatedImageNotSaved;
};

#endif // MAINFRACTALS_H
