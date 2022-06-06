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
    void calculaColisoes();
    void pegaGalinha();


    QString tipo();
    bool atravessavel();

    bool adicionaBanho();
    bool adicionaRede();
    bool adicionaGalinha();
    std::vector<Objeto*> getColisoes(){return colisoes;}
    bool colidiu();

    int raiva = 0;
    bool putasso = false;
    int frame = 0;
    bool temBanho = false;
    bool temRede = false;
    bool temGalinha = false;
    bool naAgua = false;

protected:

public slots:
    void destroiTimer();

private:
    int ultimaDirecao = 1;
    QPointF pontoMouse;
    std::vector<Objeto*> colisoes;

    QPixmap atualizaJogador(int direcao, bool anda = true);

    QPixmap personagem;
    QPixmap personagemAgua;
    QPixmap personagemArma;
    QPixmap personagemRede;

};

#endif // JOGADOR_H
