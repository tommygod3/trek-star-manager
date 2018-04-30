#include "logger.h"

namespace SDI
{
	logger::logger(string date)
	{
		loadInTodaysLog(date);
		todaysDate = date;
	}

	logger::~logger()
	{
		saveTodaysLog();
	}

	void logger::loadInTodaysLog(string date)
	{
		//Load in from log list
		std::ifstream logsIn(logCollectionFilename);
		if (!logsIn.is_open())
		{
			throw std::runtime_error("Error with log list file - cannot find " + logCollectionFilename);
		}
		string parser;
		getline(logsIn, parser);
		if (parser == "")
		{
			todaysFilename = "../data/logs/" + date + ".txt";
			addTodaysLog = 1;
			return;
		}
		string deliminator = ",";
		size_t position = 0;
		string logIn;
		while ((position = parser.find(deliminator)) != std::string::npos)
		{
			logIn = parser.substr(0, position);
			parser.erase(0, position + deliminator.length());
		}
		if (logIn != date)
		{
			todaysFilename = "../data/logs/" + date + ".txt";
			addTodaysLog = 1;
			return;
		}
		todaysFilename = "../data/logs/" + logIn + ".txt";
		logsIn.close();
		//Load in todays log
		std::ifstream todayIn(todaysFilename);
		if (!todayIn.is_open())
		{
			throw std::runtime_error("Error with log file - cannot find " + todaysFilename);
		}
		string parserToday;
		getline(todayIn, parserToday);
		if (parserToday == "")
		{
			return;
		}
		size_t positionToday = 0;
		string infoIn;
		string deliminatorToday = ",";
		while ((positionToday = parserToday.find(deliminatorToday)) != std::string::npos)
		{
			infoIn = parserToday.substr(0, positionToday);
			todaysLog.push_back(infoIn);
			parserToday.erase(0, positionToday + deliminatorToday.length());
		}
		todayIn.close();
	}

	void logger::saveTodaysLog()
	{
		//Todays logs written to file
		std::ofstream logOut(todaysFilename);
		for (unsigned int i = 0; i < todaysLog.size(); i++)
		{
			logOut << todaysLog.at(i) << ",";
		}
		logOut.close();

		//If it was created today, add todays log to log list
		if (addTodaysLog)
		{
			std::ofstream logList(logCollectionFilename);
			logList << todaysDate << ",";
			
			logList.close();
		}
	}

	//Functions to add relevant info to log when something happens
	void logger::logNewProject(string time, string name)
	{
		todaysLog.push_back("New project made at time " + time + " - Title: " + name);
	}

	void logger::logEditProject(string time, string name)
	{
		todaysLog.push_back("Existing project edited at time " + time + " - Title: " + name);
	}

	void logger::logDeleteProject(string time, string name)
	{
		todaysLog.push_back("Project deleted at time " + time + " - Title: " + name);
	}

	void logger::logNewMaterial(string time, string name, string project)
	{
		todaysLog.push_back("New material made at time " + time + " - Title: " + name + " from Project: " + project);
	}

	void logger::logEditMaterial(string time, string name, string project)
	{
		todaysLog.push_back("Existing material edited at time " + time + " - Title: " + name + " from Project: " + project);
	}

	void logger::logDeleteMaterial(string time, string name, string project)
	{
		todaysLog.push_back("Material deleted at time " + time + " - Title: " + name + " from Project: " + project);
	}
}