#include "pch.h"
#include "DaeEllipse.h"
#include <iostream>

DaeEllipse::DaeEllipse(const Point2f& center, float radX, float radY, const Color4f fillColor) :
	m_Center{ center },
	m_radX{ radX },
	m_radY{ radY },
	m_FillColor{ fillColor },
	m_Area{ float(M_PI) * radX * radY },
	m_IsActive{ false }
{
}

void DaeEllipse::Draw()
{
	Color4f color = m_IsActive ? m_FillColor : Color4f(m_FillColor.r, m_FillColor.g, m_FillColor.b, 0.5f);
	utils::SetColor(color);
	utils::FillEllipse(m_Center, m_radX, m_radY);
}
void DaeEllipse::ActivateTest(const Point2f& pos)
{
	if (utils::IsPointInEllipse(Ellipsef{ m_Center, m_radX, m_radY }, pos))
	{
		m_IsActive = true;
	}
	m_IsActive = false;
}