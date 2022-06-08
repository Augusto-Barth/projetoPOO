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
#include <QObject>
#include <QCoreApplication>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>

#include <chrono>
#include <thread>

#include <fstream>

#define LIMITE_PUTASSO 15

QString Jogador::tipo(){
    return "jogador";
}

bool Jogador::atravessavel(){
    return false;
}

Jogador::Jogador(QGraphicsItem* parent) : Objeto(parent){
    personagem = QPixmap(":/images/BonecoDir.png");
}

QRectF Jogador::boundingRect() const{

    return QRectF(0, 0, 58, 55);
}

QPainterPath Jogador::shape() const{
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

bool Jogador::colidiu(){
    std::vector<Objeto*>::iterator a;
    bool colidiu = false;
    for(a = colisoes.begin(); a != colisoes.end(); a++){
        if(!(*a)->atravessavel())
            colidiu = true;
    }
    return colidiu;
}

void Jogador::atualizaJogador(bool anda){

    // direcao : 0 esquerda 1 direita
    if(anda)
        frame++;
    switch (frame%3) {
    case 0:
        if(naAgua){
            personagem = ultimaDirecao ? QPixmap(":/images/BonecoBanhoDir.png") : QPixmap(":/images/BonecoBanhoEsq.png");
        }
        else if(putasso){
            personagem =  ultimaDirecao ? QPixmap(":/images/BonecoArmaDir.png") : QPixmap(":/images/BonecoArmaEsq.png");
        }
        else{
            if(temRede)
                personagem =  ultimaDirecao ? QPixmap(":/images/BonecoRedeDir.png") : QPixmap(":/images/BonecoRedeEsq.png");
            else
                personagem =  ultimaDirecao ? QPixmap(":/images/BonecoDir.png") : QPixmap(":/images/BonecoEsq.png");
        }
        break;
    case 1:
        if(naAgua){
            personagem =  ultimaDirecao ? QPixmap(":/images/BonecoBanhoDir.png") : QPixmap(":/images/BonecoBanhoEsq.png");
        }
        else if(putasso){
            personagem =  ultimaDirecao ? QPixmap(":/images/BonecoArmaDir1.png") : QPixmap(":/images/BonecoArmaEsq1.png");
        }
        else{
            if(temRede)
                personagem =  ultimaDirecao ? QPixmap(":/images/BonecoRedeDir1.png") : QPixmap(":/images/BonecoRedeEsq1.png");
            else
                personagem =  ultimaDirecao ? QPixmap(":/images/BonecoDir1.png") : QPixmap(":/images/BonecoEsq1.png");
        }
        break;
    case 2:
        if(naAgua){
            personagem =  ultimaDirecao ? QPixmap(":/images/BonecoBanhoDir.png") : QPixmap(":/images/BonecoBanhoEsq.png");
        }
        else if(putasso){
            personagem =  ultimaDirecao ? QPixmap(":/images/BonecoArmaDir2.png") : QPixmap(":/images/BonecoArmaEsq2.png");
        }
        else{
            if(temRede)
                personagem =  ultimaDirecao ? QPixmap(":/images/BonecoRedeDir2.png") : QPixmap(":/images/BonecoRedeEsq2.png");
            else
                personagem =  ultimaDirecao ? QPixmap(":/images/BonecoDir2.png") : QPixmap(":/images/BonecoEsq2.png");
        }
        break;
    }
    scene()->update();
}


void Jogador::keyPressEvent(QKeyEvent *event){

    JanelaPrincipal* janela = JanelaPrincipal::getInstancia();

    int passo = 10;
    int TamanhoH = 50;
    int TamanhoV = 53;
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
            ultimaDirecao = 0;
            atualizaJogador();
            if(colidiu())
                setPos(x()+passo, y());
        }
    }
    else if(event->key() == Qt::Key_D){
        if(x()+passo+TamanhoH <= scene()->width()){
            setPos(x()+passo, y());
            calculaColisoes();
            ultimaDirecao = 1;
            atualizaJogador();
            if(colidiu())
                setPos(x()-passo, y());
        }
    }
    else if(event->key() == Qt::Key_W){
        if(y()-passo >= 0){
            setPos(x(), y()-passo);
            calculaColisoes();
            atualizaJogador();
            if(colidiu())
                setPos(x(), y()+passo);
        }
    }
    else if(event->key() == Qt::Key_S){
        if(y()+passo+TamanhoV <= scene()->height()){
            setPos(x(), y()+passo);
            calculaColisoes();
            atualizaJogador();
            if(colidiu())
                setPos(x(), y()-passo);
        }

    }
    else if(event->key() == Qt::Key_F){
        calculaColisoes();
//        janela->colocaTexto(QString::number(x()) + " " + QString::number(y()), 2);


//        QMediaPlayer* player = new QMediaPlayer;
//        QAudioOutput* audioOutput = new QAudioOutput;
//        player->setAudioOutput(audioOutput);
//        // ...
//        player->setSource(QUrl::fromLocalFile("/home/augusto/Documents/projetoPOO/images/tiro.mp3"));
//        player->setSource(QUrl::fromLocalFile(":/images/tiro.mp3"));

//        audioOutput->setVolume(50);
//        player->play();

        if(colisoes.size() == 0 || (colisoes.size() == 1 && colisoes[0]->tipo() == "colisoesgerais")){
            if(raiva == LIMITE_PUTASSO){
                putasso = true;
                janela->colocaTexto("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 2);
                atualizaJogador(false);
            }
            else{
                janela->colocaTexto("Nada para pegar aqui", 2);
                raiva += 1;
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
                else if(putasso && (*a)->tipo() != "porta"){
                    janela->colocaTexto("TO MUITO PUTO", 2);
                }
                else if((*a)->tipo() == "rede"){
                    if(adicionaRede()){
                        (*a)->setVisible(false);
                        janela->colocaTexto("Pegou rede", 2);
                    }
                    else{
                        janela->colocaTexto("Já tenho a rede", 2);
                    }

                }
                else if((*a)->tipo() == "lagoa"){
                    if(adicionaBanho()){
                        janela->colocaTexto("Tomei banho", 2);
                    }
                    else{
                        janela->colocaTexto("Já tomei banho", 2);
                    }
                }
                else if((*a)->tipo() == "galinheiro"){
                    try{
                        janela->acabaJogo();
                        //janela->colocaTexto("Consegui pegar a galinha!", 4, true);
                    }
                    catch(int erro){
                        if(erro == -4)
                            janela->colocaTexto("Tenho que pegar a galinha", 2);
                    }
                }

        }
            atualizaJogador(false);
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
            f >> putasso;

            // MUITO PORCO DEPOIS ARRUMAR
            janela->getCasa()->aberto = !janela->getCasa()->aberto;
            janela->getRedeObjeto()->setVisible(!temRede);
            if(putasso)
                raiva = LIMITE_PUTASSO;

            this->setPos(xJogador, yJogador);
            scene()->views()[0]->centerOn(this);

            calculaColisoes();
            naAgua = false;
            std::vector<Objeto*>::iterator a;
            for(a = colisoes.begin(); a != colisoes.end(); a++){
                if((*a)->tipo() == "lagoa"){
                    naAgua = true;
                }
            }

            janela->colocaTexto("Jogo Carregado!", 2);
            janela->getPorta()->alteraVisibilidade();
            atualizaJogador(false);
            f.close();
        }
        else{
            qDebug() << "save não encontrado";
            QMessageBox messageBox;
            messageBox.critical(0,"Erro","Não foi encontrado um arquivo de save!");
            messageBox.setFixedSize(500,200);

        }
    }
    else if(event->key() == Qt::Key_F1){
        janela->colocaTexto("Jogo Salvo!", 2);
        std::fstream f((QCoreApplication::applicationDirPath() + "/game.txt").toStdString(), std::fstream::out);
        f << x() << " " << y() << "\n" << temBanho << " " << temRede << " " << temGalinha << " " << janela->getCasa()->aberto << " " << putasso;
        f.close();
    }
    else if(event->key() == Qt::Key_F3){
        janela->comecaJogo();
        atualizaJogador(false);
    }
}

void Jogador::resetaPersonagem(){
    putasso = false;
    raiva = 0;
    temBanho = false;
    temRede = false;
    temGalinha = false;
    naAgua = false;
    setPos(800, 600);
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
    else if(putasso){
        //janela->colocaTexto("POW!", 2);
        galinha->setVisible(false);
        janela->acabaJogo(false);
    }
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

void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    painter->drawPixmap(0, 0, personagem, 0, 0, 0, 0);
    ensureVisible(QRectF(), 200, 200);
}
