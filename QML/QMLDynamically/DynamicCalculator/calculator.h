#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QPushButton>
#include <functional>

class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QQmlApplicationEngine& engine, QObject *parent = nullptr);

signals:
    void buttonCliked();

public slots:
    QQuickItem* createCalculator(QSize size, QPoint position);
    void numberButtonClick();
    void handleButtonClicked();

private:
    void initializeComponentMap();
    QQuickItem* createButton(QQuickItem* myParent, QString myObjectName, QString text, QPoint position = QPoint(0,0));
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

#endif // CALCULATOR_H
