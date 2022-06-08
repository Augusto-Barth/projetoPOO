#include "porta.h"
#include "janelaprincipal.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

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

    return QRectF(0, 0, 208, 192);
}


QPainterPath Porta::shape() const
{
    QPainterPath path;
    path.addRect(65, 182, 5, 5);
    return path;
}

void Porta::alteraVisibilidade(){
    JanelaPrincipal* janela = JanelaPrincipal::getInstancia();
    Casa* casa = janela->getCasa();
    Telhado* telhado = janela->getTelhado();
    if(!casa->aberto){
        casa->setZValue(2);
        casa->aberto = true;
        setOpacity(0);
        telhado->setOpacity(0);
    }
    else{
        casa->setZValue(0);
        casa->aberto = false;
        setOpacity(1);
        telhado->setOpacity(1);
    }
}

void Porta::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawPixmap(40, 140, QPixmap(":/images/apenasPorta.png"), 0, 0, 0, 0);

}
