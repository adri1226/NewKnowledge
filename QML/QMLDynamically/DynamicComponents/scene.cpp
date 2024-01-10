#include "scene.h"

Scene::Scene(QQmlApplicationEngine &engine, QObject *parent) : QObject(parent),  m_engine(engine)
{

}

void Scene::create_rect_object(QPointF position)
{
    QObject* rootObject = m_engine.rootObjects().first(); // Obtengo lo que es el objeto Window, la raiz
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject); // Aqui tengo el objeto como tipo ventana

    // Creo el nuevo componente basado en mi archivo
    QQmlComponent rectangleComponent(&m_engine, QUrl("qrc:/myrect.qml")); // Cargo mi componente
    QObject* rectangleObject = rectangleComponent.create(); // Creo mi QObject
    QQuickItem* rectangleItem = qobject_cast<QQuickItem*>(rectangleObject); // Creo mi QQuickItem
        // Se usa QQuickItem porque es la clase base para elementos visuales en Qt Quick

    // Establezco el padre como la ventana
    rectangleItem->setParentItem(rootWindow->contentItem());

    // Establezco las propiedades que quiera
    rectangleItem->setProperty("color", QColor(Qt::darkMagenta).name());
    rectangleItem->setPosition(position);
}
