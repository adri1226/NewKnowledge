#ifndef OTHERCALCULATOR_H
#define OTHERCALCULATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <functional>

#include "custombutton.h"

class OtherCalculator : public QObject
{
    Q_OBJECT
public:
    explicit OtherCalculator(QQmlApplicationEngine& engine, QObject *parent = nullptr);

signals:

public slots:
    QQuickItem* createCalculator(QSize size, QPoint position);
    void numberButtonClick(/*int number*/);

private:

    void initializeComponentMap();
    QQuickItem* createButton(QQuickItem* myParent, QString myObjectName, QString text, int numberPad, QPoint position = QPoint(0,0));
    QQuickItem* createRow(QQuickItem* myParent, QString myObjectName, QPoint position = QPoint(0,0),
                       const QList<QQuickItem*> children = QList<QQuickItem*>());
    QQuickItem* createColumn(QQuickItem* myParent, QString myObjectName, QPoint position = QPoint(0,0),
                       const QList<QQuickItem*> children = QList<QQuickItem*>());
    QQuickItem* createRectangle(QQuickItem* myParent, QString myObjectName, QColor color, QPoint position = QPoint(0,0));


    QMap<QString, QString> m_componentsMap;
    QQmlApplicationEngine& m_engine;
    QObject* m_rootObject;
    QQuickItem* m_rootItem;
};

#endif // OTHERCALCULATOR_H
