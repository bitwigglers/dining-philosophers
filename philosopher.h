#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <QThread>
#include <QMutex>

enum State{StateThinking, StateHungry, StateEating};

class Philosopher : public QThread
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)

public:
    Philosopher(const QString& name, QObject *parent = 0);
    Philosopher(QObject *parent = 0);

    void run();
    const QString& name() const;
    void setName(const QString&);
    void setNeighbor(Philosopher *neighbor);

signals:
    void stateChanged(State);

protected:        
    virtual void think();
    virtual void eat();
    virtual bool acquireFork();
    virtual void releaseFork();

private:
    QString m_name;
    Philosopher *m_neighbor;
    State m_state;
    QMutex forkMutex;

    void wasteCpuCycles();
};

#endif // PHILOSOPHER_H
