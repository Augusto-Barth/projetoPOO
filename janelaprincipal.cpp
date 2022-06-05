#include "jogador.h"
#include "porta.h"
#include "casa.h"
#include "galinha.h"
#include "galinheiro.h"
#include "eventfilter.h"
#include "janelaprincipal.h"
#include "lagoa.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QPushButton>


#include <fstream>

JanelaPrincipal* JanelaPrincipal::instancia = nullptr;

JanelaPrincipal::JanelaPrincipal()
{
    scene->setSceneRect(0, 0, 1780, 1220);

//    QGraphicsRectItem* rect = new QGraphicsRectItem;
//    rect->setRect(0,0,600,600);
//    scene.addItem(rect);
    scene->setStickyFocus(true);

//    setup();
//    QPushButton* salvar = new QPushButton();
//    salvar->setText("SALVAR");
//    salvar->setGeometry(30, 30, 120, 50);
//    scene->addWidget(salvar);



    //QGraphicsView::connect(salvar, &QPushButton::clicked, view, &JanelaPrincipal::salvaJogo);

    Porta *porta = new Porta;
    porta->setPos(200, 200);
    scene->addItem(porta);

    Casa *casa = new Casa;
    casa->setPos(1240, 545);
    scene->addItem(casa);

    jogador = new Jogador;
    jogador->setPos(800, 600);
    scene->addItem(jogador);
    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();
    jogador->janela = this;

    timerTexto = new QTimer;
    QObject::connect(timerTexto, &QTimer::timeout, this, &JanelaPrincipal::destroiTimer);
    timerTexto->setSingleShot(true);
//    jogador->timer->start(1000);

    Lagoa* lagoa = new Lagoa();
    lagoa->setPos(200, 400);
    scene->addItem(lagoa);

    QGraphicsTextItem *texto = new QGraphicsTextItem;
    texto->setPlainText("Qualquer coisa");
    texto->setPos(100,100);
    scene->addItem(texto);

    Galinha *galinha = new Galinha;
    galinha->setPos(875, 135);
    scene->addItem(galinha);

    Galinheiro *galinheiro = new Galinheiro;
    galinheiro->setPos(1270, 1000);
    scene->addItem(galinheiro);

    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    //view->setBackgroundBrush(QPixmap(":/images/grass.png"));

    view->setFrameStyle(QFrame::Box);

    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::NoDrag);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    EventFilter* filter = new EventFilter();
    view->verticalScrollBar()->installEventFilter(filter);
    view->horizontalScrollBar()->installEventFilter(filter);


    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Jogo muito legal"));
    view->setFixedSize(1285, 725);

    view->show();

    QTimer* timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(1000 / 33);

}

void JanelaPrincipal::setImagem(QPixmap imagem)
{
    view->setBackgroundBrush(imagem);
}

void JanelaPrincipal::salvaJogo(){
    std::fstream f("game.txt", std::fstream::out);
    f << jogador->x() << " " << jogador->y();
//    for(int i = 0; i < 3; i++)
//        f << jogador->items[i];
    f.close();
}

void JanelaPrincipal::setup(){
    QMenuBar *bar = new QMenuBar();
    scene->addWidget(bar);

    QMenu* yourMenu = bar->addMenu("Your Menu title");
    QAction* yourFirstAction = yourMenu->addAction("Your First Action");
}

//void JanelaPrincipal::destroiTimer(){
//    jogador->destroiTimer();
//}

void JanelaPrincipal::colocaTexto(QString textoParaColocar){
    if(texto == nullptr){
        texto = new QGraphicsTextItem;
        scene->addItem(texto);
    }
    QFont fonte("Helvetica", 16);
    texto->setFont(fonte);
    texto->setPlainText(textoParaColocar);
    texto->setPos(jogador->x()-20,jogador->y()-30);
    texto->setVisible(true);
    timerTexto->start(3000);
}

void JanelaPrincipal::destroiTimer(){
//    qDebug() << "acabo";
    if(texto != nullptr)
        texto->setVisible(false);
}

void JanelaPrincipal::acabaJogo(){
    if(!jogador->temGalinha)
        throw -1;
    view->close();
}
