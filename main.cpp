#include "startscene.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startscene w;
    w.show();

    return a.exec();
}
