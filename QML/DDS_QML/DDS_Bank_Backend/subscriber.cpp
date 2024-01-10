#include "subscriber.hpp"

Subscriber::Subscriber(unsigned int domain_id, unsigned int sample_count):
    m_domainParticipant(domain_id),
    m_subscriber(m_domainParticipant),
    m_topicTransaction(m_domainParticipant, TRANSACTION_TOPIC),
    m_readerTransaction(m_subscriber, m_topicTransaction),
    m_statusConditionTransaction(m_readerTransaction),
    m_topicReset(m_domainParticipant, RESET_TOPIC),
    m_readerReset(m_subscriber, m_topicReset),
    m_statusConditionReset(m_readerReset)
{
    m_statusConditionTransaction.enabled_statuses(dds::core::status::StatusMask::data_available());
    m_statusConditionReset.enabled_statuses(dds::core::status::StatusMask::data_available());

    // What i do when i recibe a sample
    m_statusConditionTransaction.extensions().handler(std::bind(&Subscriber::configureTransactionAction, *this));
}

void Subscriber::wait(dds::core::Duration seconds)
{
    dds::core::cond::WaitSet waitset;
    waitset += m_statusConditionTransaction;

    waitset.dispatch(seconds);
}

void Subscriber::configureTransactionAction()
{
    dds::sub::LoanedSamples<Transaction> samples = m_readerTransaction.take();
    for(auto sample : samples)
    {
        if(sample.info().valid())
        {
            std::cout << "Sample obtenido: " << std::endl;
            std::cout << "\t" << sample.data() << std::endl;
        }
    }
}
