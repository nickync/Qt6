#include "taskthreadpool.h"

TaskThreadPool::TaskThreadPool(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

TaskThreadPool::~TaskThreadPool()
{
    qInfo() << "Deconstructed" << this << "on" << QThread::currentThread();
}

void TaskThreadPool::run()
{
    QThread *thread = QThread::currentThread();

    qInfo() << " - Starting" << thread;

    for (int i=0; i<10; i++)
    {
        qInfo() << " -  " << i << " on " << QThread::currentThread();
    }

    qInfo() << " - Finished" << thread;
}
