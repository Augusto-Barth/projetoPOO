#include "casa.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <QtMath>
#include <QKeyEvent>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsView>

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
    return QRectF(-25, -25, 125, 125);
}


QPainterPath Casa::shape() const
{
    QPainterPath path;
//    path.addRect(-20, -20, 40, 40);
    path.moveTo(-20, 80);
    path.lineTo(-20, -20);
    path.lineTo(100, -20);
    path.lineTo(100, 80);
    path.lineTo(91, 80);
    path.lineTo(91, -11);
    path.lineTo(-11, -11);
    path.lineTo(-11, 80);


    return path;
}


void Casa::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor marrom = QColor(150, 75, 0);
    //painter->setBrush(marrom);
    QPainterPath path = shape();
    QPen pen;
    pen.setWidth(0);
    painter->setPen(pen);
    painter->fillPath(path, QBrush(marrom));
//    // bloco
//    painter->drawRect(-20,-20,40,40);
//    painter->setPen(Qt::black);
//    // bordas
//    painter->drawLine(-20.0, -20.0, 20.0, -20.0);
//    painter->drawLine(-20.0, 20.0, 20.0, 20.0);
//    painter->drawLine(-20.0, -20.0, -20.0, 20.0);
//    painter->drawLine(20.0, -20.0, 20.0, 20.0);
//    // linhas do meio
//    painter->drawLine(-10.0, -20.0, -10.0, 20.0);
//    painter->drawLine(0.0, -20.0, 0.0, 20.0);
//    painter->drawLine(10.0, -20.0, 10.0, 20.0);


}
