#include "pch.h"
#include "Square.h"
#include <iostream>

Square::Square(float size) :
	Square(size, 0.f, 0.f)
{
}

Square::Square(float size, float left, float bottom) :
	m_Size{ size },
	m_Bottom{ bottom },
	m_Left{ left }
{
}

Square::~Square()
{
	std::cout << "the resources have been deleted\n";
}

void Square::Print()
{
	std::cout << "left: " << m_Left << " bottom: " << m_Bottom << "\n";
	std::cout << "size: " << m_Size << "\n";
	std::cout << "perimeter: " << GetPerimeter() << "\n";
	std::cout << "area: " << GetArea() << "\n";
}
void Square::Translate(float deltaLeft, float deltaBottom)
{
	m_Left += deltaLeft;
	m_Bottom += deltaBottom;
}
void Square::Setsize(float newSize)
{
	m_Size = newSize;
}

float Square::GetArea()
{
	return m_Size * m_Size;
}
float Square::GetPerimeter()
{
	return m_Size * 4;
}