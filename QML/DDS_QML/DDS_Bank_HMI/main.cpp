#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "scene_creator.hpp"
#include "publisher.hpp"

using namespace application;

int main(int argc, char *argv[]) {

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);
    std::shared_ptr<Publisher> publisher;
    try {
        publisher =  std::make_shared<Publisher>(arguments.domain_id, arguments.sample_count);

    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in publisher: " << ex.what()
                  << std::endl;
        return EXIT_FAILURE;
    }

    // Releases the memory used by the participant factory.  Optional at
    // application shutdown
    //dds::domain::DomainParticipant::finalize_participant_factory();

    //
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;
    auto sceneCreator = std::make_shared<SceneCreator>(engine, publisher);
    sceneCreator->createScene();

    return app.exec();
}
