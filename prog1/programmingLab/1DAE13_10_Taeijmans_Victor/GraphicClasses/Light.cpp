#include "pch.h"
#include "Light.h"

Light::Light(const Rectf& rect, const Color4f& color) :
	m_Rect{ rect },
	m_Color{ color },
	m_IsOn{true}
{
}

void Light::Draw()
{
	if (m_IsOn)
	{
		utils::SetColor(m_Color);
	}
	else
	{
		utils::SetColor(0.5f, 0.5f, 0.5f);
	}
	utils::FillRect(m_Rect);

	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawRect(m_Rect);
}

bool Light::IsHit(const Point2f pos)
{
	if (utils::IsPointInRect(m_Rect, pos))
	{
		m_IsOn = !m_IsOn;
		return true;
	}
	return false;
}
bool Light::IsOn()
{
	return m_IsOn;
}