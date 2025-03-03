#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QScopedPointer>
#include "task.h"
#include <QThreadPool>
#include "taskthreadpool.h"

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

    QThread::currentThread()->setObjectName("Main Thread");

    QThread worker;
    worker.setObjectName("Worker Thread");

    qInfo() << "Starting work" << QThread::currentThread();

    //Task *task = new Task(&a);
    QScopedPointer<Task> t(new Task());

    Task *task = t.data();

    task->moveToThread(&worker);

    worker.connect(&worker, &QThread::started, task, &Task::work);

    worker.start();

    qInfo() << "Free to do other things" << QThread::currentThread();

    qInfo() << " - Now running example for QThreadPool";

    qInfo() << " - Max Threads: " << QThreadPool::globalInstance()->maxThreadCount();

    for (int i=0; i < 2; i++)
    {
        TaskThreadPool *task = new TaskThreadPool();
        task->setAutoDelete(true);
        QThreadPool::globalInstance()->start(task);
    }



    return a.exec();
}
