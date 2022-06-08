#ifndef COLISOESGERAIS_H
#define COLISOESGERAIS_H

#include "objeto.h"

class ColisoesGerais : public Objeto
{
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    ColisoesGerais(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
};

#endif // COLISOESGERAIS_H
