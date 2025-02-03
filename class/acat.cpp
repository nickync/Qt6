#include "acat.h"

ACat::ACat(QObject *parent)
    : Mamal{parent}
{
    qInfo() << this <<  "Constructor";
}
