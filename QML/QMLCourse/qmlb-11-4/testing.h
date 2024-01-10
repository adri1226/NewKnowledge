#ifndef TESTING_H
#define TESTING_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QRandomGenerator>

class Testing : public QObject
{
    Q_OBJECT
public:
    explicit Testing(QObject *parent = nullptr);

signals:
    void status(QVariant data);

public slots:
    void work(QVariant data);
};

#endif // TESTING_H
