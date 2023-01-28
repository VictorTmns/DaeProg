#include "pch.h"
#include "utils.h"

class Die
{
private:
	utils::Texture m_SpriteSheet;
	const int m_ColorIdx;
	int m_DieIdx;
	float m_Scale;
	Point2f m_Pos;
	bool m_IsRolling;
public:
	Die(const Point2f& leftBottom, float scale);
	Die(float left, float bottom, float scale);
	~Die();

	void Draw();

	bool CheckHit(const Point2f& pos);
	bool CheckHit(float posX, float posY);

	void Randomize(bool IsRolling);

	void SetScale(float scale);

	//getter
	int GetDots();
};