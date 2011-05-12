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
    volatile int i = qrand();
    while(i--);
}

void Philosopher::think()
{
    m_state = StateThinking;
    emit stateChanged(m_state);
    wasteCpuCycles();
}

void Philosopher::eat()
{
    m_state = StateHungry;
    emit stateChanged(m_state);

    acquireFork();
    m_neighbor->acquireFork();

    m_state = StateEating;
    emit stateChanged(m_state);
    wasteCpuCycles();

    releaseFork();
    m_neighbor->releaseFork();
}

void Philosopher::acquireFork()
{
    forkMutex.lock();
}

void Philosopher::releaseFork()
{
    forkMutex.unlock();
}
