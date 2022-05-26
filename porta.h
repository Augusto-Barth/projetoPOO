#ifndef PORTA_H
#define PORTA_H

#include "objeto.h"

class Porta : public Objeto
{
private:

public:
    Porta(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
};

#endif // PORTA_H
