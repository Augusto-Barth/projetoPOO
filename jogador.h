#ifndef JOGADOR_H
#define JOGADOR_H

#include <QGraphicsItem>
#include <vector>
#include <QString>
#include "objeto.h"

class Jogador : public Objeto
{
public:
    Jogador(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent *event) override;
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void calculaColisoes();
    QString tipo();
    bool atravessavel();

protected:
//    void advance(int step) override;

private:
    qreal angle = 0;
    qreal speed = 0;
    qreal mouseEyeDirection = 0;
    QColor color;
    QPointF pontoMouse;
    std::vector<Objeto*> colisoes;
};

#endif // JOGADOR_H
