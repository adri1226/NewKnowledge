#ifndef SCENECREATOR_HPP
#define SCENECREATOR_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QObject>
#include <QVector>
#include "publisher.hpp"

class SceneCreator : public QObject
{
    Q_OBJECT
public:
    SceneCreator(QQmlApplicationEngine &engine, std::shared_ptr<Publisher> publisher, QObject *parent = nullptr);
    void createScene();
public slots:
    void handleButtonClicked();
private:
    QQmlApplicationEngine &m_engine;
    QVector<QQuickItem*> m_itemIDColumn;
    void createButton();
    void createColumn();
    std::shared_ptr<Publisher> m_publisher;
};

#endif // SCENECREATOR_HPP
