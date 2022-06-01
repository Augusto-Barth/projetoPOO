#include "janelaprincipal.h"
#include "jogador.h"
#include "porta.h"
#include "casa.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsRectItem>
#include <QGraphicsView>

JanelaPrincipal::JanelaPrincipal(QPixmap imagem)
{
    scene->setSceneRect(0, 0, 1280, 720);

//    QGraphicsRectItem* rect = new QGraphicsRectItem;
//    rect->setRect(0,0,600,600);
//    scene.addItem(rect);
    scene->setStickyFocus(true);

    Porta *porta = new Porta;
    porta->setPos(200, 200);
    scene->addItem(porta);

    Casa *casa = new Casa;
    casa->setPos(500, 200);
    scene->addItem(casa);

    Jogador *jogador = new Jogador;
    jogador->setPos(670, 350);
    scene->addItem(jogador);
    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();

    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    //view->setBackgroundBrush(QPixmap(":/images/grass.png"));
    view->setBackgroundBrush(imagem);
    view->setFrameStyle(QFrame::Box);

    view->setCacheMode(QGraphicsView::CacheBackground);
//  view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Jogo muito legal"));
    view->setFixedSize(1285, 725);
    view->show();

}

