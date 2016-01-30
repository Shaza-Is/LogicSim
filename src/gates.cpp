#include "gates.h"

// Qt includes

#include <QDebug>
#include <QPainter>

namespace Logicsim
{

// ===================== AndGate ===================

AndGate::AndGate()
    : GraphicGate(AbstractGate::AndGate)
{
    setMetaTypeId(qRegisterMetaType<AndGate>("AndGate"));
}

AndGate::AndGate(const AndGate &g)
    : GraphicGate(g.gateType())
{
}

QRectF AndGate::boundingRect() const
{
    return QRectF(0,0,40,50);
}

void AndGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawLine(0,0,0,50);
    painter->drawLine(0,0,20,0);
    painter->drawLine(0,50,20,50);
    painter->drawArc(QRect(0,0,40,50), -1400, 3000);
}

void AndGate::calcOutput()
{
    bool out = true;
    foreach (Node * n, inputList())
    {
        out &= n->value();
    }

    outputNode()->setValue(out);
}

QString AndGate::imageUrl() const
{
    return QString(":/gates/and");
}

// ===================== OrGate ===================

OrGate::OrGate()
    : GraphicGate(AbstractGate::OrGate)
{
    setMetaTypeId(qRegisterMetaType<OrGate>("OrGate"));
}

OrGate::OrGate(const OrGate &g)
    : GraphicGate(g.gateType())
{
}

void OrGate::calcOutput()
{
    bool out = false;
    foreach (Node * n, inputList())
    {
        out |= n->value();
    }

    outputNode()->setValue(out);
}

QString OrGate::imageUrl() const
{
    return QString(":/gates/or");
}

void OrGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawArc(QRect(-20,0,25,60), -700, 1400);
}

// ===================== NotGate ===================

NotGate::NotGate()
    : GraphicGate(AbstractGate::NotGate)
{
    setMaxInput(1);
    setMetaTypeId(qRegisterMetaType<NotGate>("NotGate"));
}

NotGate::NotGate(const NotGate &g)
    : GraphicGate(g.gateType())
{
}

void NotGate::calcOutput()
{
    bool out = inputList()[0]->value();
    outputNode()->setValue(!out);
}

QString NotGate::imageUrl() const
{
    return QString(":/gates/not");
}

void NotGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawLine(0,0,0,50);
    painter->drawLine(0,0,35,27);
    painter->drawLine(0,50,35,27);
    painter->drawEllipse(35,25,5,5);
}

// ===================== NandGate ===================

NandGate::NandGate()
    : GraphicGate(AbstractGate::NandGate)
{
    setMetaTypeId(qRegisterMetaType<NandGate>("NandGate"));
}

NandGate::NandGate(const NandGate &g)
    : GraphicGate(g.gateType())
{
}

void NandGate::calcOutput()
{
    bool out = true;
    foreach (Node * n, inputList())
    {
        out &= n->value();

    }

    outputNode()->setValue(!out);
}

QString NandGate::imageUrl() const
{
    return QString(":/gates/nand");
}


void NandGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawLine(0,0,0,50);
    painter->drawLine(0,0,17,0);
    painter->drawLine(0,50,17,50);
    painter->drawArc(QRect(-4,0,40,50), -1400, 3000);
    painter->drawEllipse(35,25,5,5);


}

// ===================== NorGate ===================



NorGate::NorGate()
    : GraphicGate(AbstractGate::NorGate)
{
    setMetaTypeId(qRegisterMetaType<NorGate>("NorGate"));
}

NorGate::NorGate(const NorGate &g)
    : GraphicGate(g.gateType())
{
}

void NorGate::calcOutput()
{
    bool out = false;
    foreach (Node * n, inputList())
    {
        out |= n->value();

    }

    outputNode()->setValue(!out);
}

QString NorGate::imageUrl() const
{
    return QString(":/gates/nor");
}

void NorGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

  painter->drawArc(QRect(-22,-5,25,60), -800, 1500);
  painter->drawArc(QRect(-23,-2,60,50), -1700, 1500);
  painter->drawArc(QRect(-23,4,60,50),  200, 1500);
  painter->drawEllipse(36,24,5,5);


}

} // namespace Logicsim
