#ifndef COLISOESGERAIS_H
#define COLISOESGERAIS_H

#include "objeto.h"

class ColisoesGerais : public Objeto
{
public:
    ColisoesGerais(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
    bool atravessavel();
};

#endif // COLISOESGERAIS_H
