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
	ClearBackground(0.f, 0.f, 0.f);

	DrawSierpinskiTriangle(Point2f(0.f, 0.f), g_WindowWidth);
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
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
void DrawSierpinskiTriangle(const Point2f& left, float size)
{

	if (size > 20.f) {

		Point2f top{ left.x + size / 2.f, left.y + sqrtf(3.f) / 2.f * size };
		Point2f right{ left.x + size	, left.y };

		Point2f middleBottom{ left.x + size / 2.f		, left.y };
		Point2f middleLeft{ left.x + size / 4.f			, left.y + sqrtf(3) / 2.f * (size / 2.f) };
		Point2f middleRight{ left.x + size * (3.f / 4.f), left.y + sqrtf(3.f) / 2.f * (size / 2.f) };

		Color4f green{ 0.f, 1.f, 0.f, 1.f };
		Color4f blue{ 0.f, 0.f, 1.f, 1.f };
		Color4f red{ 1.f, 0.f, 0.f, 1.f };
	
		SetColor(red);
		DrawTriangle(left, middleBottom, middleLeft);
		SetColor(green);
		DrawTriangle(top, middleRight, middleLeft);
		SetColor(blue);
		DrawTriangle(right, middleBottom, middleRight);

		DrawSierpinskiTriangle(left, size / 2.f);
		DrawSierpinskiTriangle(middleLeft, size / 2.f);
		DrawSierpinskiTriangle(middleBottom, size / 2);
	}

}

#pragma endregion ownDefinitions