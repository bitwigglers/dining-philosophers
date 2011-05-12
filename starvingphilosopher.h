#ifndef STARVINGPHILOSOPHER_H
#define STARVINGPHILOSOPHER_H

#include "philosopher.h"
#include <QMutex>

class StarvingPhilosopher : public Philosopher
{
    Q_OBJECT

public:
    explicit StarvingPhilosopher(const QString& name, QObject *parent = 0);

protected:
    virtual void think();
    virtual void eat();
    virtual void acquireFork();
    virtual void releaseFork();
    QMutex forkMutex;
};

#endif // STARVINGPHILOSOPHER_H
