#pragma once
#include "QObject"
#include <functional>

class ThreadHelper;
class ThreadHelperObj : public QObject {
    Q_OBJECT
private:
    ThreadHelperObj(QThread *t, std::function<void()> f, Qt::ConnectionType type) {
        moveToThread(t);
        bool b1 = connect(this, &ThreadHelperObj::start, this, [f](){
            f();
        }, type);
    }
signals:
    void start();

    friend class ThreadHelper;
};

class ThreadHelper{

public:
    static void run(QThread *t, std::function<void()> f);
    static void runWait(QThread *t, std::function<void()> f);
};

