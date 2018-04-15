#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toAddEditProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_toBrowseProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_toMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_homeButton1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_homeButton2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_homeButton3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
