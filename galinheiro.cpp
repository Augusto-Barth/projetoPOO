#include "galinheiro.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

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


}
