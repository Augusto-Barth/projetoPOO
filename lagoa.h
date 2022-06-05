#ifndef LAGOA_H
#define LAGOA_H


#include "objeto.h"

class Lagoa : public Objeto
{
private:

public:
    Lagoa(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
    bool atravessavel();
};

#endif // LAGOA_H
