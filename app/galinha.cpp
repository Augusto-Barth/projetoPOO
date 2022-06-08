#include "galinha.h"
#include "jogador.h"
#include "janelaprincipal.h"

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

    return QRectF(-80, -80, 160, 160);
}

QPainterPath Galinha::shape() const
{
    QPainterPath path;
    path.addRect(-80, -80, 160, 160);
    return path;
}

void Galinha::mousePressEvent(QGraphicsSceneMouseEvent *event){

    JanelaPrincipal* janela = JanelaPrincipal::getInstancia();
//    std::vector<std::string> inventario = janela->getJogador()->getInventario();
//    std::vector<std::string>::iterator a;
//    for(a = inventario.begin(); a != inventario.end(); a++){
//        if(*a == "rede")
//            janela->getJogador()->setVisible(false);
//    }

    Jogador* jogador = janela->getJogador();
    try{
        jogador->pegaGalinha();
    }
    catch(int erro){
        if(erro == -1){
            janela->colocaTexto("Não tenho telepatia", 2);
        }
        else if(erro == -2){
            janela->colocaTexto("O BICHO CORRE DEMAIS", 2);
        }
        else if(erro == -3){
            janela->colocaTexto("Pra quê?", 2);
        }
    }

}

void Galinha::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-20, -20, QPixmap(":/images/galinha.png"), 0, 0, 40, 40);

}

void Galinha::advance(int phase){
    if(!phase)
        return;
    passo = (passo+1)%4;
    if(passo == 0)
        setPos(x(),y()+15);
    else if(passo == 1)
        setPos(x(),y()-15);
    else if(passo == 2)
        setPos(x()+15,y());
    else if(passo == 3)
        setPos(x()-15,y());
}
