#include "lagoa.h"

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
    return QRectF(-25, -25, 125, 125);
}


QPainterPath Lagoa::shape() const
{
    QPainterPath path;
    path.addRect(-20, -20, 40, 40);
//    path.moveTo(-20, 80);
//    path.lineTo(-20, -20);
//    path.lineTo(100, -20);
//    path.lineTo(100, 80);
//    path.lineTo(91, 80);
//    path.lineTo(91, -11);
//    path.lineTo(-11, -11);
//    path.lineTo(-11, 80);
//    path.addRect(50, 50, 10, 10);


    return path;
}


void Lagoa::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor azul = QColor(0, 0, 255);
    //painter->setBrush(marrom);
    QPainterPath path = shape();
    QPen pen;
    pen.setWidth(0);
    painter->setPen(pen);
    painter->fillPath(path, QBrush(azul));
//    painter->setBrush(marrom);
//    painter->drawRect(50, 50, 10, 10);


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
