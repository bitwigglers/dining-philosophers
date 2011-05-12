#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <QThread>

enum State{StateThinking, StateHungry, StateEating};

class Philosopher : public QThread
{
    Q_OBJECT

public:
    explicit Philosopher(const QString& name, QObject *parent = 0);
    void run();
    const QString& name() const;
    void setNeighbor(Philosopher *neighbor);

signals:
    void stateChanged(State);

protected:
    virtual void think() = 0;
    virtual void eat() = 0;

    QString m_name;
    Philosopher *m_neighbor;
    State m_state;
};

#endif // PHILOSOPHER_H
