#ifndef PROJECT_H
#define PROJECT_H

#include "material.h"

namespace SDI
{
	class project
	{
	private:
		//Filename at loading
		string projectFilename;
		//Unique ID to identify project
		unsigned long long projectId;
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
		//If this will be saved
		bool toBeSaved = 1;

	public:
		//Vector of the projects associated materials
		vector<material*> myMaterials;
		vector<material*> toBeRemoved;
		//Index of material we are editing
		int currentMaterialIndex = -1;
		//Constructor setting project id
		project(unsigned long long id, bool exists);
		//Destructor
		~project();
		//Load in variables from file
		void loadIn();
		//Save variables to a file
		void saveOut();
		//Remove this project
		void removeThisProject();
		//Remove a material
		void removeMaterial(unsigned long long id);
		//Get vector of all material ids in alphabetical order of title
		vector<unsigned long long> getAlphabeticMaterials();
		//Enter id get back name
		string getMaterialNameFromId(unsigned long long id);
		//Check if project has certain types of material
		bool hasMaterialType(unsigned int type);
		//Getters:
		unsigned long long getProjectId();
		string getTitle();
		string getSummary();
		string getGenre();
		string getReleaseDate();
		string getLanguage();
		vector<string> getFilmingLocations();
		//0 = Released, 1 = Unreleased, 2 = Now Playing
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
		void setProjectId(unsigned long long idIn);
		void setTitle(string titleIn);
		void setSummary(string summaryIn);
		void setGenre(string genreIn);
		void setReleaseDate(string releaseDateIn);
		void setLanguage(string languageIn);
		void setFilmingLocations(vector<string> filmingLocationsIn);
		void resetFilmingLocations();
		void addFilmingLocation(string filmingLocationIn);
		void setProjectStatus(unsigned int projectStatusIn);
		void setRuntime(string runtimeIn);
		void setProducer(string producerIn);
		void setDirector(string directorIn);
		void setWriter(string writerIn);
		void setKeywords(vector<string> keywordsIn);
		void resetKeywords();
		void addKeyword(string keywordIn);
		void setEditor(string editorIn);
		void setProductionDesigner(string productionDesignerIn);
		void setSetDecorator(string setDecoratorIn);
		void setCostumeDesigner(string costumeDesignerIn);
		void setCast(vector<string> castIn);
		void resetCast();
		void addCast(string castIn);
		void setTicketSales(unsigned int ticketSalesIn);
		void resetTicketSales();
		//Calculations:
		unsigned long long getNextMaterialId();
		void setCurrentMaterial(unsigned long long materialId);
		void setCurrentMaterialIndex(int index);
		void setFromFile(string inFromFile, unsigned int attribute);
	};
}

#endif