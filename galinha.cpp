    #include "galinha.h"
#include "jogador.h"

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
#include <QList>
#include <QObject>

Galinha::Galinha(QGraphicsItem* parent) : Objeto(parent)
{

}

QString Galinha::tipo(){
    return "galinha";
}

bool Galinha::atravessavel(){
    return true;
}

QRectF Galinha::boundingRect() const
{

    return QRectF(-20, -20, 40, 40);
}

QPainterPath Galinha::shape() const
{
    QPainterPath path;
    path.addRect(-20, -20, 40, 40);
    return path;
}

void Galinha::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug() << "pegou";
    this->setVisible(false);
    QList<QObject*> g_items = scene()->children();
    for(int i = 0; i < g_items.length(); i++)
    {
        QGraphicsItem *selected_object = dynamic_cast<Jogador*>(g_items[i]);
        if(selected_object)
        {
            qDebug() << "jogador";
            selected_object->setVisible(false);
        }
    }
}

void Galinha::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    QColor marrom = QColor(150, 75, 0);
//    painter->setBrush(marrom);
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
    painter->drawPixmap(-20, -20, QPixmap(":/images/galinha.png"), 0, 0, 40, 40);

}
