#include "controller.h"

namespace SDI
{
	controller::controller()
	{
		//Load in existing
	}

	controller::~controller()
	{
		//Save existing
	}

	//Load in existing projects from file

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