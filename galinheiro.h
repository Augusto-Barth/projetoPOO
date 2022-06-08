#ifndef GALINHEIRO_H
#define GALINHEIRO_H

#include "objeto.h"

class Galinheiro : public Objeto
{
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    Galinheiro(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
};

#endif // GALINHEIRO_H
