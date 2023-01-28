#include "pch.h"
#include "iostream"
#include "Time.h"

Time::Time(int seconds) :
Time(0, 0, seconds)
{
}
Time::Time(int minutes, int seconds) :
Time(0, minutes, seconds)
{
}
Time::Time(int hours, int minutes, int seconds) :
	m_Seconds{ HoursToSeconds(hours) + MinutesToSeconds(minutes) + seconds }
{
}

// Member funtions
int Time::HoursToSeconds(int hours)
{
	return hours * 3600;
}
int Time::MinutesToSeconds(int minutes)
{
	return minutes * 60;
}
int Time::SecondsToHours(int seconds)
{
	return seconds / 3600;
}
int Time::SecondsToMinutes(int seconds)
{
	return seconds / 60;
}


//	Getters
void Time::Print()
{
	std::cout << GetHours() << ":" << GetMinutes() << ":" << GetSeconds() << "\n";
}
int Time::GetSeconds(){
	return m_Seconds % 60;
}
int Time::GetMinutes(){

	return ((m_Seconds - GetSeconds()) / 60) % 60;
}
int Time::GetHours() 
{
	return ((m_Seconds - (GetMinutes() * 60) - GetSeconds()) / 3600) % 60;
}

// Setters
void Time::AddSeconds(int seconds)
{
	m_Seconds += seconds;
}
void Time::AddMinutes(int minutes)
{
	m_Seconds += MinutesToSeconds(minutes);
}
void Time::AddHours(int hours)
{
	m_Seconds += HoursToSeconds(hours);
}
