#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	//Set up window with correct size, title and icon
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
	this->setFixedSize(900, 600);
	this->setWindowIcon(QIcon("../resources/film.png"));
	this->setWindowTitle("Trek Star Pictures Project Manager");
	//Try to create new controller and logger
	try
	{
		backend = new SDI::controller();
		logger = new SDI::logger(QDate::currentDate().toString().toStdString());
	}
	//If they throw because database could not be read, show this in pop up and close mainwindow
	catch (std::runtime_error &r)
	{
		showMessage(r.what());
		QTimer::singleShot(0, this, SLOT(close()));
	}
}

MainWindow::~MainWindow()
{
	//Clean up by deleting pointer objects
    delete ui;
	delete backend;
	delete logger;
}

void MainWindow::on_buttonToAddProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
	ui->dateAddProjReleaseDate->setDate(QDate::currentDate());
}

void MainWindow::on_buttonToBrowseProjects_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
	//Everytime we click in the page to view projects, update its combobox to include all projects alphabetically sorted by title
	//Add their unique id as the data so we know which project we have currently selecting, as title is not primary key in project list, project id is
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
	//Set current date for title and read in todays log from logger class
	ui->labelMaintenanceDate->setText("Date: " + QDate::currentDate().toString());
	std::string log = "";
	for (unsigned int i = 0; i < logger->todaysLog.size(); i++)
	{
		log += logger->todaysLog.at(i) + "\n";
	}
	ui->textMaintenance->setText(QString::fromStdString(log));
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_buttonAddProjHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	//Clear screen when exiting
	resetAddProjectInput();
}

void MainWindow::on_buttonHomeAddMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	//Clear screen when exiting
	resetAddMaterialInput();
}

void MainWindow::on_buttonHomeBrowseProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	//Clear screen when exiting
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
    ui->buttonAddMaterialsSave->setGeometry(680,270,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Cardboard box");
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsDVD_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,270,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");

}

void MainWindow::on_radioButtonAddMaterialsBluray_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(false);
    ui->buttonAddMaterialsSave->setGeometry(680,270,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsDoubleDVD_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setVisible(true);
    ui->frameEditMaterialsSides->setGeometry(500,250,311,111);
    ui->frameAddMaterialsSidesMovieList->setGeometry(500,390,131,111);
    ui->buttonAddMaterialsSave->setGeometry(680,460,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonAddMaterialsCombo_clicked()
{
    ui->frameAddMaterialsAdditional->setVisible(true);
    ui->frameAddMaterialsSides->setVisible(false);
    ui->frameAddMaterialsSidesMovieList->setVisible(true);
    ui->frameAddMaterialsSidesMovieList->setGeometry(500,270,131,111);
    ui->buttonAddMaterialsSave->setGeometry(680,270,130,40);
    ui->comboAddMaterialsPackaging->clear();
    ui->comboAddMaterialsPackaging->addItem("Cardboard box");
}

void MainWindow::filterAllBrowsePage()
{
	//Filters the project in the combo box with additional filters
	ui->comboBrowseProjProjResults->clear();
	//First project list is obtained in alphabetical order in whole
	std::vector<unsigned long long> idAlpha = backend->getAlphabeticProjects();
	if (idAlpha.size() == 0)
	{
		return;
	}
	std::string filterTitle = ui->textBrowseProjSearchByProj->text().toStdString();
	//Next filter by title by deleting projects that don't contain "title"
	std::vector<unsigned long long> idFiltered = backend->getProjectsTitleFilter(filterTitle, idAlpha);
	std::string filterActor = ui->textBrowseProjSearchByActor->text().toStdString();
	//Then filter by actor by deleting projects that don't contain "actor"
	idFiltered = backend->getProjectsActorFilter(filterActor, idFiltered);
	//Then filter by what types of materials are available by deleting those in list that don't have to desired material type
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
	//Reset list when returning to browse page
	filterAllBrowsePage();
}

void MainWindow::on_buttonBrowseProjSearchByActor_clicked()
{
	//Reset list when returning to browse page
	filterAllBrowsePage();
}

void MainWindow::on_buttonBrowseProjAddMaterial_clicked()
{
	if (backend->currentProjectIndex != -1)
	{
		ui->stackedWidget->setCurrentIndex(2);
	}
    
}

void MainWindow::on_buttonBrowseProjViewProj_clicked()
{
	//Load in current project to view projects page
	if (backend->currentProjectIndex == -1)
	{
		return;
	}
	SDI::project* currProj = backend->projectList.at(backend->currentProjectIndex);
	ui->textEditProjTitle->setText(QString::fromStdString(currProj->getTitle()));
	ui->textEditProjSummary->setText(QString::fromStdString(currProj->getSummary()));
	ui->textEditProjGenre->setText(QString::fromStdString(currProj->getGenre()));
	ui->dateEditProjReleaseDate->setDate(QDate::fromString(QString::fromStdString(currProj->getReleaseDate()), "dd.MM.yyyy"));
	ui->textEditProjLanguage->setText(QString::fromStdString(currProj->getLanguage()));
	QString filmingLocations;
	for (unsigned int i = 0; i < currProj->getFilmingLocations().size(); i++)
	{
		filmingLocations += QString::fromStdString(currProj->getFilmingLocations().at(i));
		if (i + 1 < currProj->getFilmingLocations().size())
		{
			filmingLocations += "\n";
		}
		
	}
	ui->textEditProjFilmingLocations->setPlainText(filmingLocations);
	switch (currProj->getProjectStatus())
	{
	case 0:
		ui->radioButtonEditProjReleased->setChecked(true);
		break;
	case 1:
		ui->radioButtonEditProjUnreleased->setChecked(true);
		break;
	case 2:
		ui->radioButtonEditProjNowPlaying->setChecked(true);
		ui->spinBoxEditProjTicketSale->setValue(currProj->getTicketSales());
		break;
	}
	ui->timeEditProjRuntime->setTime(QTime::fromString((QString::fromStdString(currProj->getRuntime())), "HH:mm"));
	ui->textEditProjProducer->setText(QString::fromStdString(currProj->getProducer()));
	ui->textEditProjDirector->setText(QString::fromStdString(currProj->getDirector()));
	ui->textEditProjWriter->setText(QString::fromStdString(currProj->getWriter()));
	QString keywords;
	for (unsigned int i = 0; i < currProj->getKeywords().size(); i++)
	{
		keywords += QString::fromStdString(currProj->getKeywords().at(i));
		if (i + 1 < currProj->getKeywords().size())
		{
			keywords += "\n";
		}
	}
	ui->textEditProjKeywords->setPlainText(keywords);
	ui->textEditProjEditor->setText(QString::fromStdString(currProj->getEditor()));
	ui->textEditProjProductionDesigner->setText(QString::fromStdString(currProj->getProductionDesigner()));
	ui->textEditProjSetDecorator->setText(QString::fromStdString(currProj->getSetDecorator()));
	ui->textEditProjCostumeDesigner->setText(QString::fromStdString(currProj->getCostumeDesigner()));
	QString allCast;
	for (unsigned int i = 0; i < currProj->getCast().size(); i++)
	{
		allCast += QString::fromStdString(currProj->getCast().at(i));
		if (i + 1 < currProj->getCast().size())
		{
			allCast += "\n";
		}
	}
	ui->textEditProjCast->setPlainText(allCast);
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_buttonHomeEditProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	//Clear screen when exiting
	resetEditProjectInput();
}

void MainWindow::on_buttonHomeEditMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
	//Clear screen when exiting
	resetEditMaterialInput();
}

void MainWindow::on_buttonBrowseProjEditMaterial_clicked()
{
	//Load in current project to view projects page
	if (backend->currentProjectIndex == -1)
	{
		return;
	}
	if (backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex == -1)
	{
		return;
	}
	SDI::material* currMat = backend->projectList.at(backend->currentProjectIndex)->myMaterials.at(backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex);
	switch (currMat->getMaterialType())
	{
	case 0:
		ui->radioButtonEditMaterialsDVD->setChecked(true);
		break;
	case 1:
		ui->radioButtonEditMaterialsDoubleDVD->setChecked(true);
		break;
	case 2:
		ui->radioButtonEditMaterialsCombo->setChecked(true);
		break;
	case 3:
		ui->radioButtonEditMaterialsVHS->setChecked(true);
		break;
	case 4:
		ui->radioButtonEditMaterialsBluray->setChecked(true);
		break;
	}

	ui->textEditMaterialsTitle->setText(QString::fromStdString(currMat->getTitle()));
	ui->textEditMaterialsFormat->setText(QString::fromStdString(currMat->getFormat()));
	ui->timeEditMaterialsRuntime->setTime(QTime::fromString((QString::fromStdString(currMat->getRuntime())), "HH:mm"));
	ui->spinBoxEditMaterialsRetailPrice->setValue(currMat->getRetailPrice());
	ui->textEditMaterialsFrameAspect->setText(QString::fromStdString(currMat->getFrameAspect()));
	ui->comboEditMaterialsAudioFormat->setCurrentIndex(ui->comboEditMaterialsAudioFormat->findText(QString::fromStdString(currMat->getAudioFormat())));
	ui->textEditMaterialsLanguage->setText(QString::fromStdString(currMat->getLanguage()));
	ui->textEditMaterialsSubtitles->setText(QString::fromStdString(currMat->getSubtitles()));
	ui->comboEditMaterialsPackaging->setCurrentIndex(ui->comboEditMaterialsPackaging->findText(QString::fromStdString(currMat->getPackaging())));



	if (currMat->getMaterialType() != 3)
	{
		QString additionalLangs;
		for (unsigned int i = 0; i < currMat->getAdditionalLanguages().size(); i++)
		{
			additionalLangs += QString::fromStdString(currMat->getAdditionalLanguages().at(i));
			if (i + 1 < currMat->getAdditionalLanguages().size())
			{
				additionalLangs += "\n";
			}

		}
		ui->textEditMaterialsAdditionalLang->setPlainText(additionalLangs);


		QString additionalSubs;
		for (unsigned int i = 0; i < currMat->getAdditionalSubtitles().size(); i++)
		{
			additionalSubs += QString::fromStdString(currMat->getAdditionalSubtitles().at(i));
			if (i + 1 < currMat->getAdditionalSubtitles().size())
			{
				additionalSubs += "\n";
			}
		}
		ui->textEditMaterialsAdditionalSub->setPlainText(additionalSubs);

		ui->textEditMaterialsBonusFeatures->setPlainText(QString::fromStdString(currMat->getBonusFeatures()));
	}
	if (currMat->getMaterialType() == 1 || currMat->getMaterialType() == 2)
	{
		QString movieList;
		for (unsigned int i = 0; i < currMat->getMovieList().size(); i++)
		{
			movieList += QString::fromStdString(currMat->getMovieList().at(i));
			if (i + 1 < currMat->getMovieList().size())
			{
				movieList += "\n";
			}
		}
		ui->textEditMaterialsMovieList->setPlainText(movieList);

		if (currMat->getMaterialType() == 1)
		{
			ui->textEditMaterialsFirstSide->setPlainText(QString::fromStdString(currMat->getSideOneDetails()));

			ui->textEditMaterialsSecondSide->setPlainText(QString::fromStdString(currMat->getSideTwoDetails()));
		}
	}

    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_radioButtonEditProjNowPlaying_clicked()
{
    ui->labelEditProjTicketSale->setVisible(true);
    ui->spinBoxEditProjTicketSale->setVisible(true);
}

void MainWindow::on_radioButtonEditProjUnreleased_clicked()
{
    ui->labelEditProjTicketSale->setVisible(false);
    ui->spinBoxEditProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonEditProjReleased_clicked()
{
    ui->labelEditProjTicketSale->setVisible(false);
    ui->spinBoxEditProjTicketSale->setVisible(false);
}

void MainWindow::on_radioButtonEditMaterialsDVD_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,270,130,40);
    ui->comboEditMaterialsPackaging->clear();
    ui->comboEditMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonEditMaterialsDoubleDVD_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsMovieList->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(true);
    ui->frameEditMaterialsSides->setGeometry(500,270,311,111);
    ui->frameEditMaterialsMovieList->setGeometry(500,390,131,111);
    ui->buttonEditMaterialsSave->setGeometry(680,460,130,40);
    ui->comboEditMaterialsPackaging->clear();
    ui->comboEditMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonEditMaterialsCombo_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(true);
    ui->frameEditMaterialsMovieList->setGeometry(500,270,131,111);
    ui->buttonEditMaterialsSave->setGeometry(680,270,130,40);
    ui->comboEditMaterialsPackaging->clear();
    ui->comboEditMaterialsPackaging->addItem("Cardboard box");
}

void MainWindow::on_radioButtonEditMaterialsVHS_clicked()
{

    ui->frameEditMaterialsAdditional->setVisible(false);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,270,130,40);
    ui->comboEditMaterialsPackaging->clear();
    ui->comboEditMaterialsPackaging->addItem("Cardboard box");
    ui->comboEditMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_radioButtonEditMaterialsBluray_clicked()
{
    ui->frameEditMaterialsAdditional->setVisible(true);
    ui->frameEditMaterialsSides->setVisible(false);
    ui->frameEditMaterialsMovieList->setVisible(false);
    ui->buttonEditMaterialsSave->setGeometry(680,270,130,40);
    ui->comboEditMaterialsPackaging->clear();
    ui->comboEditMaterialsPackaging->addItem("Plastic box");
}

void MainWindow::on_buttonAddProjectsSave_clicked()
{
	//Making new project, add it to the backends list of projects
	//Add this detail to log
	try
	{
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
			newProject->resetTicketSales();
		}
		else if (ui->radioButtonAddProjUnreleased->isChecked())
		{
			newProject->setProjectStatus(1);
			newProject->resetTicketSales();
		}
		else if (ui->radioButtonAddProjNowPlaying->isChecked())
		{
			newProject->setProjectStatus(2);
			newProject->setTicketSales(ui->spinBoxAddProjTicketSale->value());
		}
		newProject->setRuntime(ui->timeAddProjRuntime->time().toString("HH:mm").toStdString());
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
		logger->logNewProject(QTime::currentTime().toString().toStdString(), newProject->getTitle());
		//Clear screen when exiting
		resetAddProjectInput();
	}
	catch (std::invalid_argument &e)
	{
		showMessage(e.what());
	}
}

void MainWindow::on_buttonAddMaterialsSave_clicked()
{
	//Making new material, add it to the currently selected projects material list
	//Add this detail to log
	try
	{
		SDI::material* newMaterial = new SDI::material(backend->projectList.at(backend->currentProjectIndex)->getNextMaterialId(), false);
		if (ui->radioButtonAddMaterialsDVD->isChecked())
		{
			newMaterial->setMaterialType(0);
		}
		else if (ui->radioButtonAddMaterialsDoubleDVD->isChecked())
		{
			newMaterial->setMaterialType(1);
		}
		else if (ui->radioButtonAddMaterialsCombo->isChecked())
		{
			newMaterial->setMaterialType(2);
		}
		else if (ui->radioButtonAddMaterialsVHS->isChecked())
		{
			newMaterial->setMaterialType(3);
		}
		else if (ui->radioButtonAddMaterialsBluray->isChecked())
		{
			newMaterial->setMaterialType(4);
		}
		newMaterial->setTitle(ui->textAddMaterialsTitle->text().toStdString());
		newMaterial->setFormat(ui->textAddMaterialsFormat->text().toStdString());
		newMaterial->setRuntime(ui->timeAddMaterialsRuntime->time().toString("HH:mm").toStdString());
		newMaterial->setRetailPrice(ui->spinBoxAddMaterialsRetailPrice->value());
		newMaterial->setFrameAspect(ui->textAddMaterialsFrameAspect->text().toStdString());
		newMaterial->setAudioFormat(ui->comboAddMaterialsAudioFormat->currentText().toStdString());
		newMaterial->setLanguage(ui->textAddMaterialsLanguage->text().toStdString());
		newMaterial->setSubtitles(ui->textAddMaterialsSubtitles->text().toStdString());
		newMaterial->setPackaging(ui->comboAddMaterialsPackaging->currentText().toStdString());

		if (!ui->radioButtonAddMaterialsVHS->isChecked())
		{
			QString allLanguages = ui->textAddMaterialsAdditionalLang->toPlainText();
			QStringList languageList = allLanguages.split("\n");
			for (unsigned int i = 0; i < languageList.size(); i++)
			{
				newMaterial->addAdditionalLanguage(languageList.at(i).toStdString());
			}

			QString allSubtitles = ui->textAddMaterialsAdditionalSub->toPlainText();
			QStringList subtitleList = allSubtitles.split("\n");
			for (unsigned int i = 0; i < subtitleList.size(); i++)
			{
				newMaterial->addAdditionalSubtitle(subtitleList.at(i).toStdString());
			}

			QString bonusFeature = ui->textAddMaterialsBonusFeatures->toPlainText();
			QStringList featureList = bonusFeature.split("\n");
			std::string feature;
			for (unsigned int i = 0; i < featureList.size(); i++)
			{
				feature += featureList.at(i).toStdString();
			}
			newMaterial->setBonusFeatures(feature);
		}

		if (ui->radioButtonAddMaterialsDoubleDVD->isChecked())
		{
			QString firstSide = ui->textAddMaterialsFirstSide->toPlainText();
			QStringList firstSideList = firstSide.split("\n");
			std::string sideOne;
			for (unsigned int i = 0; i < firstSideList.size(); i++)
			{
				sideOne += firstSideList.at(i).toStdString();
			}
			newMaterial->setSideOneDetails(sideOne);

			QString secondSide = ui->textAddMaterialsSecondSide->toPlainText();
			QStringList secondSideList = secondSide.split("\n");
			std::string sideTwo;
			for (unsigned int i = 0; i < secondSideList.size(); i++)
			{
				sideTwo += secondSideList.at(i).toStdString();
			}
			newMaterial->setSideTwoDetails(sideTwo);
		}

		if (ui->radioButtonAddMaterialsCombo->isChecked() || ui->radioButtonAddMaterialsDoubleDVD->isChecked())
		{
			QString allMovies = ui->textAddMaterialsMovieList->toPlainText();
			QStringList movieList = allMovies.split("\n");
			for (unsigned int i = 0; i < movieList.size(); i++)
			{
				newMaterial->addToMovieList(movieList.at(i).toStdString());
			}
		}
		backend->projectList.at(backend->currentProjectIndex)->myMaterials.push_back(newMaterial);
		logger->logNewMaterial(QTime::currentTime().toString().toStdString(), newMaterial->getTitle(), backend->projectList.at(backend->currentProjectIndex)->getTitle());
		//Clear screen when exiting
		resetAddMaterialInput();
	}
	catch (std::invalid_argument &e)
	{
		showMessage(e.what());
	}
}

