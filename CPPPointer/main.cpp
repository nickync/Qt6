#include <QCoreApplication>
#include <QDebug>


// QObject get_object(QString name)
// {
//     QObject o;
//     o.setObjectName(name);
//     return o;

//     //Qt do not like returning by obj value

// }

// QObject& get_ref(QString name)
// {
//     QObject o; // on the stack, c++ manages the memory
//     o.setObjectName(name);
//     return o; // will be deleted

// }

QObject* get_pointer(QString name)
{
    QObject *o = new QObject(); // on the heap, we will manage this
    o -> setObjectName(name);
    return o;

}

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

    // QObject obj = get_ref("test");
    QObject *obj = get_pointer("By Pointer");
    qInfo() << obj -> objectName();
    qInfo() << obj;

    delete obj; // delete from heap / or it will stay on mem

    return a.exec();
}
