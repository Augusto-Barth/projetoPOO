#ifndef PORTA_H
#define PORTA_H

#include "objeto.h"

class JanelaPrincipal;

class Porta : public Objeto
{
private:

public:
    Porta(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString tipo();
    bool atravessavel();
    void alteraVisibilidade();
    bool visivel = true;
};

#endif // PORTA_H
