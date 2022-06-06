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
    return QRectF(-20, -20, 40, 40);
}


QPainterPath RedeObjeto::shape() const
{
    QPainterPath path;
    path.addRect(-20, -20, 40, 40);

    return path;
}


void RedeObjeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor cor = QColor(150, 75, 150);
    //painter->setBrush(marrom);
    QPainterPath path = shape();
    QPen pen;
    pen.setWidth(0);
    painter->setPen(pen);
    painter->fillPath(path, QBrush(cor));

}
