#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Imports necesarios para comunicar C++ con QML
#include <QQmlContext>
#include "test.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    // Aqui ponemos los atributos
    // AA_EnableHighDpiScaling es para escalar algunos atributos a diferentes resoluciones de pantalla
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    // El engine que se encarga de cargar el archivo y de que todo funcione
    QQmlApplicationEngine engine;

    // Añadimos el root context
    // engine.rootObjects() - Lista con todos los objetos que instancia el engine
    // engine.rootContext() - Propiedades y objetos disponibles del root
    Test test;
    engine.rootContext()->setContextProperty("testing", &test);

    // La URL del archivo de QML, que es un archivo compilado
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    // Aqui se conecta una señal con un slot - se comprueba que el objeto y la url coinciden
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // El motor carga el archivo QML
    engine.load(url);

    return app.exec();
}
