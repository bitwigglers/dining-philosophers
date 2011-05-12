#ifndef PHILOSOPHERITEM_H
#define PHILOSOPHERITEM_H

#include <QDeclarativeItem>
#include "philosopher.h"

class PhilosopherItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(PhilosopherItem* neighbor READ neighbor WRITE setNeighbor)

public:
    PhilosopherItem(QDeclarativeItem *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QColor color() const;
    void setColor(const QColor &color);

    PhilosopherItem* neighbor();
    void setNeighbor(PhilosopherItem*);
    Philosopher* philosopher();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

signals:

public slots:
    void changeState(State);

private:
    QString m_name;
    QColor m_color;
    Philosopher m_phil;
};

#endif // PHILOSOPHERITEM_H
