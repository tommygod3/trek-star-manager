#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "project.h"

namespace SDI
{
	
	class controller
	{
	private:
		//Load in projects:
		void populateListOfProjects(string projectsFilename);

	public:
		//Constructor:
		controller();
		//Destructor
		~controller();
		//List of all projects
		vector<project*> projectList;
		//Index of project we are editing
		unsigned int currentProjectIndex;
		
		
		//Calculations:
		unsigned long getNextProjectId();
		void setCurrentProject(unsigned int projectId);


	};


}


#endif