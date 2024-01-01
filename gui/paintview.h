#ifndef PAINTVIEW_H
#define PAINTVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class PaintView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PaintView(QGraphicsScene * view, QWidget *parent = 0);
    void mousePressEvent(QMouseEvent * e);
    QPoint getPos();
signals:
    void routingSignal(QObject *, QMouseEvent *);

public slots:

private:

};

#endif // PAINTVIEW_H
