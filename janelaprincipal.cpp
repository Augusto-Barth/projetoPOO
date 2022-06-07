#include "jogador.h"
#include "porta.h"
#include "casa.h"
#include "galinha.h"
#include "galinheiro.h"
#include "eventfilter.h"
#include "janelaprincipal.h"
#include "lagoa.h"
#include "redeobjeto.h"
#include "velha.h"
#include "colisoesgerais.h"
#include "telhado.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#include <fstream>

JanelaPrincipal* JanelaPrincipal::instancia = nullptr;

JanelaPrincipal::JanelaPrincipal()
{
    scene->setSceneRect(0, 0, 1780, 1220);

    scene->setStickyFocus(true);

    view->setBackgroundBrush(QColor(0, 0, 0));
    QGraphicsPixmapItem* back = scene->addPixmap(QPixmap(":/images/mapa3.png"));
    back->setPos(0, 0);

    ColisoesGerais* colisoes = new ColisoesGerais;
    colisoes->setPos(0, 0);
    scene->addItem(colisoes);

    rede = new RedeObjeto;
    rede->setPos(1240, 430);
    scene->addItem(rede);

    porta = new Porta;
    porta->setPos(1142, 345);
    scene->addItem(porta);
    porta->setZValue(0);

    telhado = new Telhado;
    telhado->setPos(1142, 345);
    scene->addItem(telhado);
    telhado->setZValue(2);

    casa = new Casa;
    casa->setPos(1158, 476);
    scene->addItem(casa);
    casa->setZValue(0);

    jogador = new Jogador;
    jogador->setPos(800, 600);
    scene->addItem(jogador);
    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();
    jogador->setZValue(1);

    Velha* velha = new Velha;
    velha->setPos(1150, 360);
    scene->addItem(velha);
    velha->setZValue(2);

    Lagoa* lagoa = new Lagoa();
    lagoa->setPos(0, 0);
    scene->addItem(lagoa);

    galinha = new Galinha;
    galinha->setPos(875, 145);
    scene->addItem(galinha);

    Galinheiro *galinheiro = new Galinheiro;
    galinheiro->setPos(1270, 1000);
    scene->addItem(galinheiro);

    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);

    view->setFrameStyle(QFrame::Box);

    //view->setCacheMode(QGraphicsView::CacheBackground);
//    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view->setDragMode(QGraphicsView::NoDrag);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    EventFilter* filter = new EventFilter();
    view->verticalScrollBar()->installEventFilter(filter);
    view->horizontalScrollBar()->installEventFilter(filter);


    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Betty Revengeance 2  : Electric Boogaloo"));
//    view->setFixedSize(1285, 725);
//    view->size

    view->show();

    timerJanelaPrincipal = new QTimer;
    QObject::connect(timerJanelaPrincipal, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timerJanelaPrincipal->start(1000 / 17);

    timerSobeTexto = new QTimer;
    QObject::connect(timerSobeTexto, &QTimer::timeout, this, &JanelaPrincipal::sobeTexto);
    timerSobeTexto->start(1000 / 33);

    tempoDeJogo = new QElapsedTimer;
    tempoDeJogo->start();

    timerTexto = new QTimer;
    QObject::connect(timerTexto, &QTimer::timeout, this, &JanelaPrincipal::destroiTimer);
    timerTexto->setSingleShot(true);

    comecaJogo();

}

void JanelaPrincipal::setImagem(QPixmap imagem)
{
    view->setBackgroundBrush(imagem);
}

void JanelaPrincipal::colocaTexto(QString textoParaColocar, int tempo, bool longo){
    if(texto == nullptr){
        texto = new QGraphicsTextItem;
        texto->setZValue(10);
        scene->addItem(texto);
        QFont fonte("Helvetica", 16);
//        fonte.setStyleStrategy(QFont::ForceOutline);
        texto->setDefaultTextColor(QColor(255, 255, 255));
        texto->setFont(fonte);
    }

    texto->setPlainText(textoParaColocar);
    texto->setPos(jogador->x()-25,jogador->y()-30);
    texto->setOpacity(1);
    texto->setVisible(true);
    if(longo)
        timerSobeTexto->setInterval(1000/10);
    else
        timerSobeTexto->setInterval(1000/33);
    timerTexto->start(tempo*1000);

}

void JanelaPrincipal::destroiTimer(){
//    qDebug() << "acabo";
    if(texto != nullptr)
        texto->setVisible(false);
}

void JanelaPrincipal::comecaJogo(){
    jogador->putasso = 0;
    jogador->temBanho = false;
    jogador->temRede = false;
    jogador->temGalinha = false;
    jogador->setPos(800, 600);

    galinha->setVisible(true);
    rede->setVisible(true);

    casa->setZValue(0);
    casa->aberto = false;
    porta->setOpacity(1);
    telhado->setOpacity(1);

    tempoDeJogo->restart();
    view->centerOn(jogador);
    colocaTexto("F para interagir, F1 salvar, F2 carregar, F3 resetar", 5, true);
}

void JanelaPrincipal::fechaView(){
    view->close();
}

void JanelaPrincipal::acabaJogo(bool pacifist){
    if(!jogador->temGalinha && pacifist)
        throw -4;
    else if(!jogador->putasso && !pacifist)
        throw -3;
    colocaTexto(QString::number(tempoDeJogo->elapsed()/1000.0) + "s", 4, true);
    QTimer* fimDeJogo = new QTimer;
    QObject::connect(fimDeJogo, &QTimer::timeout, this, &JanelaPrincipal::fechaView);
    fimDeJogo->setSingleShot(true);
    fimDeJogo->start(2000);
}

void JanelaPrincipal::sobeTexto(){
    if(texto != nullptr){
        if(texto->isVisible()){
            texto->setOpacity(texto->opacity()-0.01);
            texto->setPos(texto->x(), texto->y()-1);
        }
    }
}
