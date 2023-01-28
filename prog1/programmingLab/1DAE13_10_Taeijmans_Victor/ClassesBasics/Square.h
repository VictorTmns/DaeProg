#include "pch.h"

class Square
{
private:
	float m_Left;
	float m_Bottom;
	float m_Size;

	float GetArea();
	float GetPerimeter();

	int HoursToSeconds(int hours);
	int MinutesToSeconds(int minutes);
	int SecondsToHours(int seconds);
	int SecondsToMinutes(int seconds);
public:
	Square(float size);
	Square(float size, float Bottom, float left);

	~Square();

	void Print();
	void Translate(float deltaLeft, float deltaBottom);
	void Setsize(float newSize);


};