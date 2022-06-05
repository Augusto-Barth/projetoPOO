#include "galinheiro.h"

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

Galinheiro::Galinheiro(QGraphicsItem* parent) : Objeto(parent)
{

}

QString Galinheiro::tipo(){
    return "galinheiro";
}

bool Galinheiro::atravessavel(){
    return true;
}

QRectF Galinheiro::boundingRect() const
{

    return QRectF(-40, -40, 80, 80);
}


QPainterPath Galinheiro::shape() const
{
    QPainterPath path;
    path.addRect(-40, -40, 80, 80);
    return path;
}


void Galinheiro::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor marrom = QColor(255, 255, 0);
    painter->setBrush(marrom);
    // bloco
    painter->drawRect(-40, -40, 80, 80);


}
