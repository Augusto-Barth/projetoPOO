#include "lagoa.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

Lagoa::Lagoa(QGraphicsItem* parent) : Objeto(parent)
{

}

QString Lagoa::tipo(){
    return "lagoa";
}

bool Lagoa::atravessavel(){
    return true;
}

QRectF Lagoa::boundingRect() const
{
    return QRectF(0, 0, 560, 1250);
}


QPainterPath Lagoa::shape() const
{
    QPainterPath path;
//    path.addRect(-20, -20, 40, 40);
    path.moveTo(0, 250);
    path.lineTo(285, 335);
    path.lineTo(140, 400);
    path.lineTo(170, 490);
//    path.lineTo(150, 510);
    path.lineTo(310, 860);
    path.lineTo(470, 980);
    path.lineTo(580, 1250);
    path.lineTo(0, 1250);
    path.lineTo(0, 220);
    return path;
}


void Lagoa::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    QColor azul = QColor(255, 0, 255);
//    QPainterPath path = shape();
//    QPen pen;
//    pen.setWidth(0);
//    painter->setOpacity(0.3);
//    painter->setPen(pen);
//    painter->fillPath(path, QBrush(azul));

}
