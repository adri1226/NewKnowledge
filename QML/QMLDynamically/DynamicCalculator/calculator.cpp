#include "calculator.h"

Calculator::Calculator(QQmlApplicationEngine& engine, QObject *parent) : QObject(parent), m_engine(engine)
{
    auto rootObjects = m_engine.rootObjects();
    m_rootObject = rootObjects.first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(m_rootObject);
    m_rootItem = qobject_cast<QQuickItem*>(rootWindow->contentItem());

    initializeComponentMap();
}

QQuickItem* Calculator::createCalculator(QSize size, QPoint position)
{
    // La señal emitida tiene que estar definida en el QML
//    QObject::connect(calculatorItem, SIGNAL(clicked()), this, SLOT(numberButtonClick()));

//    QList<QObject*> allChildrenRoot = m_rootObject->children();
//    allChildrenRoot = m_rootObject->findChildren<QObject*>("q_subRectangle", Qt::FindChildrenRecursively);

//    QObject* buttonCalculator = allChildrenRoot.first();

//    if(buttonCalculator)
//    {
//        QObject::connect(buttonCalculator, SIGNAL(clicked()), this, SLOT(numberButtonClick()));
//    }
//    else
//    {
//        qDebug() << "Error hijo no encontrado";
//    }

//    return calculatorItem;

    QQuickItem* column = createColumn(m_rootItem, "column", position);

    QList<QQuickItem*> toFirstRow = QList<QQuickItem*>();
    QList<QQuickItem*> toSecondRow = QList<QQuickItem*>();
    QList<QQuickItem*> toThirdRow = QList<QQuickItem*>();

    for(int number = 1; number < 10; number++)
    {
        QQuickItem* button = createButton(nullptr, "button"+QString::number(number), QString::number(number));




//        std::function<void ()> function = std::bind(&Calculator::numberButtonClick, this, number);
        QObject::connect(button, SIGNAL(clicked()), this, SLOT(numberButtonClick()));
//        QObject::connect(button, &QAbstractButton::clicked, this, function);
        QObject::connect(button, &QPushButton::clicked, this, [=] (bool checked) {
                 numberButtonClick(number);
             }, Qt::AutoConnection);
//        QObject::connect(button, &QAbstractButton::clicked, this, [=]() {
//            numberButtonClick(number);
//        });
//      QObject::connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
//      QObject::connect(const QObject *button, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
//        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(HttpImageError(Feed)));
//        connect(reply, &QNetworkReply::NetworkError, [this, Feed]() {
//            this->HttpImageError(Feed);
//        });

        if(number <= 3)
        {
            toThirdRow.append(button);
        }
        else if(number > 3 && number <= 6)
        {
            toSecondRow.append(button);
        }
        else
        {
            toFirstRow.append(button);
        }
    }

    createRow(column, "rowFirst", position, toFirstRow);
    createRow(column, "rowSecond", position, toSecondRow);
    createRow(column, "rowThird", position, toThirdRow);

    return column;
}

void Calculator::numberButtonClick()
{
    qDebug() << "Pulsado un boton de numero "/* + QString::number(number)*/;
}

void Calculator::handleButtonClicked()
{
    emit buttonCliked();
}

void Calculator::initializeComponentMap()
{
    m_componentsMap["rectangle"] = "import QtQuick 2.0; Rectangle{}";
    m_componentsMap["button"] = "import QtQuick 2.0; import QtQuick.Controls 2.5; Button{}";
    m_componentsMap["row"] = "import QtQuick 2.0; import QtQuick.Controls 2.5; Row{}";
    m_componentsMap["column"] = "import QtQuick 2.0; import QtQuick.Controls 2.5; Column{}";
}

QQuickItem *Calculator::createButton(QQuickItem* myParent, QString myObjectName, QString text, QPoint position)
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

QQuickItem *Calculator::createRow(QQuickItem *myParent, QString myObjectName, QPoint position, const QList<QQuickItem *> children)
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

QQuickItem *Calculator::createColumn(QQuickItem *myParent, QString myObjectName, QPoint position, const QList<QQuickItem *> children)
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

QQuickItem *Calculator::createRectangle(QQuickItem *myParent, QString myObjectName, QColor color, QPoint position)
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


