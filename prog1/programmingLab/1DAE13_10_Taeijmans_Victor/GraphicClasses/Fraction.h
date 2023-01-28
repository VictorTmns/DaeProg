#pragma once
#include "pch.h"
#include "utils.h"

class Fraction 
{
private:
	int m_Numerator;
	int m_Denomirator;

public:
	Fraction(int numerator, int denomirator);
	
	void Draw(const Point2f& pos, float size);
	float GetValue();

};