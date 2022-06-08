#ifndef CASA_H
#define CASA_H

#include "objeto.h"

class Casa : public Objeto
{
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    Casa(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
    void alteraZ();
    bool aberto = false;
};

#endif // CASA_H
