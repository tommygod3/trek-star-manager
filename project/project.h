#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>

namespace SDI
{
	using std::vector;
	using std::string;

	class project
	{
	private:
		//Private member variables that make up project
		unsigned long projectId;
		string title;
		string summary;
		string genre;
		string releaseDate;
		string language;
		vector<string> filmingLocations;
		unsigned int projectStatus;
		string runtime;
		string producer;
		string director;
		string writer;
		vector<string> keywords;
		string editor;
		string productionDesigner;
		string setDecorator;
		string costumeDesigner;
		vector<string> cast;

	public:
		//Constructor setting project id
		project(unsigned long id);
		//Getters:
		unsigned long getProjectId();
		string getTitle();
		string getSummary();
		string getGenre();
		string getReleaseDate();
		string getLanguage();
		vector<string> getFilmingLocations();
		unsigned int getProjectStatus();
		string getRuntime();
		string getProducer();
		string getDirector();
		string getWriter();
		vector<string> getKeywords();
		string getEditor();
		string getProductionDesigner();
		string getSetDecorator();
		string getCostumeDesigner();
		vector<string> getCast();
		//Setters:
		void setProjectId(unsigned long idIn);
		void setTitle(string titleIn);
		void setSummary(string summaryIn);
		void setGenre(string genreIn);
		void setReleaseDate(string releaseDateIn);
		void setLanguage(string languageIn);
		void setFilmingLocations(vector<string> filmingLocationsIn);
		void setProjectStatus(unsigned int projectStatusIn);
		void setRuntime(string runtimeIn);
		void setProducer(string producerIn);
		void setDirector(string directorIn);
		void setWriter(string writerIn);
		void setKeywords(vector<string> keywordsIn);
		void setEditor(string editorIn);
		void setProductionDesigner(string productionDesignerIn);
		void setSetDecorator(string setDecoratorIn);
		void setCostumeDesigner(string costumeDesignerIn);
		void setCast(vector<string> castIn);
	};
}

#endif