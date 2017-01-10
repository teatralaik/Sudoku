#include <QApplication>
#include "mwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MWidget w;

    w.show();

    return a.exec();
}
