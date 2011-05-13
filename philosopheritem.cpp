#include "philosopheritem.h"
#include <QPainter>

PhilosopherItem::PhilosopherItem(QDeclarativeItem *parent) :
    QDeclarativeItem(parent), m_bites(0)
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
    if (m_activities & Act::ActEating)
        m_bites++;
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
        painter->setBrush(QColor(Qt::blue).lighter());
        painter->drawEllipse(boundingRect());

        if (m_activities & Act::ActStarving) {
            painter->setBrush(QColor(Qt::red).lighter());
            painter->drawPie(boundingRect(), 45 * 16, 180 * 16);
        }
    } else if (m_activities & Act::ActEating) {
        painter->setBrush(QColor(Qt::green).lighter());
        painter->drawEllipse(boundingRect());
    }
    painter->drawText(boundingRect(), Qt::AlignCenter, m_phil.name() + '\n' + QString::number(m_bites));
}
