#include "philosopher.h"
#include <QTime>

void Philosopher::run()
{
    while(1) {
        think();
        eat();
    }
}

Philosopher::Philosopher(const QString &name, QObject *parent)
    : QThread(parent), m_name(name), m_neighbor(NULL)
{
}

const QString& Philosopher::name() const
{
    return m_name;
}

void Philosopher::setNeighbor(Philosopher *neighbor)
{
    m_neighbor = neighbor;
}
