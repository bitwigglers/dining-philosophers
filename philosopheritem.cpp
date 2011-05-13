#include "philosopheritem.h"
#include <QPainter>

PhilosopherItem::PhilosopherItem(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    // need to disable this flag to draw inside a QDeclarativeItem
    setFlag(QGraphicsItem::ItemHasNoContents, false);

    connect(&m_phil, SIGNAL(activitiesChanged(Act::Activities)), this, SLOT(changeActivities(Act::Activities)), Qt::QueuedConnection);
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

void PhilosopherItem::changeActivities(Act::Activities activities)
{
    m_activities = activities;
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
    painter->setRenderHints(QPainter::Antialiasing, true);

    if (m_activities & Act::ActThinking) {
        painter->setBrush(Qt::blue);
        painter->drawEllipse(boundingRect());

        if (m_activities & Act::ActStarving) {
            painter->setBrush(Qt::red);
            painter->drawPie(boundingRect(), 90 * 16, 180 * 16);
        }
    } else if (m_activities & Act::ActEating) {
        painter->setBrush(Qt::green);
        painter->drawEllipse(boundingRect());
    }
    painter->drawText(boundingRect(), Qt::AlignCenter, m_phil.name());
}
