#include "component.h"

// Qt includes

#include <QPainter>

// Local includes

#include "logicsim_global.h"

namespace Logicsim
{

class Component::Private
{
public:
    Private()
    {}

    int             metaTypeId;
    Component::Type type;
    bool            selected;
    QString         name;
};

Component::Component(Type t, QGraphicsItem* parent)
    : QGraphicsObject(parent), d(new Private)
{
    d->type = t;
    d->selected = false;
}

Component::~Component()
{
    delete d;
}

void Component::setMetaTypeId(int t)
{
    d->metaTypeId = t;
}

int Component::metaTypeId() const
{
    return d->metaTypeId;
}

Component::Type Component::componentType() const
{
    return d->type;
}

QRectF Component::boundingRect() const
{
    return QRectF(0,0,40,50);
}

void Component::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(QColor(255,255,255,200));

    QPen p;
    p.setWidthF(2);
    if(d->selected)
    {
        p.setColor(QColor(30,144,255));
        painter->setPen(p);
    }
    else
    {
        p.setColor(Qt::black);
        painter->setPen(p);
    }
}

void Component::setSelection(bool selection)
{
    d->selected = selection;
    update();
}

QString Component::name()
{
    return d->name;
}

void Component::setName(QString name)
{
    d->name = name;
    setToolTip(name);
}

} // namespace Logicsim
