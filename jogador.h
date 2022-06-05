#ifndef JOGADOR_H
#define JOGADOR_H

#include <QGraphicsItem>
#include <vector>
#include <QString>
#include <QTimer>
#include <QGraphicsTextItem>
#include "objeto.h"

class JanelaPrincipal;

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
//    void adicionaInventario(QString item);
    bool adicionaBanho();
    bool adicionaRede();
    bool adicionaGalinha();
    std::vector<Objeto*> getColisoes(){return colisoes;}
//    std::vector<std::string> getInventario(){return inventario;}
    //std::vector<bool> items; // 0 rede, 1 galinha

//    void colocaTexto(QString textoParaColocar);

    bool temBanho = false;
    bool temRede = false;
    bool temGalinha = false;

//    QTimer *timer = new QTimer();
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
//    std::vector<std::string> inventario;


//    QGraphicsTextItem *texto = nullptr;

    QPixmap personagem;

};

#endif // JOGADOR_H
