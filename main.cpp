#include <QApplication>

#include "janelaprincipal.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    JanelaPrincipal janela(QPixmap(":/images/grass.jpg"));

    return app.exec();
}
