#include "jogador.h"
#include "porta.h"
#include "objeto.h"

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
#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QCursor>

constexpr qreal Pi = M_PI;
constexpr qreal TwoPi = 2 * M_PI;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

QString Jogador::tipo(){
    return "jogador";
}

bool Jogador::atravessavel(){
    return false;
}

//! [0]
Jogador::Jogador(QGraphicsItem* parent) : Objeto(parent), color(255, 0, 0)
{
    setRotation(0);
}
//! [0]

void Jogador::mousePressEvent(QGraphicsSceneMouseEvent *event){

}

void QGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
//    qDebug() << "asdqwe";
//    auto pontoMouse = event->pos();
//    qDebug() << pontoMouse.x() << " e " << pontoMouse.y();
//    qreal pitagoras = qSqrt(qPow(pontoMouse.x(), 2) + qPow(pontoMouse.y(), 2));
//    setRotation(pitagoras/pontoMouse.x());
//    update();
}

//! [1]
QRectF Jogador::boundingRect() const
{

    return QRectF(-10, -10, 20, 20);
}
//! [1]

//! [2]
QPainterPath Jogador::shape() const
{
    QPainterPath path;
    path.addRect(-10, -10, 20, 20);
    return path;
}
//! [2]

void Jogador::calculaColisoes(){
    QVector<QGraphicsItem*> vect = scene()->collidingItems(this).toVector();
    colisoes.erase(colisoes.begin(), colisoes.end());
    for(int i = 0; i < vect.size(); i++){
        if(vect[i] != this){
            Objeto* check = dynamic_cast<Objeto*>(vect[i]);
            if(check != nullptr){
                colisoes.push_back(check);
            }
        }
    }
}

//void Jogador::keyPressEvent(QKeyEvent *event){
//    if(event->key() == Qt::Key_A){
//        if(x()-10-20 >= 0)
//            setPos(x()-10, y());
//    }
//    else if(event->key() == Qt::Key_D){
//        if(x()+10+20 <= scene()->width())
//            setPos(x()+10, y());
//    }
//    else if(event->key() == Qt::Key_W){
//        if(y()-10-20 >= 0)
//            setPos(x(), y()-10);
//    }
//    else if(event->key() == Qt::Key_S){
//        if(y()+10+20 <= scene()->height())
//            setPos(x(), y()+10);
//    }
//    else if(event->key() == Qt::Key_Q){
//        calculaColisoes();
//        std::vector<Objeto*>::iterator a;
//        for(a = colisoes.begin(); a != colisoes.end(); a++){
//            qDebug() << (*a)->tipo();
//        }
//    }
//}


//        colisao.moveTo(colisao.currentPosition().x()-20-passo, colisao.currentPosition().y());
//        calculaColisoes();
//        std::vector<Objeto*>::iterator a;
//        for(a = colisoes.begin(); a != colisoes.end(); a++){
//            colidiu = true;
//        }
//        colisao.moveTo(colisao.currentPosition().x()+20+passo, colisao.currentPosition().y());
//        if(!colidiu)
//            setPos(x()-passo, y());

void Jogador::keyPressEvent(QKeyEvent *event){
    int passo = 10;
    bool colidiu = false;
    if(event->key() == Qt::Key_A){
        if(x()-passo-10 >= 0){
            setPos(x()-passo, y());
            calculaColisoes();
            std::vector<Objeto*>::iterator a;
            for(a = colisoes.begin(); a != colisoes.end(); a++){
                if(!(*a)->atravessavel())
                    colidiu = true;
            }
            if(colidiu)
                setPos(x()+passo, y());
        }
    }
    else if(event->key() == Qt::Key_D){
        if(x()+passo+10 <= scene()->width()){
            setPos(x()+passo, y());
            calculaColisoes();
            std::vector<Objeto*>::iterator a;
            for(a = colisoes.begin(); a != colisoes.end(); a++){
                if(!(*a)->atravessavel())
                    colidiu = true;
            }
            if(colidiu)
                setPos(x()-passo, y());
        }
    }
    else if(event->key() == Qt::Key_W){
        if(y()-passo-10 >= 0){
            setPos(x(), y()-passo);
            calculaColisoes();
            std::vector<Objeto*>::iterator a;
            for(a = colisoes.begin(); a != colisoes.end(); a++){
                if(!(*a)->atravessavel())
                    colidiu = true;
            }
            if(colidiu)
                setPos(x(), y()+passo);
        }
    }
    else if(event->key() == Qt::Key_S){
        if(y()+passo+10 <= scene()->height()){
            setPos(x(), y()+passo);
            calculaColisoes();
            std::vector<Objeto*>::iterator a;
            for(a = colisoes.begin(); a != colisoes.end(); a++){
                if(!(*a)->atravessavel())
                    colidiu = true;
            }
            if(colidiu)
                setPos(x(), y()-passo);
        }
    }
    else if(event->key() == Qt::Key_Q){
        calculaColisoes();
        std::vector<Objeto*>::iterator a;
        for(a = colisoes.begin(); a != colisoes.end(); a++){
            qDebug() << (*a)->tipo();
        }
    }
}


//! [3]
void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    int algo = 0;
    QVector<QGraphicsItem*> vect = scene()->collidingItems(this).toVector();
    if(vect.size() != 0){
        for(int i = 0; i < vect.size(); i++){
            if(vect[i] != this){
                Objeto* check = dynamic_cast<Objeto*>(vect[i]);
                if(check != nullptr){
                    algo = 1;
                    if(check->tipo() == "porta"){
                        color = Qt::yellow;
                    }
                    else{
                        color = Qt::red;
                    }
                }
            }
        }
    }
    if(!algo){
        color = Qt::red;
    }

    QPen pen;
    pen.setWidth(0);
    painter->setPen(pen);

    // Body
    painter->setBrush(color);
    //painter->drawEllipse(-10, -20, 20, 40);
    painter->drawRect(-10, -10, 20, 20);
    // Eyes
    painter->setBrush(Qt::white);
    painter->drawEllipse(-8, -8, 4, 4);
    painter->drawEllipse(2, -8, 4, 4);
    painter->setBrush(Qt::black);

//    auto pontoMouse = QCursor::pos() - this->scene()->views()[0]->pos();

//    QLineF ateMouse(this->pos(), QPointF(600, 350));
//    qreal anguloMouse = std::atan2(ateMouse.dy(), ateMouse.dx());
//    anguloMouse = normalizeAngle((Pi - anguloMouse) + Pi / 2);

//    this->setRotation(anguloMouse);

//    if(pontoMouse.x() > scenePos().x()+40){
//        if(pontoMouse.y() > scenePos().y()+40){
//            painter->drawEllipse(-11, -13, 3, 3);
//            painter->drawEllipse(1, -13, 3, 3);
//        }
//        else{
//            painter->drawEllipse(-11, -16, 3, 3);
//            painter->drawEllipse(1, -16, 3, 3);
//        }
//    }
//    else{
//        if(pontoMouse.y() > scenePos().y()+40){
//            painter->drawEllipse(-14, -13, 3, 3);
//            painter->drawEllipse(-3, -13, 3, 3);
//        }
//        else{
//            painter->drawEllipse(-14, -16, 3, 3);
//            painter->drawEllipse(-2, -16, 3, 3);
//        }

//    }

}
