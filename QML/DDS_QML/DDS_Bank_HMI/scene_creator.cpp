#include "scene_creator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, std::shared_ptr<Publisher> publisher, QObject *parent) :
    QObject(parent),
    m_publisher(publisher),
    m_engine(engine)
{
    // Constructor implementation
}

void SceneCreator::createScene()
{
    createColumn();
    createButton();
}

void SceneCreator::handleButtonClicked()
{
    m_publisher->writeTransaction(FundKind::CLOTHING, OperationKind::FUND, 100);
}

void SceneCreator::createButton()
{
    if(m_itemIDColumn[0])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Button{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParentItem(m_itemIDColumn[0]);
            connect(componentItem, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createColumn()
{
    QObject* rootObject = m_engine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
    if(rootWindow)
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; ColumnLayout{}";
        component.setData(qmlCode.toUtf8(), QUrl());
        QQuickItem *object = qobject_cast<QQuickItem*>(rootWindow->contentItem());
        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(object)
        {
            componentItem->setParentItem(object);
            m_itemIDColumn.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}
