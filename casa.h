#ifndef CASA_H
#define CASA_H

#include "objeto.h"

class Casa : public Objeto
{
private:

public:
    Casa(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
    bool atravessavel();
};

#endif // CASA_H
