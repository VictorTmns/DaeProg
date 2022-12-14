#include "pch.h"
#include <iostream>
#include <ctime>
#include <string> 

#pragma region Function declarations

// Function declarations
void DetermineSkill();
void GetColorCodes();
void Wait();

#pragma endregion Function declarations


int main()
{
	std::cout << "== ErrorSolving - name, firstname - 1DAExx ==\n";
	// rand seed
	srand(unsigned int(time(nullptr)));

	DetermineSkill();
	GetColorCodes();
	Wait();
}

#pragma region Function definitions
// Function definitions
void GetColorCodes()
{
	std::cout << "\n-- GetColorCodes function --\n";

	const enum class color {
		wrong,
		magenta,
		yellow,
		cyan
	};

	std::string menu{ "\nMake your choice\n" };
	std::string choice1{ std::to_string(color) };
	std::string choice2{ std::to_string(color{1}) };
	std::string choice3{ std::to_string(color{1}) };

	bool quit{ false };
	int choice{};
	std::cout << menu;
	std::cin >> choice;
	color colorChoice{static_cast<color>(choice)};
	switch (colorChoice)
	{
	case color::magenta:
		std::cout << "Magenta 0xFF00FF\n";
		break;
	case color::yellow:
		std::cout << "Yellow 0xFFFF00\n";
		break;
	case color::cyan:
		std::cout << "Cyan 0x00FFFF\n";
		break; 
	default:
		std::cout << "Wrong choice\n";
		break;
	}

	std::cin.ignore();
}


void DetermineSkill()
{
	std::cout << "\n-- DetermineSkill function --\n";

	int years{};
	std::cout << "Your years of experience ? ";
	std::cin >> years;
	std::string level{};
	if (years < 5)
	{
		level = "Junior level";
	}
	else if (years < 10)
	{
		level = "Intermediate level";
	}
	else
	{
		level = "Senior level";
	}
	std::cout << level << std::endl;

	std::cin.ignore();
}

void Wait()
{
	std::cout << "Press ENTER to quit";
	std::cin.get();
}