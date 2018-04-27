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
	ui->dateAddProjReleaseDate->setDate(QDate::currentDate());
}

void MainWindow::on_buttonToBrowseProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

	ui->comboBrowseProjProjResults->clear();
	std::vector<unsigned long long> idAlpha = backend->getAlphabeticProjects();
	for (unsigned int i = 0; i < idAlpha.size(); i++)
	{
		ui->comboBrowseProjProjResults->addItem(QString::fromStdString(backend->getNameFromId(idAlpha.at(i))), QVariant((idAlpha.at(i))));
	}
	ui->comboBrowseProjProjResults->setCurrentIndex(0);
}

void MainWindow::on_buttonToMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_buttonAddProjHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

	resetAddProjectInput();
}

void MainWindow::on_buttonHomeAddMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	resetAddMaterialInput();
}

void MainWindow::on_buttonHomeBrowseProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	ui->textBrowseProjSearchByActor->clear();
	ui->textBrowseProjSearchByProj->clear();
	ui->comboBrowseProjProjMaterials->clear();
	ui->comboBrowseProjProjResults->clear();
	ui->checkBoxBrowseProjBluray->setChecked(0);
	ui->checkBoxBrowseProjCombo->setChecked(0);
	ui->checkBoxBrowseProjDoubleDVD->setChecked(0);
	ui->checkBoxBrowseProjDVD->setChecked(0);
	ui->checkBoxBrowseProjVHS->setChecked(0);
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

void MainWindow::filterAllBrowsePage()
{
	ui->comboBrowseProjProjResults->clear();
	
	std::vector<unsigned long long> idAlpha = backend->getAlphabeticProjects();
	if (idAlpha.size() == 0)
	{
		return;
	}
	std::string filterTitle = ui->textBrowseProjSearchByProj->text().toStdString();
	//Filter by title
	std::vector<unsigned long long> idFiltered = backend->getProjectsTitleFilter(filterTitle, idAlpha);
	std::string filterActor = ui->textBrowseProjSearchByActor->text().toStdString();
	//Then filter by actor on top
	idFiltered = backend->getProjectsActorFilter(filterActor, idFiltered);
	if (ui->checkBoxBrowseProjDVD->isChecked())
	{
		idFiltered = backend->getProjectsMaterialFilter(0, idFiltered);
	}
	if (ui->checkBoxBrowseProjDoubleDVD->isChecked())
	{
		idFiltered = backend->getProjectsMaterialFilter(1, idFiltered);
	}
	if (ui->checkBoxBrowseProjCombo->isChecked())
	{
		idFiltered = backend->getProjectsMaterialFilter(2, idFiltered);
	}
	if (ui->checkBoxBrowseProjVHS->isChecked())
	{
		idFiltered = backend->getProjectsMaterialFilter(3, idFiltered);
	}
	if (ui->checkBoxBrowseProjBluray->isChecked())
	{
		idFiltered = backend->getProjectsMaterialFilter(4, idFiltered);
	}


	for (unsigned int i = 0; i < idFiltered.size(); i++)
	{
		ui->comboBrowseProjProjResults->addItem(QString::fromStdString(backend->getNameFromId(idFiltered.at(i))), QVariant((idFiltered.at(i))));
	}
	
}

void MainWindow::on_buttonBrowseProjSearchByProj_clicked()
{
	filterAllBrowsePage();
}

void MainWindow::on_buttonBrowseProjSearchByActor_clicked()
{
	filterAllBrowsePage();
}

void MainWindow::on_buttonBrowseProjAddMaterial_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buttonBrowseProjViewProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
	//Load in current project in all edit boxes

}

void MainWindow::on_buttonHomeEditProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	
	resetEditProjectInput();
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

