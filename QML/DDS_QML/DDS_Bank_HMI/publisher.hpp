#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>  // for sleep()
#include <rti/config/Logger.hpp>  // for logging
// Or simply include <dds/dds.hpp>
#include "bank.hpp"
#include "application.hpp"  // Argument parsing

#include <QDebug>

class Publisher
{
public:
    Publisher(unsigned int domain_id, unsigned int sample_count);
    const Transaction writeTransaction(const FundKind &fund_type, const OperationKind &operation_type, int16_t amount);
private:
    unsigned int m_domain_id;
    unsigned int m_sample_count;
    dds::domain::DomainParticipant m_participant;
    dds::pub::Publisher m_publisher;
    dds::topic::Topic<HelloWorld> m_topic;
    dds::topic::Topic<Reset> m_topicReset;
    dds::topic::Topic<Transaction> m_topicTransaction;
    dds::pub::DataWriter<HelloWorld> m_writer;
    dds::pub::DataWriter<Transaction> m_writerTransaction;
    dds::pub::DataWriter<Reset> m_writerReset;
};

#endif // PUBLISHER_HPP
