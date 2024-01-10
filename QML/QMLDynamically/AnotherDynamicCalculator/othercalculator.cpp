#include "othercalculator.h"

OtherCalculator::OtherCalculator(QQmlApplicationEngine& engine, QObject *parent) : QObject(parent), m_engine(engine)
{
    auto rootObjects = m_engine.rootObjects();
    m_rootObject = rootObjects.first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(m_rootObject);
    m_rootItem = qobject_cast<QQuickItem*>(rootWindow->contentItem());

    initializeComponentMap();
}

void OtherCalculator::initializeComponentMap()
{
    m_componentsMap["rectangle"] = "import QtQuick 2.0; Rectangle{}";
    m_componentsMap["button"] = "import QtQuick 2.0; import QtQuick.Controls 2.5; Button{}";
    m_componentsMap["row"] = "import QtQuick 2.0; import QtQuick.Controls 2.5; Row{}";
    m_componentsMap["column"] = "import QtQuick 2.0; import QtQuick.Controls 2.5; Column{}";
}

void OtherCalculator::numberButtonClick(/*int number*/)
{
    qDebug() << "Pulsado un boton de numero "/* + QString::number(number)*/;
}

QQuickItem *OtherCalculator::createButton(QQuickItem* myParent, QString myObjectName, QString text, int numberPad, QPoint position)
{
    QQmlComponent component(&m_engine, QUrl(QStringLiteral("qrc:/main.qml")));
    component.setData(m_componentsMap["button"].toUtf8(), QUrl());
    QObject* object = component.create();
    QQuickItem* item = qobject_cast<QQuickItem*>(object);

    // qobject_cast<QQuickItem*>(object); no se hace porque no funciona bien, esto se hace con la ventana del padre o pasando directamente el Item

    if(myParent != nullptr)
    {
        item->setParent(myParent);
        item->setParentItem(qobject_cast<QQuickItem*>(myParent));
    }

    item->setObjectName(myObjectName);
    item->setSize(QSize(100, 100));
    item->setPosition(position);
    item->setProperty("text", text);

    return item;
}

QQuickItem *OtherCalculator::createRow(QQuickItem *myParent, QString myObjectName, QPoint position, const QList<QQuickItem *> children)
{
    QQmlComponent component(&m_engine, QUrl(QStringLiteral("qrc:/main.qml")));
    component.setData(m_componentsMap["row"].toUtf8(), QUrl());
    QObject* object = component.create();
    QQuickItem* item = qobject_cast<QQuickItem*>(object);

    item->setParent(myParent);
    item->setParentItem(qobject_cast<QQuickItem*>(myParent));

    item->setObjectName(myObjectName);
    item->setPosition(position);
    item->setProperty("spacing", 5);

    if(!children.isEmpty())
    {
        for(auto child: children)
        {
            child->setParent(item);
            child->setParentItem(item);
        }
    }

    return item;
}

QQuickItem *OtherCalculator::createColumn(QQuickItem *myParent, QString myObjectName, QPoint position, const QList<QQuickItem *> children)
{
    QQmlComponent component(&m_engine, QUrl(QStringLiteral("qrc:/main.qml")));
    component.setData(m_componentsMap["column"].toUtf8(), QUrl());
    QObject* object = component.create();
    QQuickItem* item = qobject_cast<QQuickItem*>(object);

    item->setParent(myParent);
    item->setParentItem(qobject_cast<QQuickItem*>(myParent));

    item->setObjectName(myObjectName);
    item->setPosition(position);
    item->setProperty("spacing", 5);

    if(!children.isEmpty())
    {
        for(auto child: children)
        {
            child->setParent(item);
            child->setParentItem(item);
        }
    }

    return item;
}

QQuickItem *OtherCalculator::createRectangle(QQuickItem *myParent, QString myObjectName, QColor color, QPoint position)
{
    QQmlComponent component(&m_engine, QUrl(QStringLiteral("qrc:/main.qml")));
    component.setData(m_componentsMap["rectangle"].toUtf8(), QUrl());
    QObject* object = component.create();
    QQuickItem* item = qobject_cast<QQuickItem*>(object);

    // qobject_cast<QQuickItem*>(object); no se hace porque no funciona bien, esto se hace con la ventana del padre o pasando directamente el Item

    if(myParent != nullptr)
    {
        item->setParent(myParent);
        item->setParentItem(qobject_cast<QQuickItem*>(myParent));
    }

    item->setObjectName(myObjectName);
    item->setSize(QSize(100, 100));
    item->setPosition(position);
    item->setProperty("color", color);

    return item;
}

QQuickItem* OtherCalculator::createCalculator(QSize size, QPoint position)
{
    QQuickItem* column = createColumn(m_rootItem, "column", position);

    QQuickItem* rowFirst = createRow(column, "rowFirst", position);
    QQuickItem* rowSecond = createRow(column, "rowSecond", position);
    QQuickItem* rowThird = createRow(column, "rowThird", position);

    for(int number = 1; number < 10; number++)
    {
        QQuickItem * parent;

        if(number <= 3)
        {
            parent = rowThird;
        }
        else if(number > 3 && number <= 6)
        {
            parent = rowSecond;
        }
        else
        {
            parent = rowFirst;
        }

        QQuickItem* button = createButton(parent, "button"+QString::number(number), QString::number(number), number);

    }

    return column;

}