void MainWindow::on_buttonAddProjectsSave_clicked()
{
	//Making new project
	SDI::project* newProject = new SDI::project(backend->getNextProjectId(), false);

	newProject->setTitle(ui->textAddProjTitle->text().toStdString());
	newProject->setSummary(ui->textAddProjSummary->text().toStdString());
	newProject->setGenre(ui->textAddProjGenre->text().toStdString());
	newProject->setReleaseDate(QString(ui->dateAddProjReleaseDate->date().toString("dd.MM.yyyy")).toStdString());
	newProject->setLanguage(ui->textAddProjLanguage->text().toStdString());
	QString allLocations = ui->textAddProjFilmingLocations->toPlainText();
	QStringList locationList = allLocations.split("\n");
	for (unsigned int i = 0; i < locationList.size(); i++)
	{
		newProject->addFilmingLocation(locationList.at(i).toStdString());
	}
	if (ui->radioButtonAddProjReleased->isChecked())
	{
		newProject->setProjectStatus(0);
	}
	else if (ui->radioButtonAddProjUnreleased->isChecked())
	{
		newProject->setProjectStatus(1);
	}
	else if (ui->radioButtonAddProjNowPlaying->isChecked())
	{
		newProject->setProjectStatus(2);
		newProject->setTicketSales(ui->spinBoxAddProjTicketSale->value());
	}
	newProject->setRuntime(ui->timeAddProjRuntime->time().toString().toStdString());
	newProject->setProducer(ui->textAddProjProducer->text().toStdString());
	newProject->setDirector(ui->textAddProjDirector->text().toStdString());
	newProject->setWriter(ui->textAddProjWriter->text().toStdString());
	QString allKeywords = ui->textAddProjKeywords->toPlainText();
	QStringList keywordList = allKeywords.split("\n");
	for (unsigned int i = 0; i < keywordList.size(); i++)
	{
		newProject->addKeyword(keywordList.at(i).toStdString());
	}
	newProject->setEditor(ui->textAddProjEditor->text().toStdString());
	newProject->setProductionDesigner(ui->textAddProjProductionDesigner->text().toStdString());
	newProject->setSetDecorator(ui->textAddProjSetDecorator->text().toStdString());
	newProject->setCostumeDesigner(ui->textAddProjCostumeDesigner->text().toStdString());
	QString allCast = ui->textAddProjCast->toPlainText();
	QStringList castList = allCast.split("\n");
	for (unsigned int i = 0; i < castList.size(); i++)
	{
		newProject->addCast(castList.at(i).toStdString());
	}
	backend->projectList.push_back(newProject);
	
	resetAddProjectInput();
}

void MainWindow::on_buttonAddMaterialsSave_clicked()
{
	//Making new material
	//SDI::material* newMaterial = new SDI::material(backend->projectList.at(backend->currentProjectIndex)->getNextMaterialId(), false);
	/*
	newProject->setTitle(ui->textAddProjTitle->text().toStdString());
	newProject->setSummary(ui->textAddProjSummary->text().toStdString());
	newProject->setGenre(ui->textAddProjGenre->text().toStdString());
	newProject->setReleaseDate(QString(ui->dateAddProjReleaseDate->date().toString("dd.MM.yyyy")).toStdString());
	newProject->setLanguage(ui->textAddProjLanguage->text().toStdString());
	QString allLocations = ui->textAddProjFilmingLocations->toPlainText();
	QStringList locationList = allLocations.split("\n");
	for (unsigned int i = 0; i < locationList.size(); i++)
	{
		newProject->addFilmingLocation(locationList.at(i).toStdString());
	}
	if (ui->radioButtonAddProjReleased->isChecked())
	{
		newProject->setProjectStatus(0);
	}
	else if (ui->radioButtonAddProjUnreleased->isChecked())
	{
		newProject->setProjectStatus(1);
	}
	else if (ui->radioButtonAddProjNowPlaying->isChecked())
	{
		newProject->setProjectStatus(2);
		newProject->setTicketSales(ui->spinBoxAddProjTicketSale->value());
	}
	newProject->setRuntime(ui->timeAddProjRuntime->time().toString().toStdString());
	newProject->setProducer(ui->textAddProjProducer->text().toStdString());
	newProject->setDirector(ui->textAddProjDirector->text().toStdString());
	newProject->setWriter(ui->textAddProjWriter->text().toStdString());
	QString allKeywords = ui->textAddProjKeywords->toPlainText();
	QStringList keywordList = allKeywords.split("\n");
	for (unsigned int i = 0; i < keywordList.size(); i++)
	{
		newProject->addKeyword(keywordList.at(i).toStdString());
	}
	newProject->setEditor(ui->textAddProjEditor->text().toStdString());
	newProject->setProductionDesigner(ui->textAddProjProductionDesigner->text().toStdString());
	newProject->setSetDecorator(ui->textAddProjSetDecorator->text().toStdString());
	newProject->setCostumeDesigner(ui->textAddProjCostumeDesigner->text().toStdString());
	QString allCast = ui->textAddProjCast->toPlainText();
	QStringList castList = allCast.split("\n");
	for (unsigned int i = 0; i < castList.size(); i++)
	{
		newProject->addCast(castList.at(i).toStdString());
	}
	*/

	//backend->projectList.at(backend->currentProjectIndex)->myMaterials.push_back(newMaterial);

	resetAddMaterialInput();
}

