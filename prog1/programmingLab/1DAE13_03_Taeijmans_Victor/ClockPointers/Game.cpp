#include "pch.h"
#include "Game.h"
#include <cmath>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBigPointer();
	DrawSmallPointer();

}

void Update(float elapsedSec)
{
	g_NrFrames++;
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
void DrawBigPointer() {
	const float pointerLength{ 300 };
	const float pointerWidth{ 0.2f };
	const float widestPoint{ pointerLength / 3 };

	const int rotationDuration{ 240 };


	const float timeStateClock{ float(g_NrFrames % rotationDuration) };
	const float angleBigPointerRad{ (timeStateClock / rotationDuration * (2 * float(M_PI))) };


	const Point2f midPoint{ g_WindowWidth / 2.f, g_WindowHeight / 2.f, };

	const float cosTipBigPointer{ cosf(angleBigPointerRad) };
	const float sinTipBigPointer{ sinf(angleBigPointerRad) };

	const float pointerTipX{ sinTipBigPointer * pointerLength + midPoint.x };
	const float pointerTipY{ cosTipBigPointer * pointerLength + midPoint.y };

	const Point2f tipBigPointer{ pointerTipX, pointerTipY };


	const float cosWidth1BigPointer{ cosf(angleBigPointerRad - pointerWidth) };
	const float sinWidth1BigPointer{ sinf(angleBigPointerRad - pointerWidth) };

	const float widthPoint1X{ sinWidth1BigPointer * widestPoint + midPoint.x };
	const float widthPoint1Y{ cosWidth1BigPointer * widestPoint + midPoint.y };

	const Point2f widthPoint1{ widthPoint1X, widthPoint1Y };


	const float cosWidth2BigPointer{ cosf(angleBigPointerRad + pointerWidth) };
	const float sinWidth2BigPointer{ sinf(angleBigPointerRad + pointerWidth) };

	const float widthPoint2X{ sinWidth2BigPointer * widestPoint + midPoint.x };
	const float widthPoint2Y{ cosWidth2BigPointer * widestPoint + midPoint.y };

	const Point2f widthPoint2{ widthPoint2X, widthPoint2Y };


	SetColor(1.f, 1.f, 1.f);
	DrawLine(midPoint, widthPoint1, 1.f);
	DrawLine(midPoint, widthPoint2, 1.f);
	DrawLine(widthPoint1, tipBigPointer, 1.f);
	DrawLine(widthPoint2, tipBigPointer, 1.f);

}


void DrawSmallPointer() {
	const float pointerLength{ 150 };
	const float pointerWidth{ 0.3f };
	const float widestPoint{ pointerLength / 3 };

	const int rotationDuration{ 240*12 };


	const float timeStateClock{ float(g_NrFrames % rotationDuration) };
	const float angleSmallPointerRad{ (timeStateClock / rotationDuration * (2 * float(M_PI))) };


	const Point2f midPoint{ g_WindowWidth / 2.f, g_WindowHeight / 2.f, };

	const float cosTipSmallPointer{ cosf(angleSmallPointerRad) };
	const float sinTipSmallPointer{ sinf(angleSmallPointerRad) };

	const float pointerTipX{ sinTipSmallPointer * pointerLength + midPoint.x };
	const float pointerTipY{ cosTipSmallPointer * pointerLength + midPoint.y };

	const Point2f tipSmallPointer{ pointerTipX, pointerTipY };


	const float cosWidth1SmallPointer{ cosf(angleSmallPointerRad - pointerWidth) };
	const float sinWidth1SmallPointer{ sinf(angleSmallPointerRad - pointerWidth) };

	const float widthPoint1X{ sinWidth1SmallPointer * widestPoint + midPoint.x };
	const float widthPoint1Y{ cosWidth1SmallPointer * widestPoint + midPoint.y };

	const Point2f widthPoint1{ widthPoint1X, widthPoint1Y };


	const float cosWidth2SmallPointer{ cosf(angleSmallPointerRad + pointerWidth) };
	const float sinWidth2SmallPointer{ sinf(angleSmallPointerRad + pointerWidth) };

	const float widthPoint2X{ sinWidth2SmallPointer * widestPoint + midPoint.x };
	const float widthPoint2Y{ cosWidth2SmallPointer * widestPoint + midPoint.y };

	const Point2f widthPoint2{ widthPoint2X, widthPoint2Y };


	SetColor(1.f, 1.f, 1.f);
	DrawLine(midPoint, widthPoint1, 1.f);
	DrawLine(midPoint, widthPoint2, 1.f);
	DrawLine(widthPoint1, tipSmallPointer, 1.f);
	DrawLine(widthPoint2, tipSmallPointer, 1.f);
}
#pragma endregion ownDefinitions