#include "QtTools.h"
#include <QtWidgets/QApplication>
#include "QThread"
#include "Tools/ThreadHelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTools w;
    w.show();

    QThread t;
    t.start();

    ThreadHelper::run(&t, [](){
        int i = 0;
        ++i;
    });
    return a.exec();
}