void MainWindow::on_buttonEditProjSave_clicked()
{
	
}

void MainWindow::on_buttonEditMaterialsSave_clicked()
{

}

void MainWindow::on_buttonBrowseProjDeleteProj_clicked()
{
	//Delete selected project
	if (backend->currentProjectIndex > -1)
	{
		backend->removeProject(backend->projectList.at(backend->currentProjectIndex)->getProjectId());
		filterAllBrowsePage();
	}
	

}

void MainWindow::on_buttonBrowseProjDeleteMaterial_clicked()
{
	if (backend->currentProjectIndex > -1)
	{
		if (backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex > -1)
		{
			backend->projectList.at(backend->currentProjectIndex)->removeMaterial(backend->projectList.at(backend->currentProjectIndex)->myMaterials.at(backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex)->getMaterialId());
			filterAllBrowsePage();
		}
		
	}
}

void MainWindow::on_comboBrowseProjProjResults_currentIndexChanged(int index)
{
	if (ui->comboBrowseProjProjResults->count() > 0)
	{
		unsigned long long currentId = ui->comboBrowseProjProjResults->itemData(ui->comboBrowseProjProjResults->currentIndex()).toULongLong();
		backend->setCurrentProject(currentId);

		ui->comboBrowseProjProjMaterials->clear();
		if (ui->comboBrowseProjProjMaterials->count() > 0)
		{
			unsigned long long materialId = ui->comboBrowseProjProjMaterials->itemData(ui->comboBrowseProjProjMaterials->currentIndex()).toULongLong();
			backend->projectList.at(backend->currentProjectIndex)->setCurrentMaterial(materialId);
		}
		else if (backend->currentProjectIndex != -1)
		{
			backend->projectList.at(backend->currentProjectIndex)->setCurrentMaterialIndex(-1);
		}
		if (currentId != 0)
		{
			std::vector<unsigned long long> idAlphaMaterials = backend->projectList.at(backend->currentProjectIndex)->getAlphabeticMaterials();
			for (unsigned int i = 0; i < idAlphaMaterials.size(); i++)
			{
				ui->comboBrowseProjProjMaterials->addItem(QString::fromStdString(backend->projectList.at(backend->currentProjectIndex)->getMaterialNameFromId(idAlphaMaterials.at(i))), QVariant((idAlphaMaterials.at(i))));
			}
			ui->comboBrowseProjProjMaterials->setCurrentIndex(0);
		}
	}
	else
	{
		backend->setCurrentProjectIndex(-1);
		ui->comboBrowseProjProjMaterials->clear();
		
	}
	
}

void MainWindow::on_comboBrowseProjProjMaterials_currentIndexChanged(int index)
{
	if (ui->comboBrowseProjProjMaterials->count() > 0)
	{
		unsigned long long materialId = ui->comboBrowseProjProjMaterials->itemData(ui->comboBrowseProjProjMaterials->currentIndex()).toULongLong();
		backend->projectList.at(backend->currentProjectIndex)->setCurrentMaterial(materialId);
	}
	else if (backend->currentProjectIndex != -1)
	{
		backend->projectList.at(backend->currentProjectIndex)->setCurrentMaterialIndex(-1);
	}
}

