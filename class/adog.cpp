#include "adog.h"

ADog::ADog(QObject *parent)
    : Mamal{parent}
{
    qInfo() << this <<  "Constructor";
}
