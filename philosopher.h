#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <QThread>
#include <QMutex>

namespace Act {
    enum Activity{ActThinking = 0x1,
         ActStarving = 0x2,
         ActEating = 0x4};
    Q_DECLARE_FLAGS(Activities, Activity)

    Q_DECLARE_OPERATORS_FOR_FLAGS(Act::Activities)
}

class Philosopher : public QThread
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    Q_FLAGS(Activity Activities)

    Philosopher(const QString& name, QObject *parent = 0);
    Philosopher(QObject *parent = 0);

    void run();
    const QString& name() const;
    void setName(const QString&);
    void setNeighbor(Philosopher *neighbor);

signals:
    void activitiesChanged(Act::Activities);

protected:        
    virtual void think();
    virtual void eat();
    virtual bool acquireFork();
    virtual void releaseFork();

private:
    QString m_name;
    Philosopher *m_neighbor;
    Act::Activities m_activities;
    QMutex forkMutex;

    void wasteCpuCycles();
};

#endif // PHILOSOPHER_H
