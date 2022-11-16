// Variables2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

void CheckDivisible();
void GenerateRandomNumber();
void TypecastingExperimenting();
void IncrementDecrementExperimenting();
void ExploreStrings();

int main()
{
    srand(time(NULL));


    //CheckDivisible();
    //GenerateRandomNumber();
    //TypecastingExperimenting();
    //IncrementDecrementExperimenting();
    ExploreStrings();

}

void CheckDivisible() {
    int numerator{};
    int divisor{2};
    std::cout << "number: ";
    std::cin >> numerator;
    int remainder{ numerator % divisor };
    std::cout << "uneven: " << remainder;
}

void GenerateRandomNumber() {
    int randomNumber{ rand() };
    std::cout << randomNumber << std::endl;
    randomNumber = rand();
    std::cout << randomNumber << std::endl;


    std::cout << "[0, 50]: " << rand() % 51 << std::endl;
    std::cout << "[10, 80]: " << (rand() % 71)+10 << std::endl;
    std::cout << "[-20, 20]: " << (rand() % 41)-20 << std::endl;
    std::cout << "[-2, 2]: " << (rand() % 5)-2 << std::endl;

    std::cout << "[5.00, 10.00]: " << ((rand() % 501)+500)/100.0f << std::endl;
    std::cout << "[-5.00, 5.00]: " << ((rand() % 1001) - 500) / 100.0f << std::endl;

}

void TypecastingExperimenting() {
    char character{};
    int ascii{};

    std::cout << "Letter? ";
    std::cin >> character;
    ascii = int(character);
    std::cout << ascii << std::endl;

    std::cout << char((rand() % 26) + 97) << std::endl << std::endl;

    double dNumber{ 5.44 };
    std::cout << dNumber << ", rounded: " << round(dNumber) << ", int cast: " << int(dNumber) << std::endl;
    dNumber =  5.45;
    std::cout << dNumber << ", rounded: " << round(dNumber) << ", int cast: " << int(dNumber) << std::endl;
    dNumber = 5.51;
    std::cout << dNumber << ", rounded: " << round(dNumber) << ", int cast: " << int(dNumber) << std::endl << std::endl;

    double aspectRatio{1920.0/1080};
    std::cout << "The aspect ratio of full HD (1920 x 1080) is: " << aspectRatio;


}

void IncrementDecrementExperimenting() {
    int i{ 10 };
    int j{ ++i };
    std::cout << "i: " << i << ", j: " << j << std::endl;
    
    int k{ 10 };
    int l{ k++ };
    std::cout << "k: " << k << ", l: " << l << std::endl;

}

void ExploreStrings() {
    std::string emptyString;
    std::cout << emptyString;

    std::string myString{ "I am a string literal" };
    myString = " I am a reassinged string literal \n";
    std::cout << myString;

    std::cin >> myString;
    std::cout << myString;

    std::string word1{};
    std::string word2{};
    std::cout << "\nFirst word? ";
    std::cin >> word1;
    std::cout << "Second word? ";
    std::cin >> word2;
    std::cout << word1 + word2;

    std::string testString{"gretig"};
    int testInt{7};
    int testChar{ '7' };
    std::cout << testString + std::to_string(5) << std::endl;

    std::string numbersLog{};
    int enteredNr;

    std::cout << "\nEnter an integer value: ";
    std::cin >> enteredNr;
    numbersLog += std::to_string(enteredNr) + " ";

    std::cout << "Enter an integer value: ";
    std::cin >> enteredNr;
    numbersLog += std::to_string(enteredNr) + " ";

    std::cout << "Enter an integer value: ";
    std::cin >> enteredNr;
    numbersLog += std::to_string(enteredNr);

    std::cout << numbersLog;


    std::string integerString{"3"};
    std::string floatString{ "3.1415" };

    std::cout << "\nOne string contains " << integerString;
    std::cout << "\nOther string contains " << floatString;
    std::cout << "\nAdding strings " << integerString + floatString;
    std::cout << "\nAdding numbers " << std::stod (integerString) + std::stod(floatString);

}