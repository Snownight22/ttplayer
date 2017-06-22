#include "ttplayermainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ttPlayerMainWindow w;

    w.show();

    return a.exec();
}
