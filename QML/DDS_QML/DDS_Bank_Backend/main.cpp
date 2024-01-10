#include <iostream>

#include "application.hpp"
#include "subscriber.hpp"

using namespace std;
using namespace application;


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

    std::shared_ptr<Subscriber> subscriber;

    try {
        subscriber = std::make_shared<Subscriber>(arguments.domain_id, arguments.sample_count);
    } catch (const std::exception& ex) {
        // All DDS exceptions inherit from std::exception
        std::cerr << "Exception in run_example(): " << ex.what()
                  << std::endl;
        return EXIT_FAILURE;
    }

    while(!shutdown_requested)
    {
        subscriber->wait(dds::core::Duration(4));
    }

    // Releases the memory used by the participant factory.  Optional at
    // application shutdown
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
