#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>  // for sleep()
#include <rti/config/Logger.hpp>  // for logging
// Or simply include <dds/dds.hpp>

#include "own_topics.hpp"
#include "application.hpp"  // Argument parsing

using namespace application;

void run_example(unsigned int domain_id, unsigned int sample_count)
{
    // A DomainParticipant allows an application to begin communicating in
    // a DDS domain. Typically there is one DomainParticipant per application.
    // DomainParticipant QoS is configured in USER_QOS_PROFILES.xml(
    dds::domain::DomainParticipant participant (domain_id);

    // A Topic has a name and a datatype. Create a Topic named
    // "HelloWorld Topic" with type HelloWorld
    dds::topic::Topic<OwnMessahe> topic(participant, "OwnMessahe Topic");

    // A Publisher allows an application to create one or more DataWriters
    // Publisher QoS is configured in USER_QOS_PROFILES.xml
    dds::pub::Publisher publisher(participant);

    // This DataWriter will write data on Topic "OwnMessahe Topic"
    // DataWriter QoS is configured in USER_QOS_PROFILES.xml
    dds::pub::DataWriter<OwnMessahe> writer(publisher, topic);

    // Create data sample for writing
    OwnMessahe sample;
    for (unsigned int count = 0;
         !shutdown_requested && count < sample_count;
         count++) {
        // Modify the data to be written here
        sample.msg("HelloWorld! " + std::to_string(count));

        std::cout << "Writing HelloWorld, count " << count << std::endl;

        writer.write(sample);

        rti::util::sleep(dds::core::Duration(4));
    }
}


int main(int argc, char *argv[])
{

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

    try {
        run_example(arguments.domain_id, arguments.sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_example(): " << ex.what()
                  << std::endl;
        return EXIT_FAILURE;
    }

    // Releases the memory used by the participant factory.  Optional at
    // application shutdown
    dds::domain::DomainParticipant::finalize_participant_factory();

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



    return app.exec();
}
