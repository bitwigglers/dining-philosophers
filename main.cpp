#include <QtCore/QCoreApplication>
#include <QMetaType>
#include "dinertable.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qRegisterMetaType<State>("State");
    StarvingDiner diner;

    return a.exec();
}
