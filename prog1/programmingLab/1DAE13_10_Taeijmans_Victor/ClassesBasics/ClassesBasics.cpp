// ClassesBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Square.h"
#include "Time.h"

void DoSquareTests(Square* pSquare3);
void DoTimeTests();

int main()
{
    Square* pSquare3{ new Square{3.f, 4.f, 12.f} };
    //DoSquareTests(pSquare3);

    DoTimeTests();
}

void DoSquareTests(Square* pSquare3) 
{
    Square* pSquare{ new Square{3.f} };


    pSquare3->Print();

    pSquare3->Translate(1.f, 1.f);

    pSquare3->Setsize(8.f);

    pSquare3->Print();


    delete pSquare;
    pSquare = nullptr;

    delete pSquare3;
    pSquare3 = nullptr;
}
void DoTimeTests()
{
    Time* pTime(new Time(10, 10, 10));

    pTime->Print();

    pTime->AddHours(4);

    pTime->Print();

    delete pTime;
    pTime = nullptr;
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
