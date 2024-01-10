#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{

}

void Cat::call()
{
    qInfo() << "Emiting a signal";
    emit meow();
}

QString Cat::name()
{
    qInfo() << "Returning a value";
    return m_name;

}

void Cat::setName(QString value)
{
    m_name = value;
    emit nameChanged();
}
