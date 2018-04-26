#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "project.h"

namespace SDI
{
	
	class controller
	{
	public:
		vector<project*> projectList;
		controller();
		unsigned long getNextProjectId();
	


	};


}


#endif