#ifndef PROJECT_H
#define PROJECT_H

#include "material.h"

namespace SDI
{
	class project
	{
	private:
		//Unique ID to identify project
		unsigned long projectId;
		//Inputted by user:
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
		unsigned int ticketSales = 0;

	public:
		//Vector of the projects associated materials
		vector<material*> myMaterials;
		//Index of material we are editing
		unsigned int currentMaterialIndex;
		//Constructor setting project id
		project(unsigned long id, bool exists);
		//Load in variables from file
		void loadIn(string projectFilename);
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
		unsigned int getTicketSales();
		//Setters:
		void setProjectId(unsigned long idIn);
		void setTitle(string titleIn);
		void setSummary(string summaryIn);
		void setGenre(string genreIn);
		void setReleaseDate(string releaseDateIn);
		void setLanguage(string languageIn);
		void setFilmingLocations(vector<string> filmingLocationsIn);
		void addFilmingLocation(string filmingLocationIn);
		void setProjectStatus(unsigned int projectStatusIn);
		void setRuntime(string runtimeIn);
		void setProducer(string producerIn);
		void setDirector(string directorIn);
		void setWriter(string writerIn);
		void setKeywords(vector<string> keywordsIn);
		void addKeyword(string keywordIn);
		void setEditor(string editorIn);
		void setProductionDesigner(string productionDesignerIn);
		void setSetDecorator(string setDecoratorIn);
		void setCostumeDesigner(string costumeDesignerIn);
		void setCast(vector<string> castIn);
		void addCast(string castIn);
		void setTicketSales(unsigned int ticketSalesIn);
		//Calculations:
		unsigned long getNextMaterialId();
		void setCurrentMaterial(unsigned int materialId);
		void setFromFile(string inFromFile, unsigned int attribute);
	};
}

#endif