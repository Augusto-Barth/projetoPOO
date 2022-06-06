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
#include "telhado.h"
#include "redeobjeto.h"



class JanelaPrincipal : public QObject
{
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView;
    static JanelaPrincipal* instancia;
    JanelaPrincipal();
    JanelaPrincipal (const JanelaPrincipal& obj);
    JanelaPrincipal operator=(JanelaPrincipal obj);

//    std::map<std::string, QGraphicsItem*> items;
    Jogador* jogador = nullptr;
    Casa* casa = nullptr;
    Porta* porta = nullptr;
    Galinha* galinha = nullptr;
    Telhado* telhado = nullptr;
    RedeObjeto* rede = nullptr;

    QGraphicsTextItem *texto = nullptr;
    QTimer* timerTexto = nullptr;
    QTimer* timerJanelaPrincipal = nullptr;
    QTimer* timerSobeTexto = nullptr;

    void sobeTexto();

public:
    static JanelaPrincipal* getInstancia(){
        if(instancia == nullptr){
            instancia = new JanelaPrincipal();
        }
        return instancia;
    }
    void setImagem(QPixmap imagem);

    Jogador* getJogador(){return jogador;}
    Casa* getCasa(){return casa;}
    Porta* getPorta(){return porta;}
    Telhado* getTelhado(){return telhado;}
    RedeObjeto* getRedeObjeto(){return rede;}
    bool carregaJogo();
    void setup();
    void destroiTimer();
    void colocaTexto(QString textoParaColocar, int tempo, bool longo = false);
    void comecaJogo();
    void acabaJogo();

public slots:
    void salvaJogo();
};

//JanelaPrincipal* JanelaPrincipal::instancia = nullptr;
#endif // JANELAPRINCIPAL_H
