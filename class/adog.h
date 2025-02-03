#ifndef ADOG_H
#define ADOG_H

#include <QObject>
#include <QDebug>
#include "mamal.h"

class ADog : public Mamal
{
    Q_OBJECT
public:
    explicit ADog(QObject *parent = nullptr);
    void bark(){
        qInfo() << "woooof";
    }

signals:
};

#endif // ADOG_H
