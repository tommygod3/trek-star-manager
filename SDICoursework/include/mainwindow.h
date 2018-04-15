#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toAddEditProjects_clicked();

    void on_toBrowseProjects_clicked();

    void on_toMaintenance_clicked();

    void on_homeButton1_clicked();

    void on_homeButton2_clicked();

    void on_homeButton3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
