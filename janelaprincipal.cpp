#include "janelaprincipal.h"
#include "jogador.h"
#include "porta.h"
#include "casa.h"
#include "galinha.h"
#include "galinheiro.h"

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
    casa->setPos(900, 100);
    scene->addItem(casa);

    jogador = new Jogador;
    jogador->setPos(900, 600);
    scene->addItem(jogador);
    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();

    QGraphicsTextItem *texto = new QGraphicsTextItem;
    texto->setPlainText("Qualquer coisa");
    texto->setPos(100,100);
    scene->addItem(texto);

    Galinha *galinha = new Galinha;
    galinha->setPos(100, 600);
    scene->addItem(galinha);

    Galinheiro *galinheiro = new Galinheiro;
    galinheiro->setPos(1270, 1180);
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

    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Jogo muito legal"));
    view->setFixedSize(1285, 725);
    view->show();

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
