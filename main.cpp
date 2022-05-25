#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "janelaprincipal.h"
#include "jogador.h"
#include "porta.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    //scene.setSceneRect(0, 0, 600, 600);
    scene.setSceneRect(0, 0, 1280, 720);

//    QGraphicsRectItem* rect = new QGraphicsRectItem();
//    rect->setRect(0,0,600,600);
//    scene.addItem(rect);
    scene.setStickyFocus(true);

    Porta *porta = new Porta();
    porta->setPos(200, 200);
    scene.addItem(porta);

    Jogador *jogador = new Jogador();
    jogador->setPos(100, 100);
    scene.addItem(jogador);


    jogador->setFlag(QGraphicsItem::ItemIsFocusable);
    jogador->setFocus();

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/images/grass.jpg"));

//    view.setCacheMode(QGraphicsView::CacheBackground);
//    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setFrameStyle(QFrame::Box);
//    view.setFixedSize(605, 605);
    view.setFixedSize(1285, 725);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Jogo muito legal"));
    //view.resize(650, 650);
    view.show();
//    QTimer timer;
//    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
//    timer.start(1000 / 33);

    return app.exec();
}
