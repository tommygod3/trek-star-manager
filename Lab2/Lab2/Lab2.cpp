// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct timeType
{
	int hour;
	double minutes;
	int seconds;
};

struct tourType
{
	string cityName;
	int distance;
	timeType travelTime;
};

void outputTour(tourType tour)
{
	cout << "City: " << tour.cityName << endl;
	cout << "Distance in miles: " << tour.distance << endl;
	cout << "Travel time is: ";
	if (tour.travelTime.hour > 0)
	{
		cout << tour.travelTime.hour << " hours ";
	}
	if (tour.travelTime.minutes > 0)
	{
		cout << tour.travelTime.minutes << " minutes ";
	}
	if (tour.travelTime.seconds > 0)
	{
		cout << tour.travelTime.seconds << " seconds.";
	}
	cout << endl;
}

tourType inputTour(string cityname, int distance, timeType time)
{
	tourType tourname;
	tourname.cityName = cityname;
	tourname.distance = distance;
	tourname.travelTime = { time };
	return tourname;
}

void userinput(tourType &tour)
{
	cout << "What city is the tour in?" << endl;
	cin >> tour.cityName;
	cout << endl << "How far away is the city?" << endl;
	cin >> tour.distance;
	cout << endl << "How long is the tour in " << endl << "Hours: ";
	cin >> tour.travelTime.hour;
	cout << endl << "Minutes: ";
	cin >> tour.travelTime.minutes;
	cout << endl << "Seconds: ";
	cin >> tour.travelTime.seconds;
}

int main()
{
	
	tourType destination = inputTour("Nottingham", 130, { 3,15 });
	outputTour(destination); 

	userinput(destination);
	outputTour(destination);
	

    return 0;
}

