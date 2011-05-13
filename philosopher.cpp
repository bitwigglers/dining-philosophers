#include "philosopher.h"
#include <cstdlib>
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

Philosopher::Philosopher(QObject *parent)
    : QThread(parent), m_name("John Doe"), m_neighbor(NULL)
{
}

const QString& Philosopher::name() const
{
    return m_name;
}

void Philosopher::setName(const QString & name)
{
    m_name = name;
}

void Philosopher::setNeighbor(Philosopher *neighbor)
{
    m_neighbor = neighbor;
}

void Philosopher::wasteCpuCycles()
{
    volatile int i = 0x7ffffff;
    while(i--);
}

void Philosopher::think()
{
    m_activities |= Act::ActThinking;
    m_activities &= ~Act::ActEating;

    emit activitiesChanged(m_activities);
    wasteCpuCycles();
}

void Philosopher::eat()
{
    m_activities |= Act::ActStarving;
    m_activities &= ~Act::ActThinking;
    emit activitiesChanged(m_activities);

    if (!acquireFork())
        return;

    if (!m_neighbor->acquireFork()) {
        releaseFork();
        return;
    }

    m_activities |= Act::ActEating;
    m_activities &= ~Act::ActStarving;
    emit activitiesChanged(m_activities);
    wasteCpuCycles();

    releaseFork();
    m_neighbor->releaseFork();
}

bool Philosopher::acquireFork()
{
    return forkMutex.tryLock();
}

void Philosopher::releaseFork()
{
    forkMutex.unlock();
}
