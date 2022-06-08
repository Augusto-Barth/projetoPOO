#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QElapsedTimer>
#include <QObject>

#include "jogador.h"
#include "porta.h"
#include "casa.h"
#include "galinha.h"
#include "galinheiro.h"
#include "telhado.h"
#include "redeobjeto.h"


class JanelaPrincipal : public QObject
{
private:
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView;

    static JanelaPrincipal* instancia;
    JanelaPrincipal();
    JanelaPrincipal (const JanelaPrincipal& obj);
    JanelaPrincipal operator=(JanelaPrincipal obj);

    void sobeTexto();
    void fechaView();
    void destroiTexto();

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
    QElapsedTimer* tempoDeJogo = nullptr;
public:
    static JanelaPrincipal* getInstancia(){
        if(instancia == nullptr){
            instancia = new JanelaPrincipal();
        }
        return instancia;
    }

    Jogador* getJogador(){return jogador;}
    Casa* getCasa(){return casa;}
    Porta* getPorta(){return porta;}
    Telhado* getTelhado(){return telhado;}
    RedeObjeto* getRedeObjeto(){return rede;}

    bool carregaJogo();
    void comecaJogo();
    void acabaJogo(bool pacifist = true);
    void colocaTexto(QString textoParaColocar, int tempo, bool longo = false);

};

#endif // JANELAPRINCIPAL_H
