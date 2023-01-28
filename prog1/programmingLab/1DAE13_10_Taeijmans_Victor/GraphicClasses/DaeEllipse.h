#pragma once
#include "pch.h"
#include "utils.h"

class DaeEllipse
{
private:
	Point2f m_Center;
	float m_radX;
	float m_radY;
	Color4f m_FillColor;
	float m_Area;
	bool m_IsActive;
public:

	DaeEllipse(const Point2f& center, float radX, float radY, const Color4f fillColor);

	void Draw();
	void ActivateTest(const Point2f& pos);

};