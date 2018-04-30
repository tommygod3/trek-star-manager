#include "project.h"

namespace SDI
{
	project::project(unsigned long long id, bool exists)
	{
		this->setProjectId(id);
		//If set in constructor, load in info from file
		if (exists)
		{
			projectFilename = "../data/project" + std::to_string(id) + ".txt";
			loadIn();
		}
	}

	project::~project()
	{
		//Save existing
		if (toBeSaved)
		{
			saveOut();
		}
		else
		{
			remove(projectFilename.c_str());
		}
		
		//Free up memory held by list
		for (unsigned int i = 0; i < toBeRemoved.size(); i++)
		{
			delete toBeRemoved.at(i);
		}
		toBeRemoved.clear();
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			delete myMaterials.at(i);
		}
		myMaterials.clear();
		
	}

	//Load in exisiting material info from disk
	void project::loadIn()
	{
		std::ifstream detailsIn(projectFilename);
		if (!detailsIn.is_open())
		{
			throw std::runtime_error("Error with project file - cannot find " + projectFilename);
		}
		string parser;
		getline(detailsIn, parser);

		if (parser == "")
		{
			throw std::runtime_error("Error loading in project info, project name: " + std::to_string(projectId));
		}

		string deliminator = ",";
		size_t position = 0;
		string attributeIn;
		unsigned int counter = 0;
		vector<int> posOfVecs = { 5,11,16,18 };

		while ((position = parser.find(deliminator)) != std::string::npos) 
		{
			attributeIn = parser.substr(0, position);
			if (std::find(posOfVecs.begin(), posOfVecs.end(), counter) != posOfVecs.end())
			{
				int currentAttribute = counter;
				unsigned int quantity = std::stoul(attributeIn);
				
				
				parser.erase(0, position + deliminator.length());
				for (unsigned int i = 0; i < quantity; i++)
				{

					position = parser.find(deliminator);
					attributeIn = parser.substr(0, position);
					setFromFile(attributeIn, currentAttribute);
					parser.erase(0, position + deliminator.length());
				}
				position = parser.find(deliminator);
				attributeIn = parser.substr(0, position);
				counter++;
				if (counter > 18)
				{
					break;
				}
				
				
			}
			setFromFile(attributeIn, counter);
			parser.erase(0, position + deliminator.length());
			counter++;
		}

		detailsIn.close();
	}

	void project::saveOut()
	{
		//Save project to file
		remove(projectFilename.c_str());
		projectFilename = "../data/project" + std::to_string(getProjectId()) + ".txt";
		std::ofstream projectOut(projectFilename);
		string csv = ",";
		projectOut << getTitle() << csv << getSummary() << csv << getGenre() << csv << getReleaseDate() << csv << getLanguage() << csv;
		projectOut << filmingLocations.size() << csv;
		for (unsigned int i = 0; i < filmingLocations.size(); i++)
		{
			projectOut << filmingLocations.at(i) << csv;
		}
		projectOut << getProjectStatus() << csv << getRuntime() << csv << getProducer() << csv << getDirector() << csv << getWriter() << csv;
		projectOut << keywords.size() << csv;
		for (unsigned int i = 0; i < keywords.size(); i++)
		{
			projectOut << keywords.at(i) << csv;
		}
		projectOut << getEditor() << csv << getProductionDesigner() << csv << getSetDecorator() << csv << getCostumeDesigner() << csv;
		projectOut << cast.size() << csv;
		for (unsigned int i = 0; i < cast.size(); i++)
		{
			projectOut << cast.at(i) << csv;
		}
		projectOut << getTicketSales() << csv;
		projectOut << myMaterials.size() << csv;
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			projectOut << myMaterials.at(i)->getMaterialId() << csv;
		}
		projectOut.close();
	}

	void project::removeThisProject()
	{
		toBeSaved = 0;
		vector<unsigned long long> toBeRemoved;
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			toBeRemoved.push_back(myMaterials.at(i)->getMaterialId());
		}
		for (unsigned int i = 0; i < toBeRemoved.size(); i++)
		{
			removeMaterial(toBeRemoved.at(i));
		}
	}

	void project::removeMaterial(unsigned long long id)
	{
		int indexToRemove = -1;
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			if (myMaterials.at(i)->getMaterialId() == id)
			{
				myMaterials.at(i)->removeThisMaterial();
				indexToRemove = i;
				toBeRemoved.push_back(myMaterials.at(i));
			}
		}
		myMaterials.erase(myMaterials.begin() + indexToRemove);
	}

	vector<unsigned long long> project::getAlphabeticMaterials()
	{
		vector<unsigned long long> ids;
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			ids.push_back(myMaterials.at(i)->getMaterialId());
		}
		if (ids.size() == 0)
		{
			return ids;
		}
		//Bubble sort ids alphabetically from title
		bool flag = 0;
		while (flag == 0)
		{
			bool change = 0;
			for (int i = 0; i < ids.size() - 1; i++)
			{
				if (getMaterialNameFromId(ids.at(i)) > getMaterialNameFromId(ids.at(i + 1)))
				{
					std::iter_swap(ids.begin() + i, ids.begin() + i + 1);
					change = 1;
				}
			}
			if (change == 0)
			{
				flag = 1;
			}
		}
		return ids;
	}

	string project::getMaterialNameFromId(unsigned long long id)
	{
		//Enter id of mterial and get its name
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			if (myMaterials.at(i)->getMaterialId() == id)
			{
				return myMaterials.at(i)->getTitle();
			}
		}
		return "";
	}

	bool project::hasMaterialType(unsigned int type)
	{
		//Check if this project has a certain material type
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			if (myMaterials.at(i)->getMaterialType() == type)
			{
				return 1;
			}
		}
		return 0;
	}

	//Getter functions:
	unsigned long long project::getProjectId()
	{
		return projectId;
	}

	string project::getTitle()
	{
		return title;
	}

	string project::getSummary()
	{
		return summary;
	}

	string project::getGenre()
	{
		return genre;
	}

	string project::getReleaseDate()
	{
		return releaseDate;
	}

	string project::getLanguage()
	{
		return language;
	}

	vector<string> project::getFilmingLocations()
	{
		return filmingLocations;
	}

	unsigned int project::getProjectStatus()
	{
		return projectStatus;
	}

	string project::getRuntime()
	{
		return runtime;
	}

	string project::getProducer()
	{
		return producer;
	}

	string project::getDirector()
	{
		return director;
	}

	string project::getWriter()
	{
		return writer;
	}

	vector<string> project::getKeywords()
	{
		return keywords;
	}

	string project::getEditor()
	{
		return editor;
	}

	string project::getProductionDesigner()
	{
		return productionDesigner;
	}

	string project::getSetDecorator()
	{
		return setDecorator;
	}

	string project::getCostumeDesigner()
	{
		return costumeDesigner;
	}

	vector<string> project::getCast()
	{
		return cast;
	}

	unsigned int project::getTicketSales()
	{
		return ticketSales;
	}

	//Setter functions:
	void project::setProjectId(unsigned long long idIn)
	{
		projectId = idIn;
	}

	void project::setTitle(string titleIn)
	{
		if (titleIn.size() == 0)
		{
			throw std::invalid_argument("Title selection invalid: input empty");
		}
		if (titleIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Title selection invalid: cannot use comma");
		}
		title = titleIn;
	}

	void project::setSummary(string summaryIn)
	{
		if (summaryIn.size() == 0)
		{
			throw std::invalid_argument("Summary selection invalid: input empty");
		}
		if (summaryIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Summary selection invalid: cannot use comma");
		}
		summary = summaryIn;
	}

	void project::setGenre(string genreIn)
	{
		if (genreIn.size() == 0)
		{
			throw std::invalid_argument("Genre selection invalid: input empty");
		}
		if (genreIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Genre selection invalid: cannot use comma");
		}
		genre = genreIn;
	}

	void project::setReleaseDate(string releaseDateIn)
	{
		if (releaseDateIn.size() == 0)
		{
			throw std::invalid_argument("Release date selection invalid: input empty");
		}
		if (releaseDateIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Release date selection invalid: cannot use comma");
		}
		releaseDate = releaseDateIn;
	}

	void project::setLanguage(string languageIn)
	{
		if (languageIn.size() == 0)
		{
			throw std::invalid_argument("Language selection invalid: input empty");
		}
		if (languageIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Language selection invalid: cannot use comma");
		}
		language = languageIn;
	}

	void project::setFilmingLocations(vector<string> filmingLocationsIn)
	{
		if (filmingLocationsIn.size() == 0)
		{
			throw std::invalid_argument("Filming locations selection invalid: input empty");
		}
		for (unsigned int i = 0; i < filmingLocationsIn.size(); i++)
		{
			if (filmingLocationsIn.at(i).find(",") != string::npos)
			{
				throw std::invalid_argument("Filming locations selection invalid: cannot use comma");
			}
		}
		filmingLocations = filmingLocationsIn;
	}

	void project::resetFilmingLocations()
	{
		filmingLocations = vector<string>();
	}

	void project::addFilmingLocation(string filmingLocationIn)
	{
		if (filmingLocationIn.size() == 0)
		{
			throw std::invalid_argument("Filming location selection invalid: input empty");
		}
		if (filmingLocationIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Filming location selection invalid: cannot use comma");
		}
		filmingLocations.push_back(filmingLocationIn);
	}

	void project::setProjectStatus(unsigned int projectStatusIn)
	{
		if (projectStatusIn > 3)
		{
			throw std::invalid_argument("Project status selection invalid: input not 0, 1 or 2");
		}
		projectStatus = projectStatusIn;
	}

	void project::setRuntime(string runtimeIn)
	{
		if (runtimeIn.size() == 0)
		{
			throw std::invalid_argument("Runtime selection invalid: input empty");
		}
		if (runtimeIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Runtime selection invalid: cannot use comma");
		}
		runtime = runtimeIn;
	}

	void project::setProducer(string producerIn)
	{
		if (producerIn.size() == 0)
		{
			throw std::invalid_argument("Producer selection invalid: input empty");
		}
		if (producerIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Producer selection invalid: cannot use comma");
		}
		producer = producerIn;
	}

	void project::setDirector(string directorIn)
	{
		if (directorIn.size() == 0)
		{
			throw std::invalid_argument("Director selection invalid: input empty");
		}
		if (directorIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Director selection invalid: cannot use comma");
		}
		director = directorIn;
	}

	void project::setWriter(string writerIn)
	{
		if (writerIn.size() == 0)
		{
			throw std::invalid_argument("Writer selection invalid: input empty");
		}
		if (writerIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Writer selection invalid: cannot use comma");
		}
		writer = writerIn;
	}

	void project::setKeywords(vector<string> keywordsIn)
	{
		if (keywordsIn.size() == 0)
		{
			throw std::invalid_argument("Keywords selection invalid: input empty");
		}
		for (unsigned int i = 0; i < keywordsIn.size(); i++)
		{
			if (keywordsIn.at(i).find(",") != string::npos)
			{
				throw std::invalid_argument("Keywords selection invalid: cannot use comma");
			}
		}
		keywords = keywordsIn;
	}

	void project::resetKeywords()
	{
		keywords = vector<string>();
	}

	void project::addKeyword(string keywordIn)
	{
		if (keywordIn.size() == 0)
		{
			throw std::invalid_argument("Keywords selection invalid: input empty");
		}
		if (keywordIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Keywords selection invalid: cannot use comma");
		}
		keywords.push_back(keywordIn);
	}

	void project::setEditor(string editorIn)
	{
		if (editorIn.size() == 0)
		{
			throw std::invalid_argument("Editor selection invalid: input empty");
		}
		if (editorIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Editor selection invalid: cannot use comma");
		}
		editor = editorIn;
	}

	void project::setProductionDesigner(string productionDesignerIn)
	{
		if (productionDesignerIn.size() == 0)
		{
			throw std::invalid_argument("Production designer selection invalid: input empty");
		}
		if (productionDesignerIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Production designer selection invalid: cannot use comma");
		}
		productionDesigner = productionDesignerIn;
	}

	void project::setSetDecorator(string setDecoratorIn)
	{
		if (setDecoratorIn.size() == 0)
		{
			throw std::invalid_argument("Set decorator selection invalid: input empty");
		}
		if (setDecoratorIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Set decorator selection invalid: cannot use comma");
		}
		setDecorator = setDecoratorIn;
	}

	void project::setCostumeDesigner(string costumeDesignerIn)
	{
		if (costumeDesignerIn.size() == 0)
		{
			throw std::invalid_argument("Costume designer selection invalid: input empty");
		}
		if (costumeDesignerIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Costume designer selection invalid: cannot use comma");
		}
		costumeDesigner = costumeDesignerIn;
	}

	void project::setCast(vector<string> castIn)
	{
		if (castIn.size() == 0)
		{
			throw std::invalid_argument("Cast selection invalid: input empty");
		}
		for (unsigned int i = 0; i < castIn.size(); i++)
		{
			if (castIn.at(i).find(",") != string::npos)
			{
				throw std::invalid_argument("Cast selection invalid: cannot use comma");
			}
		}
		cast = castIn;
	}

	void project::resetCast()
	{
		cast = vector<string>();
	}

	void project::addCast(string castIn)
	{
		if (castIn.size() == 0)
		{
			throw std::invalid_argument("Cast selection invalid: input empty");
		}
		if (castIn.find(",") != string::npos)
		{
			throw std::invalid_argument("Cast selection invalid: cannot use comma");
		}
		cast.push_back(castIn);
	}

	void project::setTicketSales(unsigned int ticketSalesIn)
	{
		if (projectStatus != 2)
		{
			throw std::invalid_argument("Ticket sales selection invalid: cannot set ticket sales when not \"Now Playing\"");
		}
		ticketSales = ticketSalesIn;
	}

	void project::resetTicketSales()
	{
		ticketSales = 0;
	}

	//Calculations:
	unsigned long long project::getNextMaterialId()
	{
		if (myMaterials.size() > 0)
		{
			return (myMaterials.at(myMaterials.size() - 1)->getMaterialId()) + 1 + getProjectId();
		}
		else
		{
			return 1 + getProjectId();
		}
	}

	void project::setCurrentMaterial(unsigned long long materialId)
	{
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			if (myMaterials.at(i)->getMaterialId() == materialId)
			{
				currentMaterialIndex = i;
			}
		}
	}

	void project::setCurrentMaterialIndex(int index)
	{
		currentMaterialIndex = index;
	}

	void project::setFromFile(string inFromFile, unsigned int attribute)
	{
		switch (attribute)
		{
		case 0: 
			setTitle(inFromFile);
			break;
		case 1: 
			setSummary(inFromFile);
			break;
		case 2: 
			setGenre(inFromFile);
			break;
		case 3:
			setReleaseDate(inFromFile);
			break;
		case 4:
			setLanguage(inFromFile);
			break;
		case 5:
			addFilmingLocation(inFromFile);
			break;
		case 6:
			setProjectStatus(std::stoi(inFromFile));
			break;
		case 7:
			setRuntime(inFromFile);
			break;
		case 8:
			setProducer(inFromFile);
			break;
		case 9:
			setDirector(inFromFile);
			break;
		case 10:
			setWriter(inFromFile);
			break;
		case 11:
			addKeyword(inFromFile);
			break;
		case 12:
			setEditor(inFromFile);
			break;
		case 13:
			setProductionDesigner(inFromFile);
			break;
		case 14:
			setSetDecorator(inFromFile);
			break;
		case 15:
			setCostumeDesigner(inFromFile);
			break;
		case 16:
			addCast(inFromFile);
			break;
		case 17:
			if (inFromFile == "0")
			{
				resetTicketSales();
			}
			else
			{
				setTicketSales(std::stoul(inFromFile));
			}
			break;
		case 18:
			material * readMaterial = new material(std::stoi(inFromFile), true);
			myMaterials.push_back(readMaterial);
			break;
		}
	}
}