#ifndef GALINHA_H
#define GALINHA_H

#include <QGraphicsItem>
#include "objeto.h"

class Galinha : public Objeto
{
public:
    Galinha(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QString tipo();
    bool atravessavel();
protected:
    void advance(int phase);

private:
    int passo = 0;
};

#endif // GALINHA_H
