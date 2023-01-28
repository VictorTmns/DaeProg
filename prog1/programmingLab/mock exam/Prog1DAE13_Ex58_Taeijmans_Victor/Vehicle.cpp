#include "pch.h"
#include "Vehicle.h"
#include "iostream"

Vehicle::Vehicle(int id) :
	m_MaxSpeed{ 200 },
	m_MinSpeed{ 20 },
	m_Speed{ float(rand() % (m_MaxSpeed + 1) + m_MinSpeed) },
	m_Position{ Point2f{0.f, 43.f + 45.f * id} },
	m_IsActive{ false }
{
	bool loaded{};

	loaded = utils::TextureFromFile("Resources/car-truck" + std::to_string(id+1) + ".bmp", m_Texture);
	if (loaded == false) std::cout << "failed to load car texture";
}

void Vehicle::Reset()
{
	m_Position.x = -float(rand() % 300);
	m_Speed = float(rand() % (m_MaxSpeed + 1) + m_MinSpeed);
	m_IsActive = true;
}

Vehicle::~Vehicle()
{
	utils::DeleteTexture(m_Texture);
}

void Vehicle::Update(float elapsedSec, float windowWidth)
{
	if (m_IsActive)
	{
		m_Position.x += m_Speed * elapsedSec;
		if (m_Position.x > windowWidth)
		{
			Reset();
		}
	}
}

void Vehicle::Draw()
{
	utils::DrawTexture(m_Texture, m_Position);
}

bool Vehicle::IsIntersecting(const Point2f& pt)
{
	if (utils::IsPointInRect(Rectf{ m_Position.x, m_Position.y, m_Texture.width, m_Texture.height }, pt))
	{
		m_IsActive = false;
		return true;
	}
	return false;
}

void Vehicle::SetActive(bool isActive)
{

}

void Vehicle::SetYPos(float posY)
{
	m_Position.y = posY;
}
