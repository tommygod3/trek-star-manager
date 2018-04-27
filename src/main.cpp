#include "mainwindow.h"
#include <QApplication>

#include "material.h"

int main(int argc, char *argv[])
{
	SDI::controller* con = new SDI::controller();
	con->projectList.at(1)->setDirector("the directors brother");

	delete con;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
