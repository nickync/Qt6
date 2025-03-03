#ifndef TASKTHREADPOOL_H
#define TASKTHREADPOOL_H

#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QDebug>

class TaskThreadPool : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit TaskThreadPool(QObject *parent = nullptr);
    ~TaskThreadPool();

signals:

    // QRunnable interface
public slots:
    void run();
};

#endif // TASKTHREADPOOL_H
