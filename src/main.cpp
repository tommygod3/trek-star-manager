#include "mainwindow.h"
#include <QApplication>

#include "material.h"

int main(int argc, char *argv[])
{
	SDI::controller* con = new SDI::controller();
	



    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
