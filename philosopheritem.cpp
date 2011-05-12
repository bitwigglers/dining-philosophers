#include "philosopheritem.h"
#include <QPainter>

PhilosopherItem::PhilosopherItem(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    // need to disable this flag to draw inside a QDeclarativeItem
    setFlag(QGraphicsItem::ItemHasNoContents, false);

    connect(&m_phil, SIGNAL(stateChanged(State)), this, SLOT(changeState(State)), Qt::QueuedConnection);
}

QString PhilosopherItem::name() const
{
    return m_phil.name();
}

void PhilosopherItem::setName(const QString &name)
{
    m_phil.setName(name);
}

QColor PhilosopherItem::color() const
{
    return m_color;
}

void PhilosopherItem::setColor(const QColor &color)
{
    m_color = color;
}

void PhilosopherItem::changeState(State state)
{
    switch(state) {
    case StateThinking: m_color = Qt::yellow; break;
    case StateHungry:   m_color = Qt::red; break;
    case StateEating:   m_color = Qt::green; break;
    }
    update();
}

PhilosopherItem* PhilosopherItem::neighbor()
{
    return this;
}

void PhilosopherItem::setNeighbor(PhilosopherItem* item)
{
    m_phil.setNeighbor(item->philosopher());
    m_phil.start();
}

Philosopher* PhilosopherItem::philosopher()
{
    return &m_phil;
}

void PhilosopherItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QBrush brush(m_color);
    painter->setBrush(brush);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawEllipse(boundingRect());
    painter->drawText(boundingRect(), Qt::AlignCenter, m_phil.name());
}
