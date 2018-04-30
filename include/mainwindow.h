#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QTimer>
#include <QMainWindow>

#include "controller.h"
#include "logger.h"

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
	SDI::logger* logger;

	//Slots (triggered automatically by the gui)
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

    void on_radioButtonEditProjReleased_clicked();

    void on_radioButtonEditMaterialsDVD_clicked();

    void on_radioButtonEditMaterialsDoubleDVD_clicked();

    void on_radioButtonEditMaterialsCombo_clicked();

    void on_radioButtonEditMaterialsVHS_clicked();

    void on_radioButtonEditMaterialsBluray_clicked();


    void on_buttonAddProjectsSave_clicked();

    void on_buttonAddMaterialsSave_clicked();

    void on_buttonEditProjSave_clicked();

    void on_buttonEditMaterialsSave_clicked();

    void on_buttonBrowseProjDeleteProj_clicked();

    void on_buttonBrowseProjDeleteMaterial_clicked();

    void on_comboBrowseProjProjResults_currentIndexChanged(int index);

    void on_comboBrowseProjProjMaterials_currentIndexChanged(int index);

    void on_checkBoxBrowseProjDVD_stateChanged(int arg1);

    void on_checkBoxBrowseProjDoubleDVD_stateChanged(int arg1);

    void on_checkBoxBrowseProjCombo_stateChanged(int arg1);

    void on_checkBoxBrowseProjVHS_stateChanged(int arg1);

    void on_checkBoxBrowseProjBluray_stateChanged(int arg1);

    void on_buttonBackEditProj_clicked();

    void on_buttonBackEditMaterials_clicked();

    void on_radioButtonEditProjUnreleased_clicked();

private:
    Ui::MainWindow *ui;

	void filterAllBrowsePage();
	void resetAddProjectInput();
	void resetEditProjectInput();
	void resetAddMaterialInput();
	void resetEditMaterialInput();
	void showMessage(std::string text);
};

#endif // MAINWINDOW_H
