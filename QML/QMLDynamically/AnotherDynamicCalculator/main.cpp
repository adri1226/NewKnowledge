#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "othercalculator.h"
#include "custombutton.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    OtherCalculator calc(engine);
    calc.createCalculator(QSize(20,20), QPoint(0,0));

    auto rootObjects = engine.rootObjects();
    auto rootObject = rootObjects.first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
    auto rootItem = qobject_cast<QQuickItem*>(rootWindow->contentItem());

    PadButton* button = new PadButton();
    button->setParentItem(rootItem);
    button->setSize(QSize(100, 100));
    button->setPosition(QPoint(400, 100));
    button->setProperty("color", "red");



    return app.exec();
}
