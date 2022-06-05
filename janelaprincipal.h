#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QObject>
#include <map>

#include "jogador.h"
#include "porta.h"
#include "casa.h"
#include "galinha.h"
#include "galinheiro.h"



class JanelaPrincipal : public QObject
{
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView;
    static JanelaPrincipal* instancia;
    JanelaPrincipal();
    JanelaPrincipal (const JanelaPrincipal& obj);
    JanelaPrincipal operator=(JanelaPrincipal obj);

    std::map<std::string, QGraphicsItem*> items;
    Jogador* jogador = nullptr;
    QGraphicsTextItem *texto = nullptr;
    QTimer* timerTexto = nullptr;

public:
    static JanelaPrincipal* getInstancia(){
        if(instancia == nullptr){
            instancia = new JanelaPrincipal();
        }
        return instancia;
    }
    void setImagem(QPixmap imagem);

    Jogador* getJogador(){return jogador;}
    bool carregaJogo();
    void setup();
    void destroiTimer();
    void colocaTexto(QString textoParaColocar);
    void acabaJogo();

public slots:
    void salvaJogo();
};

//JanelaPrincipal* JanelaPrincipal::instancia = nullptr;
#endif // JANELAPRINCIPAL_H
