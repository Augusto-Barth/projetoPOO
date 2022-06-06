#ifndef TELHADO_H
#define TELHADO_H

#include "objeto.h"

class Telhado : public Objeto
{
private:

public:
    Telhado(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
    bool atravessavel();
    bool visivel = true;
};

#endif // TELHADO_H
