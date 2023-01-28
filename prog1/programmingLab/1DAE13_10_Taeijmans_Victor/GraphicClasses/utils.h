#pragma once
#include "structs.h"
#include <vector>

namespace utils
{

	const float g_Pi{ 3.1415926535f };

#pragma region OpenGLDrawFunctionality
	void ClearBackground(float r, float g, float b);
	void ClearBackground();
	// Choose a floating point value for each color component between 0.0f and 1.0f. The a (alpha) is optional.
	// Usage: SetColor(1.0f, 0.0f, 0.0f); set the drawing color to red
	void SetColor(float r, float g, float b, float a = 1);
	// Pass a Color4f object to the function
	void SetColor(const Color4f& color);

	// Draws a line by connecting the two points specified by (x1,y1) and (x2,y2)
	void DrawLine(float x1, float y1, float x2, float y2, float lineWidth = 1.0f);
	// Draws a line by connecting the two points specified by p1 and p1
	void DrawLine(const Point2f& p1, const Point2f& p2, float lineWidth = 1.0f);

	void DrawTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3, float lineWidth = 1);
	void FillTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3);
	void DrawRect(float left, float bottom, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Point2f& bottomLeft, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Rectf& rect, float lineWidth = 1.0f);
	void FillRect(float left, float bottom, float width, float height);
	void FillRect(const Point2f& bottomLeft, float width, float height);
	void FillRect(const Rectf& rect);

	void DrawEllipse(float centerX, float centerY, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Point2f& center, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Ellipsef& ellipse, float lineWidth = 1.0f);
	void FillEllipse(float centerX, float centerY, float radX, float radY);
	void FillEllipse(const Ellipsef& ellipse);
	void FillEllipse(const Point2f& center, float radX, float radY);


	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle);

	void DrawPolygon(const std::vector<Point2f>& vertices, bool closed = true, float lineWidth = 1.0f);
	void DrawPolygon(const Point2f* pVertices, size_t nrVertices, bool closed = true, float lineWidth = 1.0f);
	void FillPolygon(const std::vector<Point2f>& vertices);
	void FillPolygon(const Point2f* pVertices, size_t nrVertices);

#pragma endregion OpenGLDrawFunctionality

#pragma region TextureFunctionality

	struct Texture
	{
		GLuint id;
		float width;
		float height;
	};
	bool TextureFromFile(const std::string& path, Texture& texture);
	bool TextureFromString(const std::string& text, TTF_Font* pFont, const Color4f& textColor, Texture& texture);
	bool TextureFromString(const std::string& text, const std::string& fontPath, int ptSize, const Color4f& textColor, Texture& texture);
	void TextureFromSurface(const SDL_Surface* pSurface, Texture& textureData);
	void DrawTexture(const Texture& texture, const Point2f& dstBottomLeft, const Rectf& srcRect = {});
	void DrawTexture(const Texture& texture, const Rectf& dstRect, const Rectf& srcRect = {});
	void DeleteTexture(Texture& texture);
#pragma endregion TextureFunctionality

#pragma region CollisionFunctionality

#pragma endregion CollisionFunctionality

#pragma region MyUtils
	void DrawCircle(const Circlef& circle, float lineWidth = 1.0f);
	void DrawCircle(const float centerX, const float centerY, const float radius, float lineWidth = 1.0f);
	void DrawCircle(const Point2f& center, const float radius, float lineWidth = 1.0f);

	void FillCircle(const Circlef& circle);
	void FillCircle(const float centerX, const float centerY, const float radius);
	void FillCircle(const Point2f& center, const float radius);

	Color4f RgbToColor4f(float r, float g, float b, float a = 255);


	float GetDistance(float point1X, float point1Y, float point2X, float point2Y);
	float GetDistance(const Point2f& point1, const Point2f& point2);
	float GetDistance(Point2f& point1, float point2X, float point2Y);
	float GetRadians(const float degrees);
	float GetDegrees(const float radians);

	bool IsPointInCircle(const Circlef& circle, const Point2f& point);
	bool IsPointInCircle(const Point2f& circelCenter, const float radius, const Point2f& point);

	bool IsPointInRect(const Rectf& rect, const Point2f& point);
	bool IsPointInRect(const float rectX, const float rectY, const float width, const float height, const Point2f& point);

	bool IsPointInEllipse(float ellipseX, float ellipseY, float radX, float radY, float pointX, float pointY);
	bool IsPointInEllipse(const Ellipsef& ellipse, const Point2f& point);
	bool IsPointInEllipse(float ellipseX, float ellipseY, float radX, float radY, const Point2f& point);


	bool IsOverlapping(const Rectf rect1, const Rectf rect2);
	bool IsOverlapping(const Circlef& circle1, const Circlef& circle2);


	void DrawVector(const Point2f& startPoint, const Vector2f& vector);
	std::string ToString(const Vector2f vector);


	Vector2f AddVectors(const Vector2f& vector1, const Vector2f& vector2);
	Vector2f SubstractVectors(const Vector2f& vector1, const Vector2f& vector2);
	float DotProductVectors(const Vector2f& vector1, const Vector2f& vector2);
	float CrossProductVectors(const Vector2f& vector1, const Vector2f& vector2);
	float CalcLengthVector(const Vector2f& vector);
	Vector2f ScaleLengthVector(const Vector2f& vector, const float scalar);
	Vector2f NormalizeVector(const Vector2f& vector);
	float AngleBetweenVectors(const Vector2f& vector1, const Vector2f& vector2);
	bool AreEqual(const Vector2f& vector1, const Vector2f& vector2);

#pragma endregion MyUtils

}