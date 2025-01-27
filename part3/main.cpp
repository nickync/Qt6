#include <QCoreApplication>
#include <QDebug>
#include <array>
using namespace std;
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int ages[4] = {23, 4, 5, 47};

    qInfo() << ages[2];

    ages[2] = 55;

    qInfo() << ages[2];

    array<int, 5> cars;

    cars = {23, 4, 5, 47, 66};

    qInfo() << cars[2];

    cars[2] = 55;

    qInfo() << cars[2] << "array size :" << cars.size() << "array memory size: " << sizeof(cars);

    // C++ way to print
    cout << "Hello" << endl;

    // Qt way
    qInfo() << "Hello";

    // input
    int age;
    qInfo() << "Please enter an age";
    cin >> age;
    qInfo() << "You entered : " << age;

    qInfo() << "Info";
    qDebug() << "Debug";
    qCritical() << "Critical";
    qFatal() << "Fatal crash";

    return a.exec();
}
