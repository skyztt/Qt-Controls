#include "ThreadHelper.h"

void ThreadHelper::run(QThread *t, std::function<void()> f)
{
    ThreadHelperObj *obj = new ThreadHelperObj(t, f, Qt::QueuedConnection);
    emit obj->start();
}

void ThreadHelper::runWait(QThread *t, std::function<void()> f)
{
    ThreadHelperObj *obj = new ThreadHelperObj(t, f, Qt::BlockingQueuedConnection);
    emit obj->start();
}
