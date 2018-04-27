#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
	this->setFixedSize(900, 600);
	backend = new SDI::controller();
}

MainWindow::~MainWindow()
{
    delete ui;
	delete backend;
}

void MainWindow::on_buttonToAddProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_buttonToBrowseProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->frameBrowseProjProj->setVisible(false);
    ui->frameBrowseProjMaterials->setVisible(false);
}

void MainWindow::on_buttonToMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_buttonAddProjHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeAddMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeBrowseProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_radioButtonAddProjUnreleased_clicked()
{
    ui->labelAddProjTicketSale->setVisible(false);
    ui->spinBoxAddProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonAddProjReleased_clicked()
{
    ui->labelAddProjTicketSale->setVisible(false);
    ui->spinBoxAddProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonAddProjNowPlaying_clicked()
{
    ui->labelAddProjTicketSale->setVisible(true);
    ui->spinBoxAddProjTicketSale->setVisible(true);
}

void MainWindow::on_radioButtonAddMaterialsVHS_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(false);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,250,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Cardboard box");
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsDVD_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,250,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");

}

void MainWindow::on_radioButtonAddMaterialsBluray_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,250,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsDoubleDVD_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setGeometry(500,380,131,111);
    ui->buttonAddMaterialsSave->setGeometry(680,450,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsCombo_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setGeometry(500,250,131,111);
    ui->buttonAddMaterialsSave->setGeometry(680,320,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Cardboard box");
}

void MainWindow::on_buttonBrowseProjSearchByProj_clicked()
{
    ui->frameBrowseProjProj->setVisible(true);
    ui->frameBrowseProjMaterials->setVisible(true);
	ui->comboBrowseProjProjResults->clear();
	std::vector<std::string> projectNames;
	ui->comboBrowseProjProjResults->addItem("ITEM");
}

void MainWindow::on_buttonBrowseProjSearchByActor_clicked()
{
    ui->frameBrowseProjProj->setVisible(true);
    ui->frameBrowseProjMaterials->setVisible(true);
}

void MainWindow::on_buttonBrowseProjAddMaterial_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buttonBrowseProjViewProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_buttonHomeEditProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonHomeEditMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonBrowseProjEditMaterial_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_radioButtonEditProjNowPlaying_clicked()
{
    ui->labelEditProjTicketSale->setVisible(true);
    ui->spinBoxEditProjTicketSale->setVisible(true);
}

void MainWindow::on_radioButtonEditProjUneleased_clicked()
{
    ui->labelEditProjTicketSale->setVisible(false);
    ui->spinBoxEditProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonEditProjReleased_clicked()
{
    ui->labelEditProjTicketSale->setVisible(false);
    ui->spinBoxEditProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonlEditMaterialsDVD_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,250,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonlEditMaterialsDoubleDVD_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsMovieList->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(true);
    ui->frameEditMaterialsSides->setGeometry(500,380,131,111);
    ui->buttonEditMaterialsSave->setGeometry(680,450,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonlEditMaterialsCombo_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(true);
    ui->frameEditMaterialsMovieList->setGeometry(500,250,131,111);
    ui->buttonEditMaterialsSave->setGeometry(680,320,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Cardboard box");
}

void MainWindow::on_radioButtonlEditMaterialsVHS_clicked()
{

    ui->frameEditMaterialsAdditional->setVisible(false);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,250,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Cardboard box");
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonlEditMaterialBluray_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,250,130,40);
    ui->comboEditMaterialPackaging->clear();
    ui->comboEditMaterialPackaging->addItem("Plastic box");
}
