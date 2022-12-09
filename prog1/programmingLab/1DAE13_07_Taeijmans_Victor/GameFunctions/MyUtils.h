#pragma once
Color4f RgbToColor4f(float r, float g, float b, float a = 255);


float GetDistance(float point1X, float point1Y, float point2X, float point2Y);
float GetDistance(const Point2f& point1, const Point2f& point2);
float GetDistance(Point2f& point1, float point2X, float point2Y);

bool IsPointInCircle(const Circlef& circle, const Point2f& point);
bool IsPointInCircle(const Point2f& circelCenter, const float radius, const Point2f& point);

bool IsPointInRect(const Rectf& rect, const Point2f& point);
bool IsPointInRect(const float rectX, const float rectY, const float width, const float height, const Point2f& point);

bool IsOverlapping(const Rectf rect1, const Rectf rect2);
bool IsOverlapping(const Circlef& circle1, const Circlef& circle2);