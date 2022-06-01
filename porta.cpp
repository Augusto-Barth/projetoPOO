#include "porta.h"

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

Porta::Porta(QGraphicsItem* parent) : Objeto(parent)
{

}

QString Porta::tipo(){
    return "porta";
}

bool Porta::atravessavel(){
    return true;
}

QRectF Porta::boundingRect() const
{

    return QRectF(-20, -20, 40, 40);
}


QPainterPath Porta::shape() const
{
    QPainterPath path;
    path.addRect(-20, -20, 40, 40);
    return path;
}


void Porta::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor marrom = QColor(150, 75, 0);
    painter->setBrush(marrom);
    // bloco
    painter->drawRect(-20,-20,40,40);
    painter->setPen(Qt::black);
    // bordas
    painter->drawLine(-20.0, -20.0, 20.0, -20.0);
    painter->drawLine(-20.0, 20.0, 20.0, 20.0);
    painter->drawLine(-20.0, -20.0, -20.0, 20.0);
    painter->drawLine(20.0, -20.0, 20.0, 20.0);
    // linhas do meio
    painter->drawLine(-10.0, -20.0, -10.0, 20.0);
    painter->drawLine(0.0, -20.0, 0.0, 20.0);
    painter->drawLine(10.0, -20.0, 10.0, 20.0);


}
