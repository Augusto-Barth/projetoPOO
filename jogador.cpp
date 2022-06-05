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
#include <QTimer>
#include <QObject>

#include <chrono>
#include <thread>

#include <fstream>

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

bool Jogador::colidiu(){
    std::vector<Objeto*>::iterator a;
    bool colidiu = false;
    for(a = colisoes.begin(); a != colisoes.end(); a++){
        if(!(*a)->atravessavel())
            colidiu = true;
    }
    return colidiu;
}

//! [0]
Jogador::Jogador(QGraphicsItem* parent) : Objeto(parent)
{
    setRotation(0);
    personagem = QPixmap(":/images/BonecoDir.png");
//    for(int i = 0; i < 3; i++)
//        items[i] = false;
//    this->timer = new QTimer();
//    QObject::connect(timer, &QTimer::timeout, this, &Jogador::destroiTimer);
//    timer->setSingleShot(true);
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

    return QRectF(-40, -40, 80, 80);
}
//! [1]

//! [2]
QPainterPath Jogador::shape() const
{
    QPainterPath path;
    path.addRect(-40, -40, 80, 80);
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
    int metadeTamanhoH = 20;
    int metadeTamanhoV = 60;
    if(event->key() == Qt::Key_A){
        if(x()-passo-metadeTamanhoH >= 0){
            setPos(x()-passo, y());
            calculaColisoes();
            personagem = QPixmap(":/images/BonecoEsq.png");
            if(colidiu())
                setPos(x()+passo, y());
        }
    }
    else if(event->key() == Qt::Key_D){
        if(x()+passo+metadeTamanhoH <= scene()->width()){
            setPos(x()+passo, y());
            calculaColisoes();
            personagem = QPixmap(":/images/BonecoDir.png");
            if(colidiu())
                setPos(x()-passo, y());
        }
    }
    else if(event->key() == Qt::Key_W){
        if(y()-passo-metadeTamanhoV >= 0){
            setPos(x(), y()-passo);
            calculaColisoes();
            if(colidiu())
                setPos(x(), y()+passo);
        }
    }
    else if(event->key() == Qt::Key_S){
        if(y()+passo+metadeTamanhoV <= scene()->height()){
            setPos(x(), y()+passo);
            calculaColisoes();
            if(colidiu())
                setPos(x(), y()-passo);
        }
    }
    else if(event->key() == Qt::Key_F){
        calculaColisoes();
        std::vector<Objeto*>::iterator a;
        for(a = colisoes.begin(); a != colisoes.end(); a++){
            qDebug() << (*a)->tipo();
        }
    }
    else if(event->key() == Qt::Key_E){

        std::FILE *f = std::fopen("/home/augusto/Documents/game.txt", "r");
        //std::fstream f("/home/augusto/Documents/game.txt", std::fstream::in);
        std::string textoArquivo;
        int xJogador, yJogador;
        std::fscanf(f, "%d %d", &xJogador, &yJogador);
        std::fclose(f);

        this->setPos(xJogador, yJogador);
        scene()->views()[0]->centerOn(this);

        if(this->texto == nullptr){
            texto = new QGraphicsTextItem;
            texto->setPlainText(QString::fromStdString(std::to_string(xJogador) + " " + std::to_string(yJogador)));
            texto->setPos(x()-metadeTamanhoH,y()-metadeTamanhoV-20);
            scene()->addItem(texto);
        }
        else{
            texto->setPlainText(QString::fromStdString(std::to_string(xJogador) + " " + std::to_string(yJogador)));
            texto->setPos(x()-metadeTamanhoH,y()-metadeTamanhoV-20);
        }

//        timer = new QTimer;
//        scene()->connect(timer, &QTimer::timeout, this, &Jogador::destroiTimer);
//        timer->start(1000);

//         QTimer::singleShot(1000, &Jogador::destroiTimer);
    }
    else if(event->key() == Qt::Key_Q){
        calculaColisoes();
        bool colidiu = false;
        std::vector<Objeto*>::iterator a;
        for(a = colisoes.begin(); a != colisoes.end(); a++){
            if((*a)->tipo() == "galinheiro")
                colidiu = true;
        }
        if(colidiu){
            qDebug() << x() << " " << y();
            std::fstream f("/home/augusto/Documents/game.txt", std::fstream::out);
            f << x() << " " << y();
            f.close();
        }
    }
}

void Jogador::destroiTimer(){
    qDebug() << "acabo";
}

//! [3]
void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
//    int algo = 0;
//    QVector<QGraphicsItem*> vect = scene()->collidingItems(this).toVector();
//    if(vect.size() != 0){
//        for(int i = 0; i < vect.size(); i++){
//            if(vect[i] != this){
//                Objeto* check = dynamic_cast<Objeto*>(vect[i]);
//                if(check != nullptr){
//                    algo = 1;
//                    if(check->tipo() == "porta"){
//                        color = Qt::yellow;
//                    }
//                    else{
//                        color = Qt::red;
//                    }
//                }
//            }
//        }
//    }
//    if(!algo){
//        color = Qt::red;
//    }

//    QPen pen;
//    pen.setWidth(0);
//    painter->setPen(pen);

//    // Body
//    painter->setBrush(color);
//    //painter->drawEllipse(-10, -20, 20, 40);
//    painter->drawRect(-20, -20, 40, 40);
//    // Eyes
//    painter->setBrush(Qt::white);
//    painter->drawEllipse(-7, -8, 5, 5);
//    painter->drawEllipse(2, -8, 5, 5);
//    painter->setBrush(Qt::black);
//    painter->drawEllipse(-6, -7, 2, 2);
//    painter->drawEllipse(3, -7, 2, 2);

//    painter->drawPixmap(QPixmap(":/images/personagem.png"));
//    painter->drawPixmap(-20, -60, QPixmap(":/images/personagem.png"), 40, 0, 40, 120);
    painter->drawPixmap(-40, -40, personagem, 0, 0, 80, 80);
    ensureVisible(QRectF(), 100, 100);

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
