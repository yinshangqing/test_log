#include "widget.h"
#include <QApplication>
#include "log.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test_debug("haoyun shi dou bi");
    Widget w;
    w.show();

    return a.exec();
}
