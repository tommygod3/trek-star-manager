#include <stdexcept>

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

	//Setter functions:
	void project::setProjectId(unsigned long idIn)
	{
		projectId = idIn;
	}

	void project::setTitle(string titleIn)
	{
		title = titleIn;
	}

	void project::setSummary(string summaryIn)
	{
		summary = summaryIn;
	}

	void project::setGenre(string genreIn)
	{
		genre = genreIn;
	}

	void project::setReleaseDate(string releaseDateIn)
	{
		releaseDate = releaseDateIn;
	}

	void project::setLanguage(string languageIn)
	{
		language = languageIn;
	}

	void project::setFilmingLocations(vector<string> filmingLocationsIn)
	{
		filmingLocations = filmingLocationsIn;
	}

	void project::setProjectStatus(unsigned int projectStatusIn)
	{
		projectStatus = projectStatusIn;
	}

	void project::setRuntime(string runtimeIn)
	{
		runtime = runtimeIn;
	}

	void project::setProducer(string producerIn)
	{
		producer = producerIn;
	}

	void project::setDirector(string directorIn)
	{
		director = directorIn;
	}

	void project::setWriter(string writerIn)
	{
		writer = writerIn;
	}

	void project::setKeywords(vector<string> keywordsIn)
	{
		keywords = keywordsIn;
	}

	void project::setEditor(string editorIn)
	{
		editor = editorIn;
	}

	void project::setProductionDesigner(string productionDesignerIn)
	{
		productionDesigner = productionDesignerIn;
	}

	void project::setSetDecorator(string setDecoratorIn)
	{
		setDecorator = setDecoratorIn;
	}

	void project::setCostumeDesigner(string costumeDesignerIn)
	{
		costumeDesigner = costumeDesignerIn;
	}

	void project::setCast(vector<string> castIn)
	{
		cast = castIn;
	}
}