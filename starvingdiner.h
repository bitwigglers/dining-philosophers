#ifndef DINERTABLE_H
#define DINERTABLE_H

#include "starvingphilosopher.h"
#include <QObject>
#include <QHash>

class StarvingDiner : public QObject
{
    Q_OBJECT
public:
    explicit StarvingDiner(QObject *parent = 0);

public slots:
    void philStateChanged(State);

private:
    StarvingPhilosopher* phils[5];
    QHash<StarvingPhilosopher*, QString> philHash;
    void update();
};

#endif // DINERTABLE_H
