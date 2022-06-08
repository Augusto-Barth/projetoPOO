#ifndef GALINHA_H
#define GALINHA_H

#include <QGraphicsItem>
#include "objeto.h"

class Galinha : public Objeto
{
private:
    int passo = 0;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    Galinha(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
protected:
    void advance(int phase);

};

#endif // GALINHA_H