void MainWindow::on_checkBoxBrowseProjDVD_stateChanged(int arg1)
{
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjDoubleDVD_stateChanged(int arg1)
{
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjCombo_stateChanged(int arg1)
{
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjVHS_stateChanged(int arg1)
{
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjBluray_stateChanged(int arg1)
{
	filterAllBrowsePage();
}

void MainWindow::resetAddProjectInput()
{
	ui->textAddProjTitle->clear();
	ui->textAddProjSummary->clear();
	ui->textAddProjGenre->clear();
	ui->dateAddProjReleaseDate->setDate(QDate::currentDate());
	ui->textAddProjLanguage->clear();
	ui->textAddProjFilmingLocations->clear();
	ui->radioButtonAddProjReleased->setChecked(0);
	ui->radioButtonAddProjUnreleased->setChecked(0);
	ui->radioButtonAddProjNowPlaying->setChecked(0);
	ui->timeAddProjRuntime->setTime(QTime(00,00));
	ui->textAddProjProducer->clear();
	ui->textAddProjDirector->clear();
	ui->textAddProjWriter->clear();
	ui->textAddProjKeywords->clear();
	ui->textAddProjEditor->clear();
	ui->textAddProjProductionDesigner->clear();
	ui->textAddProjSetDecorator->clear();
	ui->textAddProjCostumeDesigner->clear();
	ui->textAddProjCast->clear();
	ui->spinBoxAddProjTicketSale->clear();
}

void MainWindow::resetEditProjectInput()
{
	ui->textEditProjTitle->clear();
	ui->textEditProjSummary->clear();
	ui->textEditProjGenre->clear();
	ui->dateEditProjReleaseDate->setDate(QDate::currentDate());
	ui->textEditProjLanguage->clear();
	ui->textEditProjFilmingLocations->clear();
	ui->radioButtonEditProjReleased->setChecked(false);
	ui->radioButtonEditProjUnreleased->setChecked(false);
	ui->radioButtonEditProjNowPlaying->setChecked(false);
	ui->timeEditProjRuntime->setTime(QTime(00, 00));
	ui->textEditProjProducer->clear();
	ui->textEditProjDirector->clear();
	ui->textEditProjWriter->clear();
	ui->textEditProjKeywords->clear();
	ui->textEditProjEditor->clear();
	ui->textEditProjProductionDesigner->clear();
	ui->textEditProjSetDecorator->clear();
	ui->textEditProjCostumeDesigner->clear();
	ui->textEditProjCast->clear();
	ui->spinBoxEditProjTicketSale->clear();
}

void MainWindow::resetAddMaterialInput()
{
	ui->radioButtonAddMaterialsDVD->setChecked(false);
	ui->radioButtonAddMaterialsDoubleDVD->setChecked(false);
	ui->radioButtonAddMaterialsCombo->setChecked(false);
	ui->radioButtonAddMaterialsVHS->setChecked(false);
	ui->radioButtonAddMaterialsBluray->setChecked(false);
	ui->textAddMaterialsTitle->clear();
	ui->textAddMaterialsFormat->clear();
	ui->timeAddMaterialsRuntime->setTime(QTime(00, 00));
	ui->spinBoxAddMaterialsRetailPrice->setValue(0.00);
	ui->textAddMaterialsFrameAspect->clear();
	ui->comboAddMaterialsAudioFormat->setCurrentIndex(0);
	ui->textAddMaterialsLanguage->clear();
	ui->textAddMaterialsSubtitles->clear();
	ui->comboAddMaterialsPackaging->setCurrentIndex(0);
	ui->textAddMaterialsAdditionalLang->clear();
	ui->textAddMaterialsAdditionalSub->clear();
	ui->textAddMaterialsBonusFeatures->clear();
	ui->textAddMaterialsFirstSide->clear();
	ui->textAddMaterialsSecondSide->clear();
	ui->textAddMaterialsMovieList->clear();
}