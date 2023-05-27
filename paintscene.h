#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QMouseEvent>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = 0);
    //void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

signals:
    //void routingSignal(QObject *, QGraphicsSceneMouseEvent *);

public slots:

};

#endif // PAINTSCENE_H
