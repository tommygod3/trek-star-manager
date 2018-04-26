#include "controller.h"

namespace SDI
{
	controller::controller()
	{
		//Load in existing
		populateListOfProjects("../data/projectlist.txt");
	}

	controller::~controller()
	{
		//Save existing
	}

	//Load in existing projects from file
	void controller::populateListOfProjects(string projectsFilename)
	{
		std::ifstream projectsIn(projectsFilename);
		string parser;
		getline(projectsIn, parser);
		if (parser == "")
		{
			return;
		}
		string deliminator = ",";
		size_t position = 0;
		string projectIn;
		while ((position = parser.find(deliminator)) != std::string::npos) 
		{
			projectIn = parser.substr(0, position);
			project* projectRead = new project(std::stol(projectIn),true);
			projectList.push_back(projectRead);
			parser.erase(0, position + deliminator.length());
		}
	}

	//Save existing projects to file

	//Calculations:
	unsigned long controller::getNextProjectId()
	{
		if (projectList.size() > 0)
		{
			return (projectList.at(projectList.size() - 1)->getProjectId()) + 1000;
		}
		else
		{
			return 1;
		}
	}

	void controller::setCurrentProject(unsigned int projectId)
	{
		for (unsigned int i = 0; i < projectList.size(); i++)
		{
			if (projectList.at(i)->getProjectId() == projectId)
			{
				currentProjectIndex = i;
			}
		}
	}
}