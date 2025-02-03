#ifndef ACAT_H
#define ACAT_H

#include <QObject>
#include <QDebug>
#include "mamal.h"

class ACat : public Mamal
{
    Q_OBJECT
public:
    explicit ACat(QObject *parent = nullptr);
    void meow(){
        qInfo() << "Meow";
    }

signals:
};

#endif // ACAT_H
