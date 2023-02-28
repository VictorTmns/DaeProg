#include "pch.h"
#include "Card.h"
#include "Texture.h"

const int Card::m_MinRank{ 1 };
const int Card::m_MaxRank{ 13 };

Card::Card(Suit suit, int rank) :
	m_Suit{ Suit(suit) },
	m_Rank{ rank },
	m_pTexture{ new Texture(GetImagePath(suit, rank)) }
{
}


Card::~Card()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Card::Draw(const Rectf& destRect) const
{
	m_pTexture->Draw(destRect);
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
