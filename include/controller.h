#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "project.h"

namespace SDI
{
	
	class controller
	{
	private:
		const string projectsFilename = "../data/projectlist.txt";
		//Load in projects:
		void populateListOfProjects();
		//Save currently stored projects
		void saveListOfProjectsToDisk();

	public:
		//Constructor:
		controller();
		//Destructor
		~controller();
		//List of all projects
		vector<project*> projectList;
		vector<project*> toBeRemoved;
		//Index of project we are editing
		int currentProjectIndex = -1;
		//Get vector of all project ids in alphabetical order of title
		vector<unsigned long long> getAlphabeticProjects();
		//Get vector of given ids filtering by project name
		vector<unsigned long long> getProjectsTitleFilter(string titleFilter, vector<unsigned long long>& listIn);
		//Get vector of given ids filtering by actor
		vector<unsigned long long> getProjectsActorFilter(string actorFilter, vector<unsigned long long>& listIn);
		//Ge vector of given ids with type of material
		vector<unsigned long long> getProjectsMaterialFilter(unsigned int materialFilter, vector<unsigned long long>& listIn);

		//Enter id get back name
		string getNameFromId(unsigned long long id);
		//Enter id get back actors
		vector<string> getActorsFromId(unsigned long long id);
		//Check id has material type 
		bool checkProjectHasMaterialType(unsigned long long id, unsigned int type);
		//Remove project with id
		void removeProject(unsigned long long id);
		
		//Calculations:
		unsigned long long getNextProjectId();
		void setCurrentProject(unsigned long long projectId);
		void setCurrentProjectIndex(int index);
	};
}
#endif