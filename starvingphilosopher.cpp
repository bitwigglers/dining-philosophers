#include "starvingphilosopher.h"
#include <cstdlib>

StarvingPhilosopher::StarvingPhilosopher(const QString &name, QObject *parent)
    : Philosopher(name, parent)
{

}

void StarvingPhilosopher::think()
{
    m_state = StateThinking;
    emit stateChanged(m_state);
    float t = ((float)qrand() / (float)RAND_MAX) * 10;
    sleep(t);
}

void StarvingPhilosopher::eat()
{
    m_state = StateHungry;
    emit stateChanged(m_state);

    acquireFork();
    qobject_cast<StarvingPhilosopher*>(m_neighbor)->acquireFork();

    m_state = StateEating;
    emit stateChanged(m_state);
    float t = ((float)qrand() / (float)RAND_MAX) * 10;
    sleep(t);

    releaseFork();
    qobject_cast<StarvingPhilosopher*>(m_neighbor)->releaseFork();
}

void StarvingPhilosopher::acquireFork()
{
    forkMutex.lock();
}

void StarvingPhilosopher::releaseFork()
{
    forkMutex.unlock();
}
