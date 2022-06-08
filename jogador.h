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
private:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent *event) override;

    int frame = 0;
    int ultimaDirecao = 1;
    int raiva = 0;
    bool temBanho = false;
    bool temRede = false;
    bool temGalinha = false;
    bool naAgua = false;
    bool putasso = false;
    std::vector<Objeto*> colisoes;

    bool adicionaBanho();
    bool adicionaRede();
    bool adicionaGalinha();
    void calculaColisoes();
    void atualizaJogador(bool anda = true);

    QPixmap personagem;

public:
    Jogador(QGraphicsItem* parent = nullptr);

    QString tipo();
    bool atravessavel();
    void pegaGalinha();
    bool colidiu();
    void resetaPersonagem();

    bool getTemGalinha(){return temGalinha;}
    bool getPutasso(){return putasso;}
    std::vector<Objeto*> getColisoes(){return colisoes;}

};

#endif // JOGADOR_H
