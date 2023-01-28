#include "pch.h"
#include "Fraction.h"

Fraction::Fraction(int numerator, int denomirator) :
	m_Numerator{ numerator },
	m_Denomirator{ denomirator }
{
}

void Fraction::Draw(const Point2f& pos, float size)
{
	for (int i = 0; i < m_Denomirator; i++)
	{
		if (i < m_Numerator)
		{
			utils::SetColor(0.f, 0.f, 1.f);
			utils::FillRect(pos.x + size * i, pos.y, size, size);
		}
		utils::SetColor(1.f, 1.f, 1.f);
		utils::DrawRect(pos.x + size * i, pos.y, size, size);
	}
}
float Fraction::GetValue()
{
	return float(m_Numerator) / m_Denomirator;
}