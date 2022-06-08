#include "velha.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

Velha::Velha(QGraphicsItem* parent) : Objeto(parent)
{

}

QString Velha::tipo(){
    return "velha";
}

bool Velha::atravessavel(){
    return true;
}

QRectF Velha::boundingRect() const
{
    return QRectF(0, 0, 52, 55);
}


QPainterPath Velha::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 52, 55);

    return path;
}


void Velha::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0, 0, QPixmap(":/images/veiaEsq.png"), 0, 0, 0, 0);

}
