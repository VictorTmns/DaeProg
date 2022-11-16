// Demo02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

int main()
{
    std::string split{ "---------------------------------------------------------\n" };

    split = '1' + split;

    std::cout << "Hello World!\n";

    std::cout << split;

    std::cout << "next exercise \n";

    std::cout <<  split;

    int number{ 4 };
    float fNumber{ 2.13f };
    double dNumber{ 4.3523 };
    char character{ 'R' };
    std::cout << "The size of number is " << sizeof(number) << std::endl;
    std::cout << "The size of fNumber is " << sizeof(fNumber) << std::endl;
    std::cout << "The size of dNumber is " << sizeof(dNumber) << std::endl;
    std::cout << "The size of character is " << sizeof(character) << std::endl;
    std::cout << "The size of split string is " << sizeof(split) << std::endl;

    split += std::to_string(number);

    std::cout << split;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
