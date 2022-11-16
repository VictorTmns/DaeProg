#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	DrawSquares();
	DrawTriangles();
	DrawPentagrams();
	DrawLineairGradients();
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawSquares()
{
	SetColor(0.f, 0.f, 0.f);
	DrawConcentricSquare(5.f , g_WindowHeight - 85.f, 80.f, 11);
	DrawConcentricSquare(Point2f(90.f, g_WindowHeight - 85.f), 50.f, 5);
	DrawConcentricSquare(145.f, g_WindowHeight - 85.f, 40.f, 3);
}
void DrawConcentricSquare(const float bottom, float left, float size, int numberOfSquares)
{
	float padding{ size / numberOfSquares };
	for (int i = 0; i < numberOfSquares; i++)
	{
		DrawRect(bottom + i * padding/2, left + i * padding/2, size - i * padding, size - i * padding);
	}
}
void DrawConcentricSquare(Point2f leftBottomPos, float size, int numberOfSquares)
{
	DrawConcentricSquare(leftBottomPos.x, leftBottomPos.y, size, numberOfSquares);
}
void DrawTriangles()
{
	float pi = 3.1415f;
	Color4f red(1.f, 0.f, 0.f, 1.f);
	Color4f green(0.f, 1.f, 0.f, 1.f);
	Color4f blue(0.f, 0.f, 1.f, 1.f);
	Color4f yellow(1.f, 1.f, 0.f, 1.f);
	Color4f cyan(0.f, 1.f, 1.f, 1.f);
	Color4f purple(1.f, 0.f, 1.f, 1.f);
	Color4f black(0.f, 0.f, 0.f, 1.f);

	SetColor(red);
	DrawEquilateralTriangle(200.f, 320.f, 50.f, true);
	SetColor(green);
	DrawEquilateralTriangle(207.5f, 320.f + 7.5f * cosf(pi / 3), 35.f, true);
	SetColor(blue);
	DrawEquilateralTriangle(215.f, 320.f + 15.f * cosf(pi / 3), 20.f, true);

	SetColor(cyan);
	DrawEquilateralTriangle(270.f, 320.f, 25.f, true);
	SetColor(yellow);
	DrawEquilateralTriangle(295.f, 320.f, 25.f, true);
	SetColor(purple);
	DrawEquilateralTriangle(270.f + (cosf(pi / 3) * 25.f), 320.f + (sinf(pi / 3) * 25.f), 25.f, true);
	SetColor(black);
	DrawEquilateralTriangle(270.f, 320.f, 25.f);
	DrawEquilateralTriangle(295.f, 320.f, 25.f);
	DrawEquilateralTriangle(270.f + (cosf(pi / 3) * 25.f), 320.f + (sinf(pi / 3) * 25.f), 25.f);

}
void DrawEquilateralTriangle(const float left, float bottom, float verticesSize, bool isFilled)
{
	float pi = 3.1415f;

	switch (isFilled)
	{
	case true:
		FillTriangle(Point2f(left, bottom), Point2f(left + verticesSize * cosf(0), bottom + verticesSize * sinf(0)), Point2f(left + verticesSize * cosf(pi / 3), bottom + verticesSize * sinf(pi / 3)));
	case false:
		DrawTriangle(Point2f(left, bottom), Point2f(left + verticesSize * cosf(0), bottom + verticesSize * sinf(0)), Point2f(left + verticesSize * cosf(pi / 3), bottom + verticesSize * sinf(pi / 3)));
		break;
	};
}
void DrawEquilateralTriangle(Point2f leftBottomPos, float verticesSize, bool isFilled)
{
	DrawEquilateralTriangle(leftBottomPos.x, leftBottomPos.y,verticesSize, isFilled);
}
void DrawPentagrams()
{
	Color4f red(1.f, 0.f, 0.f, 1.f);
	Color4f blue(0.f, 0.f, 1.f, 1.f);

	Point2f center1(200.f, 260.f);
	SetColor(red);
	DrawPentagram(Point2f(260.f, 280.f), 30.f);
	SetColor(blue);
	DrawPentagram(Point2f(320.f, 280.f), 20.f);
}
void DrawPentagram(const Point2f centerPos, float radius)
{
	float pi = 3.1415f;
	Point2f point1(centerPos.x + radius * cosf(0 / pi*2), centerPos.y + radius * sinf(0 / pi*2));
	Point2f point2(centerPos.x + radius * cosf(2 / pi*2), centerPos.y + radius * sinf(2 / pi*2));
	Point2f point3(centerPos.x + radius * cosf(4 / pi*2), centerPos.y + radius * sinf(4 / pi*2));
	Point2f point4(centerPos.x + radius * cosf(6 / pi*2), centerPos.y + radius * sinf(6 / pi*2));
	Point2f point5(centerPos.x + radius * cosf(8 / pi*2), centerPos.y + radius * sinf(8 / pi*2));

	DrawLine(point1, point3);
	DrawLine(point3, point5);
	DrawLine(point5, point2);
	DrawLine(point2, point4);
	DrawLine(point4, point1);
}
void DrawLineairGradients()
{
	DrawLineairGradient(Point2f(10.f, 270.f), 80.F, 20.f, Color4f(1.f, 1.f, 1.f, 1.f), Color4f(0.f, 0.f, 0.f, 1.f));
	DrawLineairGradient(Point2f(10.f, 240.f), 180.F, 25.f, Color4f(1.f, 0.f, 0.f, 1.f), Color4f(0.f, 0.f, 1.f, 1.f));
	DrawLineairGradient(Point2f(10.f, 200.f), 280.F, 35.f, Color4f(RgbToColor4f(121, 120, 35)), Color4f(RgbToColor4f(236, 128, 122)));
	DrawLineairGradient(Point2f(10.f, 155.f), 380.F, 35.f, Color4f(RgbToColor4f(0, 0, 255)), Color4f(RgbToColor4f(255, 0, 0, 0)));
}
void DrawLineairGradient(const Point2f leftBottomPos, float width, float height, Color4f startColor, Color4f finalColor)
{
	Color4f colorIncrement((finalColor.r - startColor.r) / width, (finalColor.g - startColor.g) / width, 
						   (finalColor.b - startColor.b) / width, (finalColor.a - startColor.a) / width);
	for (int i = 0; i < width; i++)
	{
		Color4f color(startColor.r + i * colorIncrement.r, startColor.g + i * colorIncrement.g,
					  startColor.b + i * colorIncrement.b, startColor.a + i * colorIncrement.a);

		SetColor(color);
		FillRect(leftBottomPos.x + i, leftBottomPos.y, 1.f, height);
	}
}
Color4f RgbToColor4f(float r, float g, float b, float a) {
	return Color4f(r / 255, g / 255, b / 255, a / 255);
}
#pragma endregion ownDefinitions