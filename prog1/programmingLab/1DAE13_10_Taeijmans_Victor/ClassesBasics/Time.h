#pragma once
#include "pch.h"

class Time {
private:
	int m_Seconds;

	int HoursToSeconds(int hours);
	int MinutesToSeconds(int minutes);
	int SecondsToHours(int seconds);
	int SecondsToMinutes(int seconds);

public:
	//constructor
	Time(int seconds);
	Time(int minutes, int seconds);
	Time(int hours ,int minutes, int seconds);


	//Getters
	void Print();
	int GetSeconds();
	int GetMinutes();
	int GetHours();
	//Setters
	void AddSeconds(int seconds);
	void AddMinutes(int minutes);
	void AddHours(int hours);
};