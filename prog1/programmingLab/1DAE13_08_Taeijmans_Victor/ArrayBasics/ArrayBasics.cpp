// ArrayBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "structs.h"
#include <iostream>

void PrintElements(int* pIntegers, int sizeOfArray);
void PrintElements(int* pIntegers, int startIdx, int endIdx);
void Test2dArrays();
int GetIndex(int rowIdx, int colIdx, int nrCols);

int main()
{

	const int sizeArrays{ 5 };

	int arrIntegers1[sizeArrays]{};
	int arrIntegers2[sizeArrays] { 38, 94, 19, 7, 56 };
	int arrIntegers3[sizeArrays]{ 81, 4, 92 };
	Point2f arrPoints[sizeArrays]{};


	std::cout << "-- Accessing elements --\n";
 	std::cout << "First element: " << arrIntegers1[0] << "\n";
	std::cout << "Last element: " << arrIntegers1[4] << "\n";

	std::cout << "\nIterating over the elements\n";
	PrintElements(arrIntegers1, (sizeof(arrIntegers1)/sizeof(arrIntegers1[0])));
	PrintElements(arrIntegers3, (sizeof(arrIntegers3) / sizeof(arrIntegers3[0])));


	std::cout << "\n\n\n-- Size of arrays --";
	std::cout << "\n2nd array";
	std::cout << "\n  nr of bytes: " << sizeof(arrIntegers2);
	std::cout << "\n  size of one element: " << sizeof(arrIntegers2[0]);
	std::cout << "\n  nr of elements: " << sizeof(arrIntegers2)/sizeof(arrIntegers2[0]);
	
	
	std::cout << "\n\n\n-- The elements occupy consecutive memory locations --\n";
	std::cout << "array with int types\n";
	for (int idx = 0; idx < sizeArrays; idx++)
	{
		std::cout << "Addres of  element wth index " << idx << " is ";
		std::cout << &arrIntegers2[idx] << "\n";
	}
	std::cout << "\narray with Point2f types\n";
	for (int idx = 0; idx < sizeArrays; idx++)
	{
		std::cout << "Addres of  element wth index " << idx << " is ";
		std::cout << &arrPoints[idx] << "\n";
	}



	std::cout << "\n\n\n-- Passing an array to a Function, PrintElements --\n";
	std::cout << "print all elements\n";
	PrintElements(arrIntegers1, sizeArrays);
	std::cout << "\n";
	PrintElements(arrIntegers2, sizeArrays);
	std::cout << "\n";
	PrintElements(arrIntegers3, sizeArrays);
	std::cout << "\n";
	std::cout << "print a range of elements\n";
	PrintElements(arrIntegers2, 2, 4);
	

	std::cout << "\n\n\n-- 2D arrays --";
	Test2dArrays();

}

void PrintElements(int* pIntegers, int sizeOfArray)
{
	for (int idx = 0; idx < sizeOfArray; idx++)
	{
		std::cout << pIntegers[idx] << " ";
	}
}

void PrintElements(int* pIntegers, int startIdx, int endIdx) 
{

	for (int idx = startIdx; idx < endIdx+1; idx++)
	{
		std::cout << pIntegers[idx] << " ";
	}
}

void Test2dArrays()
{
	const int lengtArrayInts{ 20 };
	const int arrayNrCols{ 5 };
	const int arrayNrRows{ lengtArrayInts / arrayNrCols };
	int arrInts[lengtArrayInts]{};

	for (int col = 0; col < arrayNrCols; col++)
	{
		for (int row = 0; row < arrayNrRows; row++)
		{
			int index{ GetIndex(row, col, arrayNrCols) };
			arrInts[index] = ((row + 1) * 10) + (col + 1);
		}
	}

	std::cout << "\n";
	for (int idx = 0; idx < lengtArrayInts; idx++)
	{
		std::cout << arrInts[idx] << " ";
		if ((idx + 1) % 5 == 0) std::cout << "\n";
	}
}

int GetIndex(int rowIdx, int colIdx, int nrCols)
{
	return rowIdx * nrCols + colIdx;
}