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
    jogador->calculaColisoes();
    bool colidiu = false;
    std::vector<Objeto*>::iterator a;
    std::vector<Objeto*> colisoes = jogador->getColisoes();
    for(a = colisoes.begin(); a != colisoes.end(); a++){
        if((*a)->tipo() == "galinha")
            colidiu = true;
    }
    try{
//        pegar();
    }
    catch(int erro){
        if(erro == -1){

        }
    }
    if(!colidiu)
        janela->colocaTexto("Não tenho telepatia");
    else if(jogador->temRede){
        qDebug() << "pegou";
        jogador->adicionaGalinha();
        janela->colocaTexto("Peguei a galinha");
        this->setVisible(false);
    }
    else{
        janela->colocaTexto("O BICHO CORRE DEMAIS");
        qDebug() << "O BICHO CORRE DEMAIS";
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

void Galinha::advance(int phase){
    if(!phase)
        return;
    passo = (passo+1)%4;
    if(passo == 0)
        setPos(x(),y()+3);
    else if(passo == 1)
        setPos(x(),y()-3);
    else if(passo == 2)
        setPos(x()+3,y());
    else if(passo == 3)
        setPos(x()-3,y());
}
