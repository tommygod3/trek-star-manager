#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "project.h"

namespace SDI
{
	
	class controller
	{
	public:
		//List of all projects
		vector<project*> projectList;
		//Index of project we are editting
		unsigned int currentProjectIndex;
		//Constructor:
		controller();
		~controller();
		//Calculations:
		unsigned long getNextProjectId();
		void setCurrentProject(unsigned int projectId);


	};


}


#endif