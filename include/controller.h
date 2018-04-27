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
		//Index of project we are editing
		unsigned int currentProjectIndex;
		//Get vector of all project ids in alphabetical order of title
		vector<unsigned long long> getAlphabeticProjects();
		//Get vector of all project ids filtering by project name and given an id list
		vector<unsigned long long> getAlphabeticProjectsTitleFilter(string titleFilter, vector<unsigned long long>& listIn);
		//Enter id get back name
		string getNameFromId(unsigned long long id);
		
		//Calculations:
		unsigned long long getNextProjectId();
		void setCurrentProject(unsigned int projectId);
		

	};


}


#endif