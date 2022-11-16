// Expressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    int randomInteger{4};
    char randomCharacter{'A'};
    char randomNumberCharacter{'4'};
    float randomFloatingPointNumber{4.9738791f};

    std::cout << "integer variable + integer literal: " << randomInteger + 4 << "\n";

    std::cout << "character variable + integer literal: " << randomCharacter + 4 << "\n";

    std::cout << "character variable - int literal bigger than character ascii value: " << randomCharacter - 64 << "\n";

    char negChar{};
    negChar = randomCharacter - 70;
    std::cout << "character variable - int literal bigger than character ascii value in a char: " << negChar << "\n";

    std::cout << "integer variable + integer literal: " << randomNumberCharacter - 3 << "\n";

    std::cout << "number in character variable - literal integer: " << randomFloatingPointNumber - 8 << "\n";

    std::cout << "float variable + integer literal: " << randomFloatingPointNumber + 4 << "\n";

    std::cout << "integer variable + character variable: " << randomInteger - randomCharacter << "\n";

    int intFloat{};
    intFloat = randomInteger + randomFloatingPointNumber;
    std::cout << "integer variable + float variable in integer: " << intFloat << "\n";

    char floatChar{};
    floatChar = randomInteger + randomFloatingPointNumber;
    std::cout << "integer variable + float variable in a character: " << floatChar << "\n";

    char intChar{};
    intChar = 64;
    std::cout << "integer in chararacter: " << intChar << "\n";

    std::cout << "integer variable * integer literal: " << randomInteger * 4 << "\n";

    int compInt{7};
    compInt += 4;
    std::cout << "integer compounded + 4: " << compInt << "\n";
        
    float compFloat{7.067567f};
    compFloat += 9;
    std::cout << "float compounded + 9: " << compFloat << "\n";

    char compchar{'C'};
    compchar += 9;
    std::cout << "char compounded + 9: " << compchar << "\n";

    int compMultInt{4};
    compMultInt *= 9;
    std::cout << "char compounded + 9: " << compMultInt << "\n";

    int compMultInt{4};
    compMultInt *= 9;
    std::cout << "char compounded + 9: " << compMultInt << "\n";




}
