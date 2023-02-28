#pragma once

class TrafficLight
{
public:
	enum class State
	{
		off,
		green,
		orange,
		red
	};

	TrafficLight(const Rectf& boundingBox);

	void DoHitTest(const Point2f& pos);
	void Update(float elapsedSec);
	void Draw();
	float GetWidth();
	float GetHeight();

private:
	State m_State;
	const Rectf m_BoundingBox;
	float m_AccumulatedSec;
	const Circlef m_GreenLight;
	const Circlef m_OrangeLight;
	const Circlef m_RedLight;
};
