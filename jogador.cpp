#include "jogador.h"
#include "porta.h"
#include "objeto.h"
#include "janelaprincipal.h"
#include "galinha.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
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
#include <QCoreApplication>
#include <QMessageBox>

#include <chrono>
#include <thread>

#include <fstream>

constexpr qreal Pi = M_PI;
constexpr qreal TwoPi = 2 * M_PI;

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


Jogador::Jogador(QGraphicsItem* parent) : Objeto(parent)
{
    setRotation(0);
    personagem = QPixmap(":/images/BonecoDir.png");
    personagemAgua = QPixmap(":/images/BonecoBanhoEsq.png");
    personagemArma = QPixmap(":/images/BonecoArmaDir.png");
    personagemRede = QPixmap(":/images/BonecoRedeDir.png");
}

QRectF Jogador::boundingRect() const
{

    return QRectF(0, 0, 58, 55);
}

QPainterPath Jogador::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 52, 55);
    return path;
}

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


void Jogador::keyPressEvent(QKeyEvent *event){

    JanelaPrincipal* janela = JanelaPrincipal::getInstancia();

    int passo = 10;
    int metadeTamanhoH = 50;
    int metadeTamanhoV = 53;
    naAgua = false;
    calculaColisoes();
    std::vector<Objeto*>::iterator a;
    for(a = colisoes.begin(); a != colisoes.end(); a++){
        if((*a)->tipo() == "lagoa"){
            passo = 5;
            naAgua = true;
        }
        else{
            passo = 10;
        }
    }

    if(event->key() == Qt::Key_A){
        if(x()-passo >= 0){
            setPos(x()-passo, y());
            calculaColisoes();
            personagem = QPixmap(":/images/BonecoEsq.png");
            personagemAgua = QPixmap(":/images/BonecoBanhoEsq.png");
            personagemArma = QPixmap(":/images/BonecoArmaEsq.png");
            personagemRede = QPixmap(":/images/BonecoRedeEsq.png");
            if(colidiu())
                setPos(x()+passo, y());
        }
    }
    else if(event->key() == Qt::Key_D){
        if(x()+passo+metadeTamanhoH <= scene()->width()){
            setPos(x()+passo, y());
            calculaColisoes();
            personagem = QPixmap(":/images/BonecoDir.png");
            personagemAgua = QPixmap(":/images/BonecoBanhoDir.png");
            personagemArma = QPixmap(":/images/BonecoArmaDir.png");
            personagemRede = QPixmap(":/images/BonecoRedeDir.png");
            if(colidiu())
                setPos(x()-passo, y());
        }
    }
    else if(event->key() == Qt::Key_W){
        if(y()-passo >= 0){
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
//        janela->colocaTexto(QString::number(x()) + " " + QString::number(y()), 2);


//    QMediaPlayer *player = new QMediaPlayer;
//    player->setMedia(QUrl::fromLocalFile("/path"));
//    player->setVolume(50);
//    player->play();

        // FAZER ANIMAÇÃO POR VARIAVEL COM %
        // 3 FRAMES, ALTERAR ENTRE TODOS A CADA PASSO

        if(colisoes.size() == 0){
            if(putasso == 10){
                scene()->update();
                janela->colocaTexto("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 2);
            }
            else{
                janela->colocaTexto("Nada para pegar aqui", 2);
                putasso += 1;
            }
        }
            std::vector<Objeto*>::iterator a;
            for(a = colisoes.begin(); a != colisoes.end(); a++){

                if((*a)->tipo() == "porta"){
                    Porta* porta = dynamic_cast<Porta*>(*a);
                    if(!temBanho){
                        janela->colocaTexto("Ainda tô fedido", 2);
                    }
                    else{
                        porta->alteraVisibilidade();
                    }
                }
                else if(putasso == 10 && (*a)->tipo() != "porta"){
                    janela->colocaTexto("TO MUITO PUTO", 2);
                }
                else if((*a)->tipo() == "rede"){
                    if(!temRede){
                        adicionaRede();
                        (*a)->setVisible(false);
                        janela->colocaTexto("Pegou rede", 2);
                    }
                    else{
                        janela->colocaTexto("Já tenho a rede", 2);
                    }

                }
                else if((*a)->tipo() == "lagoa"){
                    if(!temBanho){
                        adicionaBanho();
                        janela->colocaTexto("Tomei banho", 2);
                    }
                    else{
                        janela->colocaTexto("Já tomei banho", 2);
                    }
                }
                else if((*a)->tipo() == "galinheiro"){
                    try{
                        janela->acabaJogo();
                    }
                    catch(int erro){
                        if(erro == -1)
                            janela->colocaTexto("Tenho que pegar a galinha", 2);
                    }
                }

        }
    }
    else if(event->key() == Qt::Key_F2){

        std::fstream f((QCoreApplication::applicationDirPath() + "/game.txt").toStdString(), std::fstream::in);
        if(f.is_open()){
            int xJogador, yJogador;

            f >> xJogador;
            f >> yJogador;
            f >> temBanho;
            f >> temRede;
            f >> temGalinha;
            f >> janela->getCasa()->aberto;

            // MUITO PORCO DEPOIS ARRUMAR
            janela->getCasa()->aberto = !janela->getCasa()->aberto;
            janela->getRedeObjeto()->setVisible(!temRede);


            qDebug() << xJogador << " " << yJogador << " " << temBanho << " " << temRede << " " << temGalinha << " " << janela->getCasa()->aberto;

            this->setPos(xJogador, yJogador);
            scene()->views()[0]->centerOn(this);

//            janela->colocaTexto(QString::fromStdString(std::to_string(xJogador) + " " + std::to_string(yJogador)));
            janela->colocaTexto("Jogo Carregado!", 2);
            janela->getPorta()->alteraVisibilidade();
            scene()->update();
            f.close();
        }
        else{
            qDebug() << "save não encontrado";
            QMessageBox messageBox;
            messageBox.critical(0,"Erro","Não foi encontrado um arquivo de save!");
            messageBox.setFixedSize(500,200);

        }
//        timer = new QTimer;
//        scene()->connect(timer, &QTimer::timeout, this, &Jogador::destroiTimer);
//        timer->start(1000);

//         QTimer::singleShot(1000, &Jogador::destroiTimer);
    }
    else if(event->key() == Qt::Key_F1){
        calculaColisoes();
        bool colidiu = false;
        std::vector<Objeto*>::iterator a;
        for(a = colisoes.begin(); a != colisoes.end(); a++){
            if((*a)->tipo() == "galinheiro")
                colidiu = true;
        }
        if(colidiu){

            janela->colocaTexto("Jogo Salvo!", 2);
            qDebug() << x() << " " << y();
            std::fstream f((QCoreApplication::applicationDirPath() + "/game.txt").toStdString(), std::fstream::out);

            f << x() << " " << y() << "\n" << temBanho << " " << temRede << " " << temGalinha << " " << janela->getCasa()->aberto;
            f.close();
        }
    }
    else if(event->key() == Qt::Key_F3){
        janela->comecaJogo();
    }
}


void Jogador::pegaGalinha(){
    calculaColisoes();
    JanelaPrincipal* janela = JanelaPrincipal::getInstancia();
    bool colidiu = false;
    Galinha* galinha = nullptr;
    std::vector<Objeto*>::iterator a;
    for(a = colisoes.begin(); a != colisoes.end(); a++){
        if((*a)->tipo() == "galinha"){
            colidiu = true;
            galinha = dynamic_cast<Galinha*>(*a);
        }
    }

    if(!colidiu)
        throw -1;
    else if(temRede){
        adicionaGalinha();
        janela->colocaTexto("Peguei a galinha", 2);
        galinha->setVisible(false);
    }
    else{
        throw -2;
    }
}

bool Jogador::adicionaBanho(){
    if(temBanho)
        return false;
    else{
        temBanho = true;
        return true;
    }
}

bool Jogador::adicionaRede(){
    if(temRede)
        return false;
    else{
        temRede = true;
        return true;
    }
}

bool Jogador::adicionaGalinha(){
    if(temGalinha)
        return false;
    else{
        temGalinha = true;
        return true;
    }
}


//! [3]
void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(naAgua){
        painter->drawPixmap(0, 0, personagemAgua, 0, 0, 0, 0);
    }
    else if(putasso == 10){
        painter->drawPixmap(0, 0, personagemArma, 0, 0, 0, 0);
    }
    else{
        if(temRede)
            painter->drawPixmap(0, 0, personagemRede, 0, 0, 0, 0);
        else
            painter->drawPixmap(0, 0, personagem, 0, 0, 0, 0);
    }
    ensureVisible(QRectF(), 200, 200);
    scene()->update();
}
