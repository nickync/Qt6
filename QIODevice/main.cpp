#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>

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

    QBuffer buffer;

    if (buffer.open(QIODevice::ReadWrite))
    {
        qInfo() << "Device is Open";

        QByteArray data("Hello World");

        for(int i=0; i < 5; i++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }
        //buffer.flush();

        buffer.seek(0);
        qInfo() << buffer.readAll();

        qInfo() << "Closing buffer";

        buffer.close();

    }

    qInfo() << "Done closing";
    return a.exec();
}
