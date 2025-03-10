#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr, QString firstname = "", QString lastname = "");

    void display();


    QString firstname() const;
    void setFirstname(const QString &newFirstname);

signals:

private:
    QString m_firstname;
    QString m_lastname;
};

#endif // PERSON_H
