#ifndef SUBSCRIBER_HPP
#define SUBSCRIBER_HPP

#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/config/Logger.hpp>

#include "bank.hpp"

class Subscriber
{
public:
    Subscriber(unsigned int domain_id, unsigned int sample_count);

    void wait(dds::core::Duration seconds);

    void configureTransactionAction();
    void configureResetAction();
    void configureResultTransactionAction();

private:

    dds::domain::DomainParticipant m_domainParticipant;
    dds::sub::Subscriber m_subscriber;

    dds::topic::Topic<Transaction> m_topicTransaction;
    dds::sub::DataReader<Transaction> m_readerTransaction;
    dds::core::cond::StatusCondition m_statusConditionTransaction;

    dds::topic::Topic<Reset> m_topicReset;
    dds::sub::DataReader<Reset> m_readerReset;
    dds::core::cond::StatusCondition m_statusConditionReset;
};

#endif // SUBSCRIBER_HPP
