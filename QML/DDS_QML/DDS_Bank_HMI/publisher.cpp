#include "publisher.hpp"

Publisher::Publisher(unsigned int domain_id, unsigned int sample_count)
    : m_domain_id(domain_id),
      m_sample_count(sample_count),
      m_participant(domain_id),
      m_publisher(m_participant),
      m_topic(m_participant, "HelloWorld Topic"),
      m_topicTransaction(m_participant, TRANSACTION_TOPIC),
      m_topicReset(m_participant, RESET_TOPIC),
      m_writer(m_publisher, m_topic),
      m_writerTransaction(m_publisher, m_topicTransaction),
      m_writerReset(m_publisher, m_topicReset)
{
    // Aquí puedes realizar otras inicializaciones si es necesario
}

const Transaction Publisher::writeTransaction(const FundKind& fund_type, const OperationKind& operation_type, int16_t amount)
{
    Transaction sampleTransaction(fund_type, operation_type, amount);
    m_writerTransaction.write(sampleTransaction);
    qDebug() << "topic sended: " << static_cast<int>(sampleTransaction.fund_type()) << " " << static_cast<int>(sampleTransaction.operation_type()) << " " << sampleTransaction.amount();
    return sampleTransaction;
}

