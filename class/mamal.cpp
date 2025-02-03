#include "mamal.h"
#include "animal.h"

Mamal::Mamal(QObject *parent)
    : Animal{parent}
{
    qDebug() << this << "Constructed";
}
