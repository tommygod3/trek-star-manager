#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	SDI::controller* backend;

private slots:
    void on_toAddEditProjects_clicked();

    void on_toBrowseProjects_clicked();

    void on_toMaintenance_clicked();

    void on_homeButton1_clicked();

    void on_homeButton2_clicked();

    void on_homeButton3_clicked();

    void on_homeButton4_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_13_clicked();

    void on_radioButton_12_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_4_clicked();

    void on_homeButton1_2_clicked();

    void on_homeButton2_2_clicked();

    void on_pushButton_9_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_14_clicked();

    void on_radioButton_15_clicked();

    void on_radioButton_17_clicked();

    void on_radioButton_16_clicked();

    void on_radioButton_18_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
