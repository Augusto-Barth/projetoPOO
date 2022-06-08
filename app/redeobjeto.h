#ifndef REDEOBJETO_H
#define REDEOBJETO_H

#include "objeto.h"

class RedeObjeto : public Objeto
{
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    RedeObjeto(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
};

#endif // REDEOBJETO_H
