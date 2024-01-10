#include "bankmodel.hpp"

BankModel::BankModel()
{
    resetAllBuckets();
}

void BankModel::deposit(BucketType bucket, int money)
{
    m_savingsByBucketType[bucket] += money;
}

void BankModel::withdraw(BucketType bucket, int money)
{
    m_savingsByBucketType[bucket] -= money;
}

void BankModel::resetBucket(BucketType bucket)
{
    m_savingsByBucketType[bucket] = 0;
}

void BankModel::resetAllBuckets()
{
   resetBucket(BucketType::Savings);
   resetBucket(BucketType::Housing);
   resetBucket(BucketType::Food);
   resetBucket(BucketType::Transportation);
   resetBucket(BucketType::Entertainment);
   resetBucket(BucketType::Travel);
   resetBucket(BucketType::Clothing);
   resetBucket(BucketType::Debts);
   resetBucket(BucketType::Car);
}
