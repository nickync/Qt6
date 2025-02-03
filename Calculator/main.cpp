#include <QCoreApplication>
#include "agecalc.h"


void print(AgeCalc &calc)
{
    qInfo() << calc.catYears();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AgeCalc cat;
    cat.setAge(66);


    return a.exec();
}
