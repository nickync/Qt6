#include <QCoreApplication>
#include "animal.h"

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

    Animal cat;
    Animal dog;
    Animal fish;

    cat.setObjectName("Kitty");
    dog.setObjectName("Goof");
    fish.setObjectName("Neemo");

    cat.speak("Meowwww..");
    dog.speak("Woooof");
    fish.speak("shhhhhsss");

    return a.exec();
}
