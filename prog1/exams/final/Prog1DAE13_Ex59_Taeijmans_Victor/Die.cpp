#include "pch.h"
#include "Die.h"
#include "iostream"

Die::Die(const Point2f& leftBottom, float scale) :
	m_Pos{ leftBottom },
	m_ColorIdx { rand() % 10 },
	m_DieIdx{ rand() % 6 },
	m_Scale{ scale },
	m_IsRolling{ false }
{
	bool loaded{};
	loaded = utils::TextureFromFile("Resources/Dice_Sprites.png", m_SpriteSheet);
	if (loaded == false) std::cout << "failed to load dice texture";
}

Die::Die(float left, float bottom, float scale) :
	m_Pos{ Point2f{left, bottom} },
	m_ColorIdx{ rand() % 10 },
	m_DieIdx{ rand() % 6 },
	m_Scale{ scale },
	m_IsRolling{ false }
{
	bool loaded{};
	loaded = utils::TextureFromFile("Resources/Dice_Sprites.png", m_SpriteSheet);
	if (loaded == false) std::cout << "failed to load dice texture";

}

Die::~Die()
{
	utils::DeleteTexture(m_SpriteSheet);
}

void Die::Draw()
{
	const float widthDie{ m_SpriteSheet.width / 9 };
	const float heightDie{ m_SpriteSheet.height/ 10 };

	const Rectf sourceRect{ widthDie * m_DieIdx, heightDie * (m_ColorIdx + 1), widthDie, heightDie };
	const Rectf destRect{ m_Pos.x, m_Pos.y, widthDie, heightDie };

	utils::DrawTexture(m_SpriteSheet, destRect, sourceRect);
}

bool Die::CheckHit(const Point2f& pos)
{
	return CheckHit(pos.x, pos.y);
}
bool Die::CheckHit(float posX, float posY)
{
	if (utils::IsPointInRect(Rectf{ m_Pos.x, m_Pos.y, m_SpriteSheet.width/9 *m_Scale, m_SpriteSheet.height/10* m_Scale}, Point2f{posX, posY}))
	{

		return true;
	}
	return false;
}

void Die::Randomize(bool IsRolling)
{
	if (IsRolling)
	{
		m_DieIdx = rand() % 3 + 6;
	}
	else
	{
		m_DieIdx = rand() % 6;
	}

}

void Die::SetScale(float scale)
{
	m_Scale = scale;
}

int Die::GetDots()
{
	if (m_DieIdx < 6)
	{
		return m_DieIdx + 1;
	}
	else
	{
		return 0;
	}
}