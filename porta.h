#ifndef PORTA_H
#define PORTA_H

#include "objeto.h"

class Porta : public Objeto
{
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    Porta(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
    void alteraVisibilidade();
};

#endif // PORTA_H
