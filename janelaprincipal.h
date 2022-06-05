#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <map>

#include "janelaprincipal.h"
#include "jogador.h"
#include "porta.h"
#include "casa.h"
#include "galinha.h"
#include "galinheiro.h"

class JanelaPrincipal
{
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView;
    static JanelaPrincipal* instancia;
    JanelaPrincipal();
    JanelaPrincipal (const JanelaPrincipal& obj);
    JanelaPrincipal operator=(JanelaPrincipal obj);


    std::map<std::string, QGraphicsItem*> items;
    Jogador *jogador = nullptr;
public:
    static JanelaPrincipal* getInstancia(){
        if(instancia == nullptr){
            instancia = new JanelaPrincipal();
        }
        return instancia;
    }
    void setImagem(QPixmap imagem);

    bool carregaJogo();
    void setup();
public slots:
    void salvaJogo();
};

//JanelaPrincipal* JanelaPrincipal::instancia = nullptr;
#endif // JANELAPRINCIPAL_H
