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
		//Get 
		
		
		//Calculations:
		unsigned long getNextProjectId();
		void setCurrentProject(unsigned int projectId);
		void setCurrentProject(string projectName);

	};


}


#endif