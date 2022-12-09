// Taeijmans, Victor 1DAE13E

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

void CalcCosSin(const float angle, float &cos, float &sin);
void TestCalcCosSin();

int main()
{
	srand(int(time(NULL)));
	TestCalcCosSin();
}


void TestCalcCosSin()
{
	float pi{ 3.1415f };


	std::cout << "--Function that calculates cosine and sine--\n";
	float cos, sin;

	std::cout << std::setw(10) << "Radians" << std::setw(10) << "Cos" << std::setw(10) << "Sin" << "\n";

	for (int i = 0; i < 10; i++)
	{
		float angle{ (rand() % int(200 * pi))/100.f };
		CalcCosSin(angle, cos, sin);
		std::cout << std::setw(10) << angle << std::setw(10) << std::setprecision(2) << std::fixed << cos << std::setw(10) << std::setprecision(2) << std::fixed << sin << "\n";
	}
}
void CalcCosSin(const float angle, float &cos, float &sin)
{
	cos = cosf(angle);
	sin = sinf(angle);
}