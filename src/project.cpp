#include "project.h"

namespace SDI
{
	project::project(unsigned long id)
	{
		this->setProjectId(id);
	}

	//Getter functions:
	unsigned long project::getProjectId()
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
	void project::setProjectId(unsigned long idIn)
	{
		projectId = idIn;
	}

	void project::setTitle(string titleIn)
	{
		if (titleIn.size() == 0)
		{
			throw std::invalid_argument("Title selection invalid: input empty");
		}
		title = titleIn;
	}

	void project::setSummary(string summaryIn)
	{
		if (summaryIn.size() == 0)
		{
			throw std::invalid_argument("Summary selection invalid: input empty");
		}
		summary = summaryIn;
	}

	void project::setGenre(string genreIn)
	{
		if (genreIn.size() == 0)
		{
			throw std::invalid_argument("Genre selection invalid: input empty");
		}
		genre = genreIn;
	}

	void project::setReleaseDate(string releaseDateIn)
	{
		if (releaseDateIn.size() == 0)
		{
			throw std::invalid_argument("Release date selection invalid: input empty");
		}
		releaseDate = releaseDateIn;
	}

	void project::setLanguage(string languageIn)
	{
		if (languageIn.size() == 0)
		{
			throw std::invalid_argument("Language selection invalid: input empty");
		}
		language = languageIn;
	}

	void project::setFilmingLocations(vector<string> filmingLocationsIn)
	{
		if (filmingLocationsIn.size() == 0)
		{
			throw std::invalid_argument("Filming locations selection invalid: input empty");
		}
		filmingLocations = filmingLocationsIn;
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
		runtime = runtimeIn;
	}

	void project::setProducer(string producerIn)
	{
		if (producerIn.size() == 0)
		{
			throw std::invalid_argument("Producer selection invalid: input empty");
		}
		producer = producerIn;
	}

	void project::setDirector(string directorIn)
	{
		if (directorIn.size() == 0)
		{
			throw std::invalid_argument("Director selection invalid: input empty");
		}
		director = directorIn;
	}

	void project::setWriter(string writerIn)
	{
		if (writerIn.size() == 0)
		{
			throw std::invalid_argument("Writer selection invalid: input empty");
		}
		writer = writerIn;
	}

	void project::setKeywords(vector<string> keywordsIn)
	{
		if (keywordsIn.size() == 0)
		{
			throw std::invalid_argument("Keywords selection invalid: input empty");
		}
		keywords = keywordsIn;
	}

	void project::setEditor(string editorIn)
	{
		if (editorIn.size() == 0)
		{
			throw std::invalid_argument("Editor selection invalid: input empty");
		}
		editor = editorIn;
	}

	void project::setProductionDesigner(string productionDesignerIn)
	{
		if (productionDesignerIn.size() == 0)
		{
			throw std::invalid_argument("Production designer selection invalid: input empty");
		}
		productionDesigner = productionDesignerIn;
	}

	void project::setSetDecorator(string setDecoratorIn)
	{
		if (setDecoratorIn.size() == 0)
		{
			throw std::invalid_argument("Set decorator selection invalid: input empty");
		}
		setDecorator = setDecoratorIn;
	}

	void project::setCostumeDesigner(string costumeDesignerIn)
	{
		if (costumeDesignerIn.size() == 0)
		{
			throw std::invalid_argument("Costume designer selection invalid: input empty");
		}
		costumeDesigner = costumeDesignerIn;
	}

	void project::setCast(vector<string> castIn)
	{
		if (castIn.size() == 0)
		{
			throw std::invalid_argument("Cast selection invalid: input empty");
		}
		cast = castIn;
	}

	void project::setTicketSales(unsigned int ticketSalesIn)
	{
		if (projectStatus != 2)
		{
			throw std::invalid_argument("Ticket sales selection invalid: cannot set ticket sales when not \"Now Playing\"");
		}
		ticketSales = ticketSalesIn;
	}

	//Calculations:
	unsigned long project::getNextMaterialId()
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

	void project::setCurrentMaterial(unsigned int materialId)
	{
		for (unsigned int i = 0; i < myMaterials.size(); i++)
		{
			if (myMaterials.at(i)->getMaterialId() == materialId)
			{
				currentMaterialIndex = i;
			}
		}
	}
}