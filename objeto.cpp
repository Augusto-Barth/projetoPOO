#include "objeto.h"

Objeto::Objeto(QGraphicsItem* parent) : QGraphicsItem(parent)
{

}

QString Objeto::tipo(){
    return tipoObjeto;
}
