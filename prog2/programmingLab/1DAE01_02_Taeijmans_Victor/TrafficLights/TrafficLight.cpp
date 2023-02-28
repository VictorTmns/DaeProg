#include "pch.h"
#include "TrafficLight.h"
#include "utils.h"



TrafficLight::TrafficLight(const Rectf& boundingBox) :
	m_BoundingBox{ boundingBox },
	m_GreenLight{ Circlef{Point2f{boundingBox.left + boundingBox.width / 2, boundingBox.bottom + boundingBox.height * 1 / 6},boundingBox.width/2 * 2 / 5} },
	m_OrangeLight{ Circlef{Point2f{boundingBox.left + boundingBox.width / 2, boundingBox.bottom + boundingBox.height * 3 / 6}, boundingBox.width/2 * 2 / 5} },
	m_RedLight{ Circlef{Point2f{boundingBox.left + boundingBox.width / 2, boundingBox.bottom + boundingBox.height * 5 / 6}, boundingBox.width/2 * 2 / 5} },
	m_AccumulatedSec{},
	m_State{State::green}
{
}

void TrafficLight::DoHitTest(const Point2f& pos)
{
	if (utils::IsPointInRect(pos, m_BoundingBox))
	{
		if (m_State == State::off)
		{
			if (utils::IsPointInCircle(pos, m_GreenLight))
			{
				m_State = State::green;
			}
			else if (utils::IsPointInCircle(pos, m_OrangeLight))
			{
				m_State = State::orange;
			}
			else if (utils::IsPointInCircle(pos, m_RedLight))
			{
				m_State = State::red;
			}
		}
		else
		{
			if (!(utils::IsPointInCircle(pos, m_GreenLight) || utils::IsPointInCircle(pos, m_OrangeLight) || utils::IsPointInCircle(pos, m_RedLight)))
			{
				m_AccumulatedSec = 0.f;
				m_State = State::off;
			}
		}
	}
}
void TrafficLight::Update(float elapsedSec)
{
	if (!(m_State == State::off))
	{
		m_AccumulatedSec += elapsedSec;
	}

	switch (m_State)
	{
	case TrafficLight::State::off:
		break;

	case TrafficLight::State::green:
		if (m_AccumulatedSec >= 4.f)
		{
			m_AccumulatedSec = 0.f;
			m_State = State::orange;
		}
		break;

	case TrafficLight::State::orange:
		if (m_AccumulatedSec >= 1.f)
		{
			m_AccumulatedSec = 0.f;
			m_State = State::red;
		}
		break;

	case TrafficLight::State::red:
		if (m_AccumulatedSec >= 4.f)
		{
			m_AccumulatedSec = 0.f;
			m_State = State::green;
		}
		break;
	}
}
void TrafficLight::Draw()
{
	utils::SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	utils::FillRect(m_BoundingBox);

	utils::SetColor(Color4f{ 0.5f, 0.5f, 0.5f, 1.f });
	utils::FillEllipse(m_GreenLight.center, m_GreenLight.radius, m_GreenLight.radius);
	utils::FillEllipse(m_OrangeLight.center, m_OrangeLight.radius, m_OrangeLight.radius);
	utils::FillEllipse(m_RedLight.center, m_RedLight.radius, m_RedLight.radius);

	switch (m_State)
	{
	case TrafficLight::State::off:
		break;
	case TrafficLight::State::green:
		utils::SetColor(Color4f{ 0.f, 1.f, 0.f, 1.f });
		utils::FillEllipse(m_GreenLight.center, m_GreenLight.radius, m_GreenLight.radius);
		break;
	case TrafficLight::State::orange:
		utils::SetColor(Color4f{ 1.f, 0.5f, 0.f, 1.f });
		utils::FillEllipse(m_OrangeLight.center, m_OrangeLight.radius, m_OrangeLight.radius);
		break;
	case TrafficLight::State::red:
		utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
		utils::FillEllipse(m_RedLight.center, m_RedLight.radius, m_RedLight.radius);
		break;
	}

}
float TrafficLight::GetWidth()
{
	return m_BoundingBox.width;
}
float TrafficLight::GetHeight()
{
	return m_BoundingBox.height;
}