#include "wGameMenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wGameMenu w;
    w.show();
    return a.exec();
}
