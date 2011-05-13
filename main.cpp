#include <QApplication>
#include <QMetaType>
#include <QDeclarativeView>
#include "philosopheritem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<Act::Activities>("Act::Activities");
    qmlRegisterType<PhilosopherItem>("Philosophers", 1, 0, "Philosopher");

    QDeclarativeView view;
    view.setSource(QUrl::fromLocalFile("app.qml"));
    view.show();

    return a.exec();
}
