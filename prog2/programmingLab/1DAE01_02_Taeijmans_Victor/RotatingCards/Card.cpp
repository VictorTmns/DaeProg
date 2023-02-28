#include "pch.h"
#include "Card.h"
#include "Texture.h"

const int Card::m_MinRank{ 1 };
const int Card::m_MaxRank{ 13 };

Card::Card(int suit, int rank, float angle, const Circlef& circle) :
	m_Suit{ Suit(suit) },
	m_Rank{ rank },
	m_pTexture{ new Texture(GetImagePath(Suit(suit), rank)) },
	m_Angle{ angle }, 
	m_Circle{ circle },
	m_RotationalSpeed{ 10.f }
{
}


Card::~Card()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Card::Draw() const
{
	glPushMatrix();

	glRotatef(m_Angle, 0, 0, 1);
	m_pTexture->Draw(Rectf{ m_Circle.radius, -GetHeight() / 4, GetWidth()/2, GetHeight()/2});

	glPopMatrix();
}

void Card::Update(float elapsedSec)
{
	m_Angle += m_RotationalSpeed * elapsedSec;
}



std::string Card::GetImagePath(Suit suit, int rank) const
{
	return ("VectorContainerBasics/Cards/" + std::to_string(int(suit)*100+rank) + ".png");
}


float Card::GetWidth() const
{
	return m_pTexture->GetWidth();
}
float Card::GetHeight() const
{
	return m_pTexture->GetHeight();
}
