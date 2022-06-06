#ifndef VELHA_H
#define VELHA_H

#include "objeto.h"

class Velha : public Objeto
{
private:

public:
    Velha(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
    bool atravessavel();
};

#endif // VELHA_H
