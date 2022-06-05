#ifndef JOGADOR_H
#define JOGADOR_H

#include <QGraphicsItem>
#include <vector>
#include <QString>
#include <QTimer>
#include <QGraphicsTextItem>
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
    bool colidiu();
    QString tipo();
    bool atravessavel();

    //std::vector<bool> items; // 0 rede, 1 galinha

protected:
//    void advance(int step) override;

public slots:
    void destroiTimer();

private:
    qreal angle = 0;
    qreal speed = 0;
    qreal mouseEyeDirection = 0;
    QPointF pontoMouse;
    std::vector<Objeto*> colisoes;
    QGraphicsTextItem *texto;
    QTimer *timer;
    QPixmap personagem;

};

#endif // JOGADOR_H
