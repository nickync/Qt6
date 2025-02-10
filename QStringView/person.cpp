#include "person.h"
#include <QStringView>
#include <QString>
#include <QDebug>

Person::Person(QObject *parent, QString firstname, QString lastname)
{
    this -> m_firstname = firstname;
    this -> m_lastname = lastname;

}

void Person::display()
{
    QString data = this->m_firstname + " " + this->m_lastname;
    QStringView view(data);
    qInfo() << view;
}
