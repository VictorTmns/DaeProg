#include "pch.h"
#include "PowerUp.h"
#include <Texture.h>


PowerUp::PowerUp(const Point2f& center, PowerUp::Type type):
	m_Type{type},
	m_pTexture{ new Texture{"PowerUp/PowerUp.png"}},
	m_RotSpeed{ 360.f },
	m_TextClip{ Rectf{0.f,(m_pTexture->GetHeight()/2) * int(type), m_pTexture->GetWidth(), m_pTexture->GetHeight()/2}},
	m_Shape{ Circlef{center, 30.f} },
	m_Angle{0.f}
{

}

PowerUp::~PowerUp()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void PowerUp::Update(float elapsedSec)
{
	m_Angle += elapsedSec * m_RotSpeed;
}

void PowerUp::Draw() const
{
	glPushMatrix();

	glTranslatef(m_Shape.center.x, m_Shape.center.y, 0);
	glRotatef(m_Angle, 0, 0, 1);
	m_pTexture->Draw(Rectf{ -m_Shape.radius, -m_Shape.radius, m_Shape.radius*2, m_Shape.radius*2}, m_TextClip);

	glPopMatrix();
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	return utils::IsOverlapping(rect, m_Shape);
}