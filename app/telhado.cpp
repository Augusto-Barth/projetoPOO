#include "telhado.h"
#include "janelaprincipal.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

Telhado::Telhado(QGraphicsItem* parent) : Objeto(parent)
{

}

QString Telhado::tipo(){
    return "telhado";
}

bool Telhado::atravessavel(){
    return true;
}

QRectF Telhado::boundingRect() const
{

    return QRectF(0, 0, 208, 192);
}


QPainterPath Telhado::shape() const
{
    QPainterPath path;
    path.addRect(65, 182, 5, 5);
    return path;
}

void Telhado::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawPixmap(0, 0, QPixmap(":/images/apenasTelhado.png"), 0, 0, 0, 0);

}
