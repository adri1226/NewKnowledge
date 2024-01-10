#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

int Test::number()
{
    qInfo() << "Called number()";
    return 26;
}

void Test::bark()
{
    qInfo() << "Bark bark bark";
}
