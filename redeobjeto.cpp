#include "redeobjeto.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QPointF>
#include <QGraphicsView>

RedeObjeto::RedeObjeto(QGraphicsItem* parent) : Objeto(parent)
{

}

QString RedeObjeto::tipo(){
    return "rede";
}

bool RedeObjeto::atravessavel(){
    return true;
}

QRectF RedeObjeto::boundingRect() const
{
    return QRectF(0, 0, 40, 45);
}


QPainterPath RedeObjeto::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 40, 45);

    return path;
}


void RedeObjeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, QPixmap(":/images/rede.png"), 0, 0, 0, 0);
}
