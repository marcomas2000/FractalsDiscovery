#include <QGraphicsSceneMouseEvent>
#include "paintview.h"

PaintView::PaintView(QGraphicsScene * view, QWidget *parent) :
    QGraphicsView(view, parent)
{
}

void PaintView::mousePressEvent(QMouseEvent * e)
{
    // forward to scene (via default view behaviour)
    QGraphicsView::mousePressEvent(e) ;
    emit routingSignal(this, e);
}
