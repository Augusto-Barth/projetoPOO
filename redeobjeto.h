#ifndef REDEOBJETO_H
#define REDEOBJETO_H

#include "objeto.h"

class RedeObjeto : public Objeto
{
public:
    RedeObjeto(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
    bool atravessavel();
};

#endif // REDEOBJETO_H