void MainWindow::on_buttonEditProjSave_clicked()
{
	//Save changes on viewed project
	//Add this detail to log
	try
	{
		SDI::project* currProj = backend->projectList.at(backend->currentProjectIndex);

		currProj->setTitle(ui->textEditProjTitle->text().toStdString());
		currProj->setSummary(ui->textEditProjSummary->text().toStdString());
		currProj->setGenre(ui->textEditProjGenre->text().toStdString());
		currProj->setReleaseDate(QString(ui->dateEditProjReleaseDate->date().toString("dd.MM.yyyy")).toStdString());
		currProj->setLanguage(ui->textEditProjLanguage->text().toStdString());
		QString allLocations = ui->textEditProjFilmingLocations->toPlainText();
		QStringList locationList = allLocations.split("\n");
		currProj->resetFilmingLocations();
		for (unsigned int i = 0; i < locationList.size(); i++)
		{
			currProj->addFilmingLocation(locationList.at(i).toStdString());
		}
		if (ui->radioButtonEditProjReleased->isChecked())
		{
			currProj->setProjectStatus(0);
			currProj->resetTicketSales();
		}
		else if (ui->radioButtonEditProjUnreleased->isChecked())
		{
			currProj->setProjectStatus(1);
			currProj->resetTicketSales();
		}
		else if (ui->radioButtonEditProjNowPlaying->isChecked())
		{
			currProj->setProjectStatus(2);
			currProj->setTicketSales(ui->spinBoxEditProjTicketSale->value());
		}
		currProj->setRuntime(ui->timeEditProjRuntime->time().toString("HH:mm").toStdString());
		currProj->setProducer(ui->textEditProjProducer->text().toStdString());
		currProj->setDirector(ui->textEditProjDirector->text().toStdString());
		currProj->setWriter(ui->textEditProjWriter->text().toStdString());
		QString allKeywords = ui->textEditProjKeywords->toPlainText();
		QStringList keywordList = allKeywords.split("\n");
		currProj->resetKeywords();
		for (unsigned int i = 0; i < keywordList.size(); i++)
		{
			currProj->addKeyword(keywordList.at(i).toStdString());
		}
		currProj->setEditor(ui->textEditProjEditor->text().toStdString());
		currProj->setProductionDesigner(ui->textEditProjProductionDesigner->text().toStdString());
		currProj->setSetDecorator(ui->textEditProjSetDecorator->text().toStdString());
		currProj->setCostumeDesigner(ui->textEditProjCostumeDesigner->text().toStdString());
		QString allCast = ui->textEditProjCast->toPlainText();
		QStringList castList = allCast.split("\n");
		currProj->resetCast();
		for (unsigned int i = 0; i < castList.size(); i++)
		{
			currProj->addCast(castList.at(i).toStdString());
		}
		logger->logEditProject(QTime::currentTime().toString().toStdString(), currProj->getTitle());
	}
	catch (std::invalid_argument &e)
	{
		showMessage(e.what());
	}
	
}

