#ifndef TELHADO_H
#define TELHADO_H

#include "objeto.h"

class Telhado : public Objeto
{
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    Telhado(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
    bool visivel = true;
};

#endif // TELHADO_H
