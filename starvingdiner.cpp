#include "starvingdiner.h"

#include <QDebug>
#include <iostream>
#include <iomanip>

StarvingDiner::StarvingDiner(QObject *parent) :
    QObject(parent)
{
    // create 5 philosophers and place them around the table
    phils[0] = new StarvingPhilosopher("Aristoteles");
    phils[1] = new StarvingPhilosopher("Descartes");
    phils[2] = new StarvingPhilosopher("Russell");
    phils[3] = new StarvingPhilosopher("Hegel");
    phils[4] = new StarvingPhilosopher("Kant");

    phils[0]->setNeighbor(phils[1]);
    phils[1]->setNeighbor(phils[2]);
    phils[2]->setNeighbor(phils[3]);
    phils[3]->setNeighbor(phils[4]);
    phils[4]->setNeighbor(phils[0]);

    for (int i = 0; i < 5; ++i)
        connect(phils[i], SIGNAL(stateChanged(State)), this, SLOT(philStateChanged(State)));

    for (int i = 0; i < 5; ++i)
        phils[i]->start();
}

void StarvingDiner::philStateChanged(State state)
{
    StarvingPhilosopher *phil = qobject_cast<StarvingPhilosopher*>(sender());
    if (!phil)
        return;

    switch (state) {
    case StateThinking:
        philHash[phil] = "Thinking";
        break;
    case StateHungry:
        philHash[phil] = "Hungry";
        break;
    case StateEating:
        philHash[phil] = "Eating";
        break;
    }

    update();
}

void StarvingDiner::update()
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Name: " << std::setw(12) << phils[i]->name().toStdString();
        std::cout << "\tState: " << philHash[phils[i]].toStdString() << "\n";
    }
    std::cout << "\n****************************************\n";
}
