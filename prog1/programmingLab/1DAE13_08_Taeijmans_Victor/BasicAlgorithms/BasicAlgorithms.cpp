// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void PrintElements(int* pInts, int size);

void TestCount();
void TestMinMax();
void TestSwap();
void TestShuffle();
void TestBubbleSort();

int Count(int* pInts, int size, int number);
int MinElement(int* pInts, int size);
int MaxElement(int* pInts, int size);
void Swap(int* pInts, int idx1, int idx2);
void Shuffle(int* pInts, int size, int numSwaps);
void BubbleSort(int* pInts, int size);

const int sizeArrInts1{ 18 };
const int sizeArrInts2{ 11 };
int arrInts1[sizeArrInts1]{-3, 8, 9, 1, -2, 9, 4, 6, 3, 7, -9, 0, 3, -8, -5, 2, 0, 1};
int arrInts2[sizeArrInts2]{2, 5, -7, 8, 9, 0, 4, -3, 5, -6, 6};

int main()
{
	srand(time(NULL));
	TestCount();
	TestMinMax();
	TestSwap();
	TestShuffle();
	TestBubbleSort();
}


void TestCount()
{
    std::cout << "\n\n\n-- Test of count function --\n";
	PrintElements(arrInts1, sizeArrInts1);
    std::cout << "\n" << -3 << "\ occurs " << Count(arrInts1, sizeArrInts1, -3) << " times in this array";
}
void TestMinMax()
{
	std::cout << "\n\n\n-- Test of min and max function --\n";
	PrintElements(arrInts1, sizeArrInts1);
	std::cout << "\n" << MinElement(arrInts1, sizeArrInts1) << " is the smallest item in this array";
	std::cout << "\n" << MaxElement(arrInts1, sizeArrInts1) << " is the biggest item in this array";

	std::cout << "\n\n";
	PrintElements(arrInts2, sizeArrInts2);
	std::cout << "\n" << MinElement(arrInts2, sizeArrInts2) << " is the smallest item in this array";
	std::cout << "\n" << MaxElement(arrInts2, sizeArrInts2) << " is the biggest item in this array";
}
void TestSwap()
{
	std::cout << "\n\n\n-- Test of Swap Function --";
	std::cout << "\nbefore swap\n";
	PrintElements(arrInts1, sizeArrInts1);

	Swap(arrInts1, 0, 1);
	std::cout << "\nafter swap\n";
	PrintElements(arrInts1, sizeArrInts1);

	std::cout << "\n\nbefore swap\n";
	PrintElements(arrInts2, sizeArrInts2);

	Swap(arrInts2, 7, 10);
	std::cout << "\nafter swap\n";
	PrintElements(arrInts2, sizeArrInts2);
}
void TestShuffle()
{
	std::cout << "\n\n\n-- Test of shuffle Function --";
	std::cout << "\nbefore shuffle\n";
	PrintElements(arrInts1, sizeArrInts1);

	Shuffle(arrInts1, sizeArrInts1, 1);
	std::cout << "\nafter 1 shuffle\n";
	PrintElements(arrInts1, sizeArrInts1);


	std::cout << "\n\nbefore shuffle\n";
	PrintElements(arrInts2, sizeArrInts2);

	Shuffle(arrInts2, sizeArrInts2, 100);
	std::cout << "\nafter 100 shuffles\n";
	PrintElements(arrInts2, sizeArrInts2);

	const int sizeArrSortedInts{ 10 };
	int arrSortedInts[sizeArrSortedInts]{};
	for (int idx = 0; idx < sizeArrSortedInts; idx++)
	{
		arrSortedInts[idx] = idx;
	}
	std::cout << "\n\nbefore shuffle\n";
	PrintElements(arrSortedInts, sizeArrSortedInts);

	Shuffle(arrSortedInts, sizeArrSortedInts, 100);
	std::cout << "\nafter 100 shuffles\n";
	PrintElements(arrSortedInts, sizeArrSortedInts);
}
void TestBubbleSort()
{
	std::cout << "\n\n\n-- Test of bubbleSort Function --";
	std::cout << "\nbefore sort\n";
	PrintElements(arrInts1, sizeArrInts1);

	BubbleSort(arrInts1, sizeArrInts1);
	std::cout << "\nafter sort\n";
	PrintElements(arrInts1, sizeArrInts1);


	std::cout << "\n\nbefore sort\n";
	PrintElements(arrInts2, sizeArrInts2);

	BubbleSort(arrInts2, sizeArrInts2);
	std::cout << "\nafter ssort\n";
	PrintElements(arrInts2, sizeArrInts2);


	const int sizeArrSortedInts{ 10 };
	int arrSortedInts[sizeArrSortedInts]{};
	for (int idx = 0; idx < sizeArrSortedInts; idx++)
	{
		arrSortedInts[idx] = sizeArrSortedInts - 1 - idx;
	}
	std::cout << "\n\nbefore sort\n";
	PrintElements(arrSortedInts, sizeArrSortedInts);

	BubbleSort(arrSortedInts, sizeArrSortedInts);
	std::cout << "\nafter ssort\n";
	PrintElements(arrSortedInts, sizeArrSortedInts);


}


int Count(int* pInts, int size, int number) 
{
	int result{};
	for (int idx = 0; idx < size; idx++)
	{
		if (pInts[idx] == number) result++;
	}
	return result;
}
int MinElement(int* pInts, int size)
{
	int result{ pInts[0] };
	for (int idx = 0; idx < size; idx++)
	{
		if (pInts[idx] < result) result = pInts[idx];
	}
	return result;
}
int MaxElement(int* pInts, int size)
{
	int result{ pInts[0] };
	for (int idx = 0; idx < size; idx++)
	{
		if (pInts[idx] > result) result = pInts[idx];
	}
	return result;
}
void Swap(int* pInts, int idx1, int idx2) 
{
	int holdVarialbe{ pInts[idx1] };
	pInts[idx1] = pInts[idx2];
	pInts[idx2] = holdVarialbe;

}
void Shuffle(int* pInts, int size, int numSwaps)
{
	for (int i = 0; i < numSwaps; i++)
	{
		int random{ rand() };
		int randIdx1{ random % size };
		int randIdx2{};
		do{
		randIdx2 = rand() % size;
		} while (randIdx1 == randIdx2);

		Swap(pInts, randIdx1, randIdx2);
	}
}
void BubbleSort(int* pInts, int size)
{
	for (int idx = 0; idx < size-1; idx++)
	{
		if (pInts[idx] > pInts[idx + 1]) Swap(pInts, idx, idx + 1);
	}
	if (size > 1) BubbleSort(pInts, size - 1);
}


void PrintElements(int* pIntegers, int sizeOfArray)
{
	for (int idx = 0; idx < sizeOfArray; idx++)
	{
		std::cout << pIntegers[idx] << " ";
	}
}
