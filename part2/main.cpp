#include <QCoreApplication>
#include <QDebug>

enum Colors {red, blue, green, black};

struct product
{
    int weight;
    double value;
    Colors color;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    qInfo() << "Hello World";

    bool isOn = false;

    qInfo() << "Is on:" << isOn;

    isOn = true;

    qInfo() << isOn;

    int age = 44;
    double height = 6.02;

    qInfo() << age << " " << height;

    enum Color {red, green, blue};
    enum Color1 {red1 = 100, green1 = 150, blue1 = 255};

    Color mycolor = Color::blue;

    Color1 color = Color1::blue1;

    qInfo() << mycolor;
    qInfo() << color;

    // struct stuff...
    product Laptop; // no assignment
    qInfo() << sizeof(Laptop); // laptop memory size 24;

    Laptop.color = Colors::green;
    Laptop.value = 540.97;
    Laptop.weight = 3;

    qInfo() << Laptop.weight << Laptop.color << Laptop.value;

    return a.exec();
}
