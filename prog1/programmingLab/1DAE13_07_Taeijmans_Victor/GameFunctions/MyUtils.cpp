#include "pch.h"
#include "MyUtils.h"

Color4f RgbToColor4f(float r, float g, float b, float a) {
	return Color4f(r / 255, g / 255, b / 255, a / 255);
}



float GetDistance(float point1X, float point1Y, float point2X, float point2Y)
{
	float result{ sqrtf( powf((point1X - point2X), 2) + powf((point1Y - point2Y), 2) ) };
	return result;
}

float GetDistance(const Point2f& point1, const Point2f& point2)
{
	float result{ GetDistance(point1.x, point1.y, point2.x, point2.y) };
	return result;
}

float GetDistance(Point2f& point1, float point2X, float point2Y)
{
	float result{ GetDistance(point1.x, point1.y, point2X, point2Y) };
	return result;
}



bool IsPointInCircle(const Point2f& circelCenter, const float radius, const Point2f& point)
{
	float distanceCircleCenterToPoint{ GetDistance(circelCenter, point) };
	if (distanceCircleCenterToPoint >= radius)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool IsPointInCircle(const Circlef& circle, const Point2f& point)
{
	return IsPointInCircle(circle.center, circle.radius, point);
}


bool IsPointInRect(const float rectX, const float rectY, const float width, const float height, const Point2f& point)
{
	if (point.x >= rectX && point.x <= rectX + width
	 && point.y >= rectY && point.y <= rectY + height)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool IsPointInRect(const Rectf& rect, const Point2f& point)
{
	return IsPointInRect(rect.left, rect.bottom, rect.width, rect.height, point);
}



bool IsOverlapping(const Rectf rect1, const Rectf rect2)
{ 
	Point2f l1{ rect1.bottom, rect1.left };
	Point2f r1{ rect1.bottom + rect1.height, rect1.left + rect1.width };
	Point2f l2{ rect2.bottom, rect2.left };
	Point2f r2{ rect2.bottom + rect2.height, rect2.left + rect2.width };


	// If one rectangle is on left side of other
	if (rect1.bottom > rect2.bottom + rect2.height || rect2.bottom > rect1.bottom + rect1.height)
		return false;

	// If one rectangle is above other
	if (rect1.left > rect2.left + rect2.width || rect2.left > rect1.left + rect1.width)
		return false;

	return true;

}
bool IsOverlapping(const Circlef& circle1, const Circlef& circle2)
{
	float distanceBetweenCenters{ GetDistance(circle1.center, circle2.center) };

	if (distanceBetweenCenters <= (circle1.radius + circle2.radius))
	{
		return true;
	}
	else
	{
		return false;
	}
}