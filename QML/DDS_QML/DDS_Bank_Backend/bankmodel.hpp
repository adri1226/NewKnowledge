#ifndef BANKMODEL_H
#define BANKMODEL_H

#include <map>
#include "buckettype.hpp"

class BankModel
{
public:
    BankModel();
    void deposit(BucketType bucket, int money);
    void withdraw(BucketType bucket, int money);
    void resetBucket(BucketType bucket);
    void resetAllBuckets();

private:
    std::map<BucketType, int> m_savingsByBucketType;

};

#endif // BANKMODEL_H
