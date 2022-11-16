//Taeijmans, Victor - 1DAE13

#include "pch.h"
#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>

void ShowData(); // functions forwarding
void ShowStudentHistory();
void EnterToQuit();
void TestOneParFunctions();
void TestTwoParFunctions();

int main( )
{
	//// 1. Show my data
	ShowData();

	// 2. Show my student history
	ShowStudentHistory();

	// 3.1.2 exercise c
	TestOneParFunctions();

	// 3.1.3
	TestTwoParFunctions();

	// Wait
	EnterToQuit();

	return 0;
}

void ShowData() {
	std::cout << "My name is name, firstname" << std::endl;
	std::cout << "I am in group 1DAExx" << std::endl << std::endl;
}

void ShowStudentHistory() {
	std::cout << "Name of my high school: " << std::endl;
	std::cout << "In the last year I had ... hours math a week" << std::endl << std::endl;
}

void TestOneParFunctions() {
	std::cout << cos(1) << std::endl;

	double angle{};
	double testCos{ cos(angle) };
	std::cout << "Angle: " << angle << std::endl << "cos: " << testCos << std::endl;

	double pi{ 3.1415926535 };
	angle = pi/4;
	testCos = cos(angle);
	std::cout << "Angle: " << angle << std::endl << "cos: " << testCos << std::endl;

	angle += pi/4;
	testCos = cos(angle);
	std::cout << "Angle: " << angle << std::endl << "cos: " << testCos << std::endl;

	angle += pi / 4;
	testCos = cos(angle);
	std::cout << "Angle: " << angle << std::endl << "cos: " << testCos << std::endl;

	angle += pi / 4;
	testCos = cos(angle);
	std::cout << "Angle: " << angle << std::endl << "cos: " << testCos << std::endl;

	angle = pi;
	testCos = cos(angle*2);
	std::cout << "Angle: " << angle*2 << std::endl << "cos: " << testCos << std::endl << std::endl;


}

void TestTwoParFunctions() {
	int number1{ 2 };
	int number2{ 8 };
	double result{ pow(number1, number2) };
	std::cout << result << std::endl << std::endl;

	float side1{ 3 };
	float side2{ 4 };

	double hypotalamus{ sqrt(pow(side1, 2) + pow(side2,2)) };
	std::cout << "hypothalamus of a triangle with sides " << side1 << " and " << side2 << ": " << hypotalamus << std::endl;
}

void EnterToQuit() {
	std::cout << "Push ENTER to quit\n";
	std::cin.get();
}
