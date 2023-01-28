#include "pch.h"
#include "Tile.h"
#include "iostream"

Tile::Tile(const Rectf& boundingBox, const std::string& imagePath, const int numberOfAnimals) :
	m_BoundingBox{ boundingBox },
	m_NrOfAnimals{ numberOfAnimals },
	m_IsActive{ false },
	m_CurrentAnimal{ rand()%numberOfAnimals },
	m_IsChangeble {true}
{
	bool loaded{};

	loaded = utils::TextureFromFile(imagePath, m_TileTextue);
	if (loaded == false) std::cout << "failed to load ";
}

void Tile::Draw()
{
	const Rectf sourceRect{  (m_TileTextue.width / m_NrOfAnimals) * m_CurrentAnimal, m_TileTextue.width / m_NrOfAnimals, m_TileTextue.width / m_NrOfAnimals, m_TileTextue.height };

	utils::DrawTexture(m_TileTextue, m_BoundingBox, sourceRect);
	if (m_IsActive && m_IsChangeble)
	{
		utils::SetColor(0.4f, 0.4f, 0.4f, 0.4f);
		utils::FillRect(m_BoundingBox);

		utils::SetColor(1.f, 0.f, 0.f, 1.f);
		utils::DrawRect(m_BoundingBox.left								 , m_BoundingBox.bottom, m_BoundingBox.width / 4, m_BoundingBox.height / 4);
		utils::DrawRect(m_BoundingBox.left + m_BoundingBox.height * 3 / 4, m_BoundingBox.bottom, m_BoundingBox.width / 4, m_BoundingBox.height / 4);
	}
}

void Tile::CheckActivation(const Point2f& mousePos)
{
	if (utils::IsPointInRect(m_BoundingBox, mousePos))
	{
		m_IsActive = true;
	}
	else
	{
		m_IsActive = false;
	}
}
bool Tile::CheckHit(const Point2f& mousePos)
{
	if (m_IsChangeble)
	{
		const Rectf leftButton{  Rectf{m_BoundingBox.left							    , m_BoundingBox.bottom, m_BoundingBox.width / 4, m_BoundingBox.height / 4} };
		const Rectf RightButton{ Rectf{m_BoundingBox.left + m_BoundingBox.height * 3 / 4, m_BoundingBox.bottom, m_BoundingBox.width / 4, m_BoundingBox.height / 4} };
		if (utils::IsPointInRect(leftButton, mousePos))
		{
			m_CurrentAnimal = (m_CurrentAnimal == 0) ? m_NrOfAnimals-1 : m_CurrentAnimal - 1;
			return true;
		}
		if (utils::IsPointInRect(RightButton, mousePos))
		{
			m_CurrentAnimal = (m_CurrentAnimal == m_NrOfAnimals-1) ? 0 : m_CurrentAnimal + 1;
			return true;
		}
	}
	return false;
}

void Tile::Deactivate()
{
	m_IsChangeble = false;
}


int Tile::GetCurrentAnimal()
{
	return m_CurrentAnimal;
}

void Tile::Shuffle() {
	m_CurrentAnimal = rand() % m_NrOfAnimals;
	m_IsChangeble = true;
}