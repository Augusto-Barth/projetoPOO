#include "janelaprincipal.h"
#include "jogador.h"
#include "porta.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsRectItem>
#include <QGraphicsView>

JanelaPrincipal::JanelaPrincipal()
{

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 600, 600);

    QGraphicsRectItem* rect = new QGraphicsRectItem;
    rect->setRect(0,0,600,600);
    scene.addItem(rect);
    scene.setStickyFocus(true);

    Porta *porta = new Porta;
    porta->setPos(200, 200);
    scene.addItem(porta);

    Jogador *jogador = new Jogador;
    jogador->setPos(100, 100);
    scene.addItem(jogador);


    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    //view.setBackgroundBrush(QPixmap(":/images/gustavo.png"));

//    view.setCacheMode(QGraphicsView::CacheBackground);
//    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Jogo muito legal"));
    view.resize(650, 650);
    view.show();

}
