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
    void on_buttonToAddProjects_clicked();

    void on_buttonToBrowseProjects_clicked();

    void on_buttonToMaintenance_clicked();

    void on_buttonAddProjHome_clicked();

    void on_buttonHomeAddMaterials_clicked();

    void on_buttonHomeBrowseProj_clicked();

    void on_buttonHomeMaintenance_clicked();

    void on_radioButtonAddProjUnreleased_clicked();

    void on_radioButtonAddProjReleased_clicked();

    void on_radioButtonAddProjNowPlaying_clicked();

    void on_radioButtonAddMaterialsVHS_clicked();

    void on_radioButtonAddMaterialsDVD_clicked();

    void on_radioButtonAddMaterialsBluray_clicked();

    void on_radioButtonAddMaterialsDoubleDVD_clicked();

    void on_radioButtonAddMaterialsCombo_clicked();

    void on_buttonBrowseProjSearchByProj_clicked();

    void on_buttonBrowseProjSearchByActor_clicked();

    void on_buttonBrowseProjAddMaterial_clicked();

    void on_buttonBrowseProjViewProj_clicked();

    void on_buttonHomeEditProj_clicked();

    void on_buttonHomeEditMaterials_clicked();

    void on_buttonBrowseProjEditMaterial_clicked();

    void on_radioButtonEditProjNowPlaying_clicked();

    void on_radioButtonEditProjUneleased_clicked();

    void on_radioButtonEditProjReleased_clicked();

    void on_radioButtonlEditMaterialsDVD_clicked();

    void on_radioButtonlEditMaterialsDoubleDVD_clicked();

    void on_radioButtonlEditMaterialsCombo_clicked();

    void on_radioButtonlEditMaterialsVHS_clicked();

    void on_radioButtonlEditMaterialBluray_clicked();


    void on_buttonAddProjectsSave_clicked();

    void on_buttonAddMaterialsSave_clicked();

    void on_buttonEditProjSave_clicked();

    void on_buttonEditMaterialsSave_clicked();

    void on_buttonBrowseProjDeleteProj_clicked();

    void on_buttonBrowseProjDeleteMaterial_clicked();

    void on_comboBrowseProjProjResults_currentIndexChanged(int index);

    void on_comboBrowseProjProjMaterials_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
