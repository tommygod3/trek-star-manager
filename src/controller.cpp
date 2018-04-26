#include "controller.h"

namespace SDI
{
	controller::controller()
	{
		
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
}