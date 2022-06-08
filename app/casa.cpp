#include "casa.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

Casa::Casa(QGraphicsItem* parent) : Objeto(parent)
{

}

QString Casa::tipo(){
    return "casa";
}

bool Casa::atravessavel(){
    return false;
}

QRectF Casa::boundingRect() const
{
    return QRectF(0, -90, 176, 146);
}

QPainterPath Casa::shape() const
{
    QPainterPath path;
    //path.addRect(0, -90, 176, 146);
    path.moveTo(0, -90);
    path.lineTo(179, -90);
    path.lineTo(179, 56);
    path.lineTo(80, 56);
    path.lineTo(80, 50);
    path.lineTo(178, 50);
    path.lineTo(178, -91);
    path.lineTo(0, -91);
    path.lineTo(0, 56);
    path.lineTo(16, 56);
    path.lineTo(16, 50);
    path.lineTo(0, 50);
    path.lineTo(0, -90);

    QPainterPath pathFechado;
    pathFechado.moveTo(0, -90);
    pathFechado.lineTo(179, -90);
    pathFechado.lineTo(179, 0);
    pathFechado.lineTo(0, 0);
    pathFechado.lineTo(0, -90);
//    path.moveTo(-20, 80);
//    path.lineTo(-20, -20);
//    path.lineTo(100, -20);
//    path.lineTo(100, 80);
//    path.lineTo(91, 80);
//    path.lineTo(91, -11);
//    path.lineTo(-11, -11);
//    path.lineTo(-11, 80);
//    path.addRect(50, 50, 10, 10);
    if(aberto)
        return path;
    else
        return pathFechado;
}


void Casa::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, QPixmap(":/images/parede.png"), 0, 0, 0, 0);
//        QColor azul = QColor(255, 0, 255);
//        QPainterPath path = shape();
//        QPen pen;
//        pen.setWidth(0);
//        painter->setOpacity(0.3);
//        painter->setPen(pen);
//        painter->fillPath(path, QBrush(azul));

}
