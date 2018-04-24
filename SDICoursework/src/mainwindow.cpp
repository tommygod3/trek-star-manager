#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->stackedWidget->setCurrentIndex(3);
    ui->frame_4->setVisible(false);
}

void MainWindow::on_toMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
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

void MainWindow::on_homeButton4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toAddMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->label_22->setVisible(false);
    ui->lineEdit_14->setVisible(false);
}

void MainWindow::on_radioButton_clicked()
{
    ui->label_22->setVisible(true);
    ui->lineEdit_14->setVisible(true);
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->label_22->setVisible(true);
    ui->lineEdit_14->setVisible(true);
}

void MainWindow::on_radioButton_11_clicked()
{
    ui->frame->setVisible(false);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);
    ui->pushButton_3->setGeometry(680,250,130,40);
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Cardboard box");
    ui->comboBox_3->addItem("Plastic box");
}

void MainWindow::on_radioButton_9_clicked()
{
    ui->frame->setVisible(true);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);
    ui->pushButton_3->setGeometry(680,250,130,40);
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Plastic box");

}

void MainWindow::on_radioButton_10_clicked()
{
    ui->frame->setVisible(true);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);
    ui->pushButton_3->setGeometry(680,250,130,40);
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Plastic box");
}

void MainWindow::on_radioButton_13_clicked()
{
    ui->frame->setVisible(true);
    ui->frame_2->setVisible(true);
    ui->frame_3->setVisible(true);
    ui->frame_3->setGeometry(500,380,131,111);
    ui->pushButton_3->setGeometry(680,450,130,40);
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Plastic box");
}

void MainWindow::on_radioButton_12_clicked()
{
    ui->frame->setVisible(true);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(true);
    ui->frame_3->setGeometry(500,250,131,111);
    ui->pushButton_3->setGeometry(680,320,130,40);
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Cardboard box");
}

void MainWindow::on_pushButton_clicked()
{
    ui->frame_4->setVisible(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->frame_4->setVisible(true);
}
