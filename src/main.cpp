#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	//Main Qt application loop
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
