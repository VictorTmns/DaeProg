// Taeijmans Victor 1DAE13E
//
#include "pch.h"
#include "time.h"
#include <iostream>
#include <chrono>

struct Point2f {
	float x;
	float y;
};

void TestSum(const int number1, const int number2);
int Sum(const int number1, const int number2);
void Print(unsigned int value, char delimiter = ' ');
void Print(char value, char delimiter = ' ');
void Print(float value, char delimiter = ' ');
void TestPrint();
void TestMultiply();
int Multiply(const int number1, const int number2);
void TestModulo();
int Modulo(const int dividend, const int divisor);
void TestPrintNumbers();
void PrintNumbers(const int startNumber, const int endNumber);
void TestCalcElapsedTime();
void CalcElapsedTime(const int startNumber, const int endNumber);
void TestPrintMessage();
void PrintMessage();
void PrintMessage(const int indentationSpaces);
void TestIsEven();
void PrintIsEven(const int number);
bool IsEven(const int number);
void TestIsLeapYear();
void PrintIsLeapYear( const int year);
bool IsLeapYear( const int year);
void TestGetRand();
float GetRand(const float bottomNumber, const float topNumber);
float GetRand(const float bottomNumber, const int topNumber);
float GetRand(const int bottomNumber, const float topNumber);
int GetRand(const int bottomNumber, const int topNumber);
void TestGetDistance();
float GetDistance(Point2f point1, Point2f point2);
float GetDistance(float point1X, float point1Y, float point2X, float point2Y);

int main()
{
	srand(int(time(NULL)));
	//TestSum(29, 8);
	//std::cout << Sum(10, 7);
	TestPrint();
	//TestMultiply();
	//TestModulo();
	//TestPrintNumbers();
	//TestCalcElapsedTime();
	//TestPrintMessage();
	//TestIsEven();
	//TestIsLeapYear();
	//TestGetRand();
	//TestGetDistance();
}

