#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QQmlApplicationEngine& engine, QObject *parent = nullptr);
    QQmlApplicationEngine& m_engine;

public slots:
    void create_rect_object(QPointF position);

};

#endif // SCENE_H