void MainWindow::on_buttonEditMaterialsSave_clicked()
{
	//Save changes on currently viewed material
	//Add this detail to log
	try
	{
		SDI::material* currMat = backend->projectList.at(backend->currentProjectIndex)->myMaterials.at(backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex);

		if (ui->radioButtonEditMaterialsDVD->isChecked())
		{
			currMat->setMaterialType(0);
		}
		else if (ui->radioButtonEditMaterialsDoubleDVD->isChecked())
		{
			currMat->setMaterialType(1);
		}
		else if (ui->radioButtonEditMaterialsCombo->isChecked())
		{
			currMat->setMaterialType(2);
		}
		else if (ui->radioButtonEditMaterialsVHS->isChecked())
		{
			currMat->setMaterialType(3);
		}
		else if (ui->radioButtonEditMaterialsBluray->isChecked())
		{
			currMat->setMaterialType(4);
		}
		currMat->setTitle(ui->textEditMaterialsTitle->text().toStdString());
		currMat->setFormat(ui->textEditMaterialsFormat->text().toStdString());
		currMat->setRuntime(ui->timeEditMaterialsRuntime->time().toString("HH:mm").toStdString());
		currMat->setRetailPrice(ui->spinBoxEditMaterialsRetailPrice->value());
		currMat->setFrameAspect(ui->textEditMaterialsFrameAspect->text().toStdString());
		currMat->setAudioFormat(ui->comboEditMaterialsAudioFormat->currentText().toStdString());
		currMat->setLanguage(ui->textEditMaterialsLanguage->text().toStdString());
		currMat->setSubtitles(ui->textEditMaterialsSubtitles->text().toStdString());
		currMat->setPackaging(ui->comboEditMaterialsPackaging->currentText().toStdString());

		if (!ui->radioButtonEditMaterialsVHS->isChecked())
		{
			QString allLanguages = ui->textEditMaterialsAdditionalLang->toPlainText();
			QStringList languageList = allLanguages.split("\n");
			currMat->resetAdditionalLanguages();
			for (unsigned int i = 0; i < languageList.size(); i++)
			{
				currMat->addAdditionalLanguage(languageList.at(i).toStdString());
			}

			QString allSubtitles = ui->textEditMaterialsAdditionalSub->toPlainText();
			QStringList subtitleList = allSubtitles.split("\n");
			currMat->resetAdditionalSubtitles();
			for (unsigned int i = 0; i < subtitleList.size(); i++)
			{
				currMat->addAdditionalSubtitle(subtitleList.at(i).toStdString());
			}

			QString bonusFeature = ui->textEditMaterialsBonusFeatures->toPlainText();
			QStringList featureList = bonusFeature.split("\n");
			std::string feature;
			for (unsigned int i = 0; i < featureList.size(); i++)
			{
				feature += featureList.at(i).toStdString();
			}
			currMat->setBonusFeatures(feature);
		}

		if (ui->radioButtonEditMaterialsDoubleDVD->isChecked())
		{
			QString firstSide = ui->textEditMaterialsFirstSide->toPlainText();
			QStringList firstSideList = firstSide.split("\n");
			std::string sideOne;
			for (unsigned int i = 0; i < firstSideList.size(); i++)
			{
				sideOne += firstSideList.at(i).toStdString();
			}
			currMat->setSideOneDetails(sideOne);

			QString secondSide = ui->textEditMaterialsSecondSide->toPlainText();
			QStringList secondSideList = secondSide.split("\n");
			std::string sideTwo;
			for (unsigned int i = 0; i < secondSideList.size(); i++)
			{
				sideTwo += secondSideList.at(i).toStdString();
			}
			currMat->setSideTwoDetails(sideTwo);
		}

		if (ui->radioButtonEditMaterialsCombo->isChecked() || ui->radioButtonEditMaterialsDoubleDVD->isChecked())
		{
			QString allMovies = ui->textEditMaterialsMovieList->toPlainText();
			QStringList movieList = allMovies.split("\n");
			currMat->resetMovieList();
			for (unsigned int i = 0; i < movieList.size(); i++)
			{
				currMat->addToMovieList(movieList.at(i).toStdString());
			}
		}

		logger->logEditMaterial(QTime::currentTime().toString().toStdString(), currMat->getTitle(), backend->projectList.at(backend->currentProjectIndex)->getTitle());
	}
	catch (std::invalid_argument &e)
	{
		showMessage(e.what());
	}
	
}

