#ifndef MAMAL_H
#define MAMAL_H

#include <QObject>
#include "animal.h"

class Mamal : public Animal
{
    Q_OBJECT
public:
    explicit Mamal(QObject *parent = nullptr);

    bool hasBackbone(){
        return true;
    }

signals:
};

#endif // MAMAL_H
