#include "testing.h"

Testing::Testing(QObject *parent) : QObject(parent)
{

}

void Testing::work(QVariant data)
{
    bool ok;
    int numIn = data.toInt(&ok);
    int numOut = 0;

    if(!ok)
    {
        qWarning() << "Not a valid number";
    } else {
        int numRand = QRandomGenerator::global()->bounded(100);
        numOut = numIn * numRand;
        qInfo() << "In: " << numIn;
        qInfo() << "Rand: " << numRand;
        qInfo() << "Out: " << numOut;
    }

    emit status(QVariant(numOut));
}
