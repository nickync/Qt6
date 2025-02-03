#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>

class Animal : public QObject
{
    Q_OBJECT

public:
    explicit Animal(QObject *parent = nullptr);
    void speak(QString message);
    bool isAlive(){
        return true;
    }

// private:


signals:

};

#endif // ANIMAL_H
