#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <QObject>
#include "MicrowaveInterface.h"
#include "FreezerInterface.h"
#include "ToasterInterface.h"
#include <QDebug>

class Appliance : public QObject, public MicrowaveInterface, public FreezerInterface, public ToasterInterface
{
    Q_OBJECT
public:
    explicit Appliance(QObject *parent = nullptr);

signals:

    // ToasterInterface interface
public:
    bool grill();

    // FreezerInterface interface
public:
    bool freeze();

    // MicrowaveInterface interface
public:
    bool cook();
};

#endif // APPLIANCE_H