void TestSum(const int number1, const int number2) {
	const int result = number1 + number2;
	std::cout << number1 << " + " << number2 << " = " << result << std::endl;
}
int Sum(const int number1, const int number2) {
	const int result = number1 + number2;
	return result;
}
void Print(int value, char delimiter)
{
	std::cout << value << delimiter;
}
void Print(char value, char delimiter)
{
	std::cout << value << delimiter;
}
void Print(float value, char delimiter)
{
	std::cout << value << delimiter;
}
void TestPrint()
{
	Print('a');
	Print(20, ',');
	Print(20.0f, ',');
}
void TestMultiply()
{
	int a{};
	int b{};
	int c{};
	int d{};
	std::cout << "-- Multiply --\n";

	std::cout << "enter two integers: ";
	std::cin >> a >> b;
	std::cout << a << " + " << b << " = " << Multiply(a, b);

	std::cout << "\n\nnow we multiply 4 numbers\n";
	std::cout << "enter four integers: ";
	std::cin >> a >> b >> c >> d;

	std::cout << a << " * " << b << " * " << c << " * " << d << " = " << Multiply(Multiply(a, b),Multiply(c, d));

}
int Multiply(const int number1, const int number2)
{
	int result{ number1 * number2 };
	return result;
}
void TestModulo()
{
	int a{};
	int b{};
	std::cout << "\n\n-- Modulo --\n";

	std::cout << "enter two integers: ";
	std::cin >> a >> b;
	std::cout << a << " % " << b << " = " << Modulo(a, b);


}
int Modulo(const int number1, const int number2)
{
	int result{ number1 - (number1 / number2 * number2) };
	return result;
}
void TestPrintNumbers() {
	std::cout << "\n\n-- Modulo --\n";

	std::cout << "Interval [10, 20]\n";
	PrintNumbers(10, 20);
	std::cout << "\nInterval [40, 90]\n";
	PrintNumbers(40, 90);
	
}
void PrintNumbers(const int startNumber, const int endNumber) {
	for (int i = 0; i < endNumber - startNumber + 1; i++)
	{
		std::cout << i + startNumber << " ";
	}
}
void TestCalcElapsedTime()
{
	std::cout << "\n\n-- Calculator of printTask --\n";
	std::cout << "Interval [40, 90]\n";
	CalcElapsedTime(40, 90);

}
void CalcElapsedTime(const int startNumber, const int endNumber)
{
	std::chrono::steady_clock::time_point startTime{ std::chrono::steady_clock::now() };
	PrintNumbers(startNumber, endNumber);
	std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };

	std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };

	std::cout << "\nduration print task: " << elapsedTime.count() << "ms";

}
void TestPrintMessage()
{
	std::cout << "\n\n-- test function with random indentation --\n";
	PrintMessage();
	PrintMessage(2);
	PrintMessage(4);
}
void PrintMessage(const int indentationSpaces) 
{
	std::string message{ " spaces indentation specified" };

	std::cout << "\n";
	for (int i = 0; i < indentationSpaces; i++)
	{
		std::cout << " ";
	}
	std::cout << indentationSpaces << message;

}
void PrintMessage() 
{
	PrintMessage(0);
}
void TestIsEven()
{
	std::cout << "\n\n-- test if a number is even and print it --\n";
	PrintIsEven(4);
	PrintIsEven(9);
	PrintIsEven(21);
}
void PrintIsEven(const int number)
{

	switch (IsEven(number))
	{
	case 0:
		std::cout << number << " is even";
		break;
	case 1:
		std::cout << number << " is not even";
		break;
	}
		std::cout << "\n";
}
bool IsEven(const int number)
{
	bool result{ bool(number % 2) };
	return result;
}
void TestIsLeapYear()
{
	std::cout << "\n\n-- test if a year is a leap year and print it --\n";

	PrintIsLeapYear(45);
	PrintIsLeapYear(2000);
	PrintIsLeapYear(2020);
	PrintIsLeapYear(1900);
}
void PrintIsLeapYear(const int year)
{
	std::cout << "\n" << year;
	switch(IsLeapYear(year))
	{
	case true:
		std::cout << " is a leapyear";
		break;
	case false:
		std::cout << " is not a leapyear";
		break;
	}

}
bool IsLeapYear(const int year)
{
	bool result{};
	if (year % 400 == 0) 
	{
		result = true;
	}
	else if (year % 100 == 0) 
	{
		result = false;
	}
	else if (year % 4 == 0) 
	{
		result = true;
	}
	else 
	{
		result = false;
	}
	return result;
}
void TestGetRand()
{
	std::cout << "\n\n-- test an overloaded 'get random number' function --\n";

	std::cout << "float generated random number\n";
	std::cout << GetRand(4.f, 9.8f) << "\n";
	std::cout << GetRand(9.f, 793.9f) << "\n";
	std::cout << GetRand(1.f, 2.f) << "\n";
	std::cout << GetRand(-10.f, 0.f) << "\n";


	std::cout << "integer generated random number\n";
	std::cout << GetRand(10, 18) << "\n";
	std::cout << GetRand(3, 30) << "\n";
	std::cout << GetRand(-80, -5) << "\n";


	std::cout << "and now integer and float\n";
	std::cout << GetRand(14, 7.f) << "\n";
	std::cout << GetRand(3.f, 18) << "\n";
	std::cout << GetRand(-3.f, 72) << "\n";


}
float GetRand(const float bottomNumber, const float topNumber)
{
	int range{ (int(topNumber * 100) - int(bottomNumber * 100)) };
	float result{ (float(rand() % range) / 100) + bottomNumber};
	return result;
}
float GetRand(const float bottomNumber, const int topNumber)
{
	float result{ GetRand(bottomNumber, float(topNumber)) };
	return result;
}
float GetRand(const int bottomNumber, const float topNumber)
{
	float result{ GetRand(float(bottomNumber), topNumber) };
	return result;
}
int GetRand(const int bottomNumber, const int topNumber)
{
	int range{ topNumber - (bottomNumber) };
	float result{ float(rand() % range) + bottomNumber};
	return result;
}
void TestGetDistance()
{
	Point2f point1{ 4, 8 };
	Point2f point2{ 8, 20 };

	std::cout << GetDistance(point1, point2) << "\n";
	std::cout << GetDistance(4, 8, 8, 20) << "\n";
}
float GetDistance(Point2f point1, Point2f point2)
{
	float result{ GetDistance(point1.x, point1.y, point2.x, point2.y) };
	return result;
}
float GetDistance(float point1X, float point1Y, float point2X, float point2Y)
{
	float result{ sqrtf(powf((point1X - point2X), 2) + powf((point1Y - point2Y), 2)) };
	return result;
}