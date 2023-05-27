#include "paintscene.h"
#include <QGraphicsSceneMouseEvent>

PaintScene::PaintScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

//void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
//{
//    emit routingSignal(this, mouseEvent);
//}
