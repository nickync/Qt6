#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

Task::~Task()
{
    qInfo() << "Deconstructed" << this << "on" << QThread::currentThread();
}

void Task::work()
{
    QThread *thread = QThread::currentThread();

    qInfo() << "Starting" << thread;

    for (int i=0; i<10; i++)
    {
        qInfo() << i << " on " << QThread::currentThread();
    }

    qInfo() << "Finished" << thread;
}
