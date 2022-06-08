#include "eventfilter.h"

#include <QEvent>
#include <QWheelEvent>

EventFilter::EventFilter(QObject *parent) :
QObject(parent)
{
}

bool EventFilter::eventFilter(QObject *obj, QEvent *event)
{

    if (event->type() == QEvent::Wheel)
    {
      QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);
      return true;
    }
    else
    {
      // standard event processing
      return QObject::eventFilter(obj, event);
    }
}
