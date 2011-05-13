#ifndef PHILOSOPHERITEM_H
#define PHILOSOPHERITEM_H

#include <QDeclarativeItem>
#include "philosopher.h"

class PhilosopherItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(PhilosopherItem* neighbor READ neighbor WRITE setNeighbor)

public:
    PhilosopherItem(QDeclarativeItem *parent = 0);

    QString name() const;
    void setName(const QString &name);

    PhilosopherItem* neighbor();
    void setNeighbor(PhilosopherItem*);
    Philosopher* philosopher();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

signals:

public slots:
    void changeActivities(Act::Activities);

private:
    QString m_name;
    Philosopher m_phil;
    Act::Activities m_activities;
    unsigned long m_bites;
};

#endif // PHILOSOPHERITEM_H
