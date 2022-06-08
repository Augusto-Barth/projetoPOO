#ifndef LAGOA_H
#define LAGOA_H

#include "objeto.h"

class Lagoa : public Objeto
{
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    Lagoa(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
};

#endif // LAGOA_H
