#ifndef LOGGER_H
#define LOGGER_H

#include "project.h"

namespace SDI
{
	class logger
	{
	private:
		const string logCollectionFilename = "../data/logs/loglist.txt";
		string todaysFilename;
		string todaysDate;
		bool addTodaysLog = 0;
		void loadInTodaysLog(string date);
		void saveTodaysLog();

	public:
		logger(string date);
		~logger();
		//The log
		vector<string> todaysLog;
		//Functions to add relevant info to the log
		void logNewProject(string time, string name);
		void logEditProject(string time, string name);
		void logDeleteProject(string time, string name);
		void logNewMaterial(string time, string name, string project);
		void logEditMaterial(string time, string name, string project);
		void logDeleteMaterial(string time, string name, string project);
	};
}

#endif