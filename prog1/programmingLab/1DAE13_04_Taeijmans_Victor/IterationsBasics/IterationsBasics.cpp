// IterationsBasics - Taeijmans, Victor - DAE13E

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

void PrintEvenNumbers();
void CalculateExamScores();
void GuessNumber();
void CalculateTrigoniometricNumbers();
void PrintAsciiTable();

int main()
{
	PrintEvenNumbers();
	CalculateExamScores();
	GuessNumber();
	CalculateTrigoniometricNumbers();
	PrintAsciiTable();
}

void PrintEvenNumbers() {
	std::cout << " -- Even numbers --\n";
	for (int i = 0; i < 24; i += 2)
	{
		std::cout << i << " ";
	};
	std::cout << "\n";



	int iWhile{ 0 };
	while (iWhile < 24)
	{
		std::cout << iWhile << " ";
		iWhile += 2;
	};
	std::cout << "\n";



	int iDoWhile{ 0 };
	do {
		std::cout << iDoWhile << " ";
		iDoWhile += 2;
	} while (iDoWhile < 24);
	std::cout << "\n";
	std::cout << "\n";


}

void CalculateExamScores() {
	std::cout << "-- Exam Scores --\n";


	int currentScore{ 0 };
	std::string scoreString{ "Entered Scores: " };
	int totalScore{};

	int amountApScores{};
	int amountAScores{};
	int amountBScores{};
	int amountCScores{};
	int amountDScores{};
	int amountEScores{};
	int amountFXScores{};
	int amountFScores{};

	do {
		std::cout << "Score [0, 20] ? ";
		std::cin >> currentScore;


		if (currentScore < -1 || currentScore > 20) {
			std::cout << "Wrong score!\n";
		}
		else if (currentScore >= 18) {
			++amountApScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		}
		else if (currentScore >= 16) {
			++amountAScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		}
		else if (currentScore >= 15) {
			++amountBScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		}
		else if (currentScore >= 13) {
			++amountCScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		}
		else if (currentScore >= 11) {
			++amountDScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		}
		else if (currentScore >= 10) {
			++amountEScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		}
		else if (currentScore >= 8) {
			++amountFXScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		}
		else if (currentScore >= 0) {
			++amountFScores;
			totalScore += currentScore;
			scoreString += std::to_string(currentScore) + ", ";
		};

	} while (currentScore != -1);

	std::cout << "\nA+: " << amountApScores;
	std::cout << "\nA: " << amountAScores;
	std::cout << "\nB: " << amountBScores;
	std::cout << "\nC: " << amountCScores;
	std::cout << "\nD: " << amountDScores;
	std::cout << "\nE: " << amountEScores;
	std::cout << "\nFX: " << amountFXScores;
	std::cout << "\nF: " << amountFScores;

	std::cout << "\ntotalScore: " << totalScore;
	std::cout << "\n";
	std::cout << scoreString;
}

void GuessNumber() {
	std::cout << "\n\n-- Guess number --\n";
	int number{};
	int amountGuesses{};
	int guessedNumber{};



	do {
		std::cout << "Number to guess? ";
		std::cin >> number;

		if (number < 0 || number > RAND_MAX)
		{
			std::cout << "This is a wrong number, ";
		}


	} while (number < 0 || number > RAND_MAX);


	do {
		guessedNumber = rand()%RAND_MAX;
		++amountGuesses;
	} while (number != guessedNumber);

	std::cout << "Number found after " << amountGuesses << " guesses";

}

void CalculateTrigoniometricNumbers() {
	float pi{ 3.1414f };
	std::cout << "\n\n-- Trigonometry --\n";
	std::cout << std::setw(10);
	std::cout << std::setw(10) << "Degrees" << std::setw(10) << "Radians" << std::setw(10) << "Cos" << std::setw(10) << "Sin" << "\n";
	
	for (int i = 0; i < 181; i+=10)
	{
		float degrees{ float(i) };
		float Radians{ round(degrees/180.f*pi * 100) / 100 };
		float sin{ round(sinf(Radians)*100)/100 };
		float cos{ round(cosf(Radians) *100) / 100};

		std::cout << std::setw(10) << degrees << std::setw(10) << Radians << std::setw(10) << cos << std::setw(10) << sin << "\n";
	}
}

void PrintAsciiTable() {
	std::cout << "\n\n-- ASCII table --\n";

	for (int i = 0; i < 13; i++)
	{

		std::cout << char(97 + i) << std::setw(10) << i + 97 << std::setw(4) << char(110 + i) << std::setw(10) << i + 110 << "\n";

	}
}