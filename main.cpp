#include <QApplication>

#include "janelaprincipal.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    //JanelaPrincipal janela(QPixmap(":/images/fundo.png"));
    JanelaPrincipal* janela = JanelaPrincipal::getInstancia();
    janela->setImagem(QPixmap(":/images/mapa3.png"));

    return app.exec();
}