void MainWindow::on_buttonBrowseProjDeleteProj_clicked()
{
	//Delete selected project
	//Add this detail to log
	if (backend->currentProjectIndex > -1)
	{
		logger->logEditProject(QTime::currentTime().toString().toStdString(), backend->projectList.at(backend->currentProjectIndex)->getTitle());
		backend->removeProject(backend->projectList.at(backend->currentProjectIndex)->getProjectId());
		
		filterAllBrowsePage();
	}
}

void MainWindow::on_buttonBrowseProjDeleteMaterial_clicked()
{
	//Delete selected material
	//Add this detail to log
	if (backend->currentProjectIndex > -1)
	{
		if (backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex > -1)
		{
			logger->logDeleteMaterial(QTime::currentTime().toString().toStdString(), backend->projectList.at(backend->currentProjectIndex)->myMaterials.at(backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex)->getTitle(), backend->projectList.at(backend->currentProjectIndex)->getTitle());
			backend->projectList.at(backend->currentProjectIndex)->removeMaterial(backend->projectList.at(backend->currentProjectIndex)->myMaterials.at(backend->projectList.at(backend->currentProjectIndex)->currentMaterialIndex)->getMaterialId());
			
			filterAllBrowsePage();
		}
		
	}
}

void MainWindow::on_comboBrowseProjProjResults_currentIndexChanged(int index)
{
	//When currently selected project on list is changed, change the backend so the currently selected index matches and set material list to be its materials
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
	//Set the backends currently selected projects' currently selected material to match what is currently selected by combo box
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
	//Reapply filter
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjDoubleDVD_stateChanged(int arg1)
{
	//Reapply filter
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjCombo_stateChanged(int arg1)
{
	//Reapply filter
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjVHS_stateChanged(int arg1)
{
	//Reapply filter
	filterAllBrowsePage();
}

void MainWindow::on_checkBoxBrowseProjBluray_stateChanged(int arg1)
{
	//Reapply filter
	filterAllBrowsePage();
}

void MainWindow::resetAddProjectInput()
{
	//Clear add project page
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
	//Clear edit project page
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
	//Clear add material page
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

void MainWindow::resetEditMaterialInput()
{
	//Clear edit material page
	ui->radioButtonEditMaterialsDVD->setChecked(false);
	ui->radioButtonEditMaterialsDoubleDVD->setChecked(false);
	ui->radioButtonEditMaterialsCombo->setChecked(false);
	ui->radioButtonEditMaterialsVHS->setChecked(false);
	ui->radioButtonEditMaterialsBluray->setChecked(false);
	ui->textEditMaterialsTitle->clear();
	ui->textEditMaterialsFormat->clear();
	ui->timeEditMaterialsRuntime->setTime(QTime(00, 00));
	ui->spinBoxEditMaterialsRetailPrice->setValue(0.00);
	ui->textEditMaterialsFrameAspect->clear();
	ui->comboEditMaterialsAudioFormat->setCurrentIndex(0);
	ui->textEditMaterialsLanguage->clear();
	ui->textEditMaterialsSubtitles->clear();
	ui->comboEditMaterialsPackaging->setCurrentIndex(0);
	ui->textEditMaterialsAdditionalLang->clear();
	ui->textEditMaterialsAdditionalSub->clear();
	ui->textEditMaterialsBonusFeatures->clear();
	ui->textEditMaterialsFirstSide->clear();
	ui->textEditMaterialsSecondSide->clear();
	ui->textEditMaterialsMovieList->clear();
}
void MainWindow::on_buttonBackEditProj_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
	resetEditMaterialInput();
	filterAllBrowsePage();
}

void MainWindow::on_buttonBackEditMaterials_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
	resetEditMaterialInput();
	filterAllBrowsePage();
}

void MainWindow::showMessage(std::string text)
{
	//Create standard error message box to be shown when user makes an error
	QString message = QString::fromStdString(text);
	QMessageBox msg;
	msg.setText("Error");
	msg.setInformativeText(message);
	msg.setWindowTitle("Trek Star Pictures Project Manager");
	msg.setIconPixmap(QPixmap("../resources/error.png"));
	msg.setWindowIcon(QIcon("../resources/film.png"));
	msg.exec();
}
