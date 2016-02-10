#ifndef GRAPHICGATE_H
#define GRAPHICGATE_H

// Qt includes

#include <QGraphicsObject>
#include <QPainter>

// Local includes

#include "abstractgate.h"

namespace Logicsim
{

class GraphicGate : public QGraphicsObject, public AbstractGate
{
public:
    GraphicGate(AbstractGate::Type t, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void setSelection(bool selection);

private:
    bool selected;
};

} // namespace Logicsim

#endif // GRAPHICGATE_H
