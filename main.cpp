#include "mainfractals.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainFractals w;
    w.showMaximized();
    w.show();
    
    return a.exec();
}
