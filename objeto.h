#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsItem>
#include <QString>

class Objeto : public QGraphicsItem
{
private:
public:
    Objeto(QGraphicsItem *parent = nullptr);

    virtual QString tipo() = 0;
    virtual bool atravessavel() = 0;
    virtual QRectF boundingRect() const = 0;
    virtual QPainterPath shape() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
};

#endif // OBJETO_H
