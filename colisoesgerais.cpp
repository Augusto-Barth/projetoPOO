#include "colisoesgerais.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

ColisoesGerais::ColisoesGerais(QGraphicsItem* parent) : Objeto(parent)
{

}

QString ColisoesGerais::tipo(){
    return "colisoesgerais";
}

bool ColisoesGerais::atravessavel(){
    return false;
}

QRectF ColisoesGerais::boundingRect() const
{

    return QRectF(0, 0, 1780, 1220);
}


QPainterPath ColisoesGerais::shape() const
{
    QPainterPath path;

    //floresta
    path.moveTo(0, 0);
    path.lineTo(1780, 0);
    path.lineTo(1780, 140);
    path.lineTo(940, 140);
    path.lineTo(940, 70);
    path.lineTo(810, 70);
    path.lineTo(810, 140);
    path.lineTo(0, 140);
    path.lineTo(0, 0);
    path.closeSubpath();
    //path.addRect(1350, 500, 50, 50);

    //muros perto da casa
    path.moveTo(1370, 530);
    path.lineTo(1370, 510);
    path.lineTo(1350, 510);
    path.lineTo(1350, 415);
    path.lineTo(1490, 415);
    path.lineTo(1490, 620);
    path.lineTo(1380, 620);
    //voltando
    path.lineTo(1380, 615);
    path.lineTo(1485, 615);
    path.lineTo(1485, 415);
    path.lineTo(1350, 415);
    path.lineTo(1350, 510);
    path.lineTo(1370, 510);
    path.closeSubpath();

    //cerca perto da casa
    path.moveTo(1000, 490);
    path.lineTo(1145, 490);
    path.closeSubpath();

    //galinheiro
    path.addRect(1104, 835, 140, 140);

    return path;
}


void ColisoesGerais::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    QColor azul = QColor(255, 0, 255);
//    //painter->setBrush(marrom);
//    QPainterPath path = shape();
//    QPen pen;
//    pen.setWidth(0);
//    painter->setOpacity(0.3);
//    painter->setPen(pen);
//    painter->fillPath(path, QBrush(azul));

}
