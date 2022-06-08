#include <QApplication>

#include "janelaprincipal.h"
#include <QIcon>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    JanelaPrincipal* janela = JanelaPrincipal::getInstancia();
//    janela->setImagem(QPixmap(":/images/mapa3.png"));
    app.setWindowIcon(QIcon(":/images/icone.png"));
    return app.exec();
}
