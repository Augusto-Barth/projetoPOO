#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QGraphicsScene>
#include <QGraphicsView>

class JanelaPrincipal
{
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView;
public:
    JanelaPrincipal(QPixmap imagem);
};

#endif // JANELAPRINCIPAL_H
