#include "controller.h"

namespace SDI
{
	controller::controller()
	{
		//Load in existing
		populateListOfProjects();
	}

	controller::~controller()
	{
		//Save existing
		saveListOfProjectsToDisk();
		//Free up memory held by list
		for (unsigned int i = 0; i < projectList.size(); i++)
		{
			delete projectList.at(i);
		}
		projectList.clear();

	}

	//Load in existing projects from file
	void controller::populateListOfProjects()
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
		projectsIn.close();
	}

	//Save existing projects to file
	void controller::saveListOfProjectsToDisk()
	{
		std::ofstream projectsOut(projectsFilename);
		for (unsigned int i = 0; i < projectList.size(); i++)
		{
			projectsOut << std::to_string(projectList.at(i)->getProjectId()) << ",";
			
		}
		projectsOut.close();
	}

	vector<unsigned long> controller::getAlphabeticProjects()
	{
		vector<unsigned long> ids;
		//sort, return
	}

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