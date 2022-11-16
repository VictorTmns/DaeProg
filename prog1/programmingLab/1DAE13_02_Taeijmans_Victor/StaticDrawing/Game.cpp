#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	AskGamerPercentages();

}

void Draw()
{
	ClearBackground(0.18f, 0.09f, 0.2f);
	DrawBelgianFlag();
	DrawCheckBoard();
	DrawColorSpectrum();
	DrawPentagram();
	DrawHouse();
	DrawColumnChart();

	// Put your own draw statements here

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

void DrawBelgianFlag() {
	float x{ 20.f };
	float y{ 200.f };
	const float height{ 100.f };
	const float width{ 50.f };

	Color4f black{ 0.f, 0.f, 0.f, 1.f };
	Color4f white{ 1.f, 1.f, 1.f, 1.f };
	Color4f yellow{ 1.f, 1.f, 0.f, 1.f };
	Color4f red{ 1.f, 0.f, 0.f, 1.f };

	SetColor(white);
	DrawRect(x, y, width*3, height, 2);

	SetColor(black);
	FillRect(x, y, width, height);

	x += 50;
	SetColor(yellow);
	FillRect(x, y, width, height);

	x += 50;
	SetColor(red);
	FillRect(x, y, width, height);
}

void DrawCheckBoard() {
	const float x{ 20.f };
	const float y{ 20.f };
	const float side{ 30.f };

	Color4f black{ 0.f, 0.f, 0.f, 1.f };
	Color4f white{ 1.f, 1.f, 1.f, 1.f };

	SetColor(black);
	FillRect(x, y, side*3, side*3);


	SetColor(white);
	DrawRect(x, y, side * 3, side * 3, 1);

	FillRect(x + side, y, side, side);
	FillRect(x, y + side, side, side);
	FillRect(x + side * 2, y + side, side, side);
	FillRect(x + side, y + side * 2, side, side);


}

void DrawColorSpectrum() {
	float startX = 360.f;
	float startY = 380.f;
	float x = startX;
	float y = startY;
	const float width = 30.f;
	const float height = 100.f;
	Color4f grey{0.3f, 0.3f, 0.3f, 1.f};
	Color4f red{1, 0.f, 0.f, 1};
	Color4f green{0.f, 1.f, 0.f, 1.f };
	Color4f blue{0.f, 0.f, 1.f, 1.f };
	Color4f magenta{1.f, 0.f, 1.f, 1.f };
	Color4f yellow{1.f, 1.f, 0.f, 1.f };
	Color4f lightBlue{0.67f, 0.85f, 0.9f, 1.f };
	Color4f white{1.f, 1.f, 1.f, 1};
	Color4f black{0.f, 0.f, 0.f, 1};

	const float borderWidth = 4.f;
	SetColor(yellow);
	FillRect(x - borderWidth, y - borderWidth, width * 9 + borderWidth * 2, height + borderWidth * 2);

	SetColor(grey);
	FillRect(x, y, width, height);

	x += width;
	SetColor(red);
	FillRect(x, y, width, height);


	x += width;
	SetColor(green);
	FillRect(x, y, width, height);


	x += width;
	SetColor(blue);
	FillRect(x, y, width, height);


	x += width;
	SetColor(magenta);
	FillRect(x, y, width, height);


	x += width;
	SetColor(yellow);
	FillRect(x, y, width, height);


	x += width;
	SetColor(green);
	FillRect(x, y, width, height);


	x += width;
	SetColor(lightBlue);
	FillRect(x, y, width, height);


	x += width;
	SetColor(white);
	FillRect(x, y, width, height);

	black.a = 0.5;
	SetColor(black);
	FillRect(startX, startY, width*9, height/2);


}

void DrawPentagram() {
	float pie{ 3.1415f };
	float centerX{ 525.f };
	float centerY{ 250.f };
	float radius{ 70.f };

	Color4f magenta{1.f, 0.f, 1.f, 1.f };

	Point2f point1{ centerX + radius * float(cos(0.f / 5.f * pie)), centerY + radius * float(sin(0.f / 5.f * pie)) };
	Point2f point2{ centerX + radius * float(cos(2.f / 5.f * pie)), centerY + radius * float(sin(2.f / 5.f * pie)) };
	Point2f point3{ centerX + radius * float(cos(4.f / 5.f * pie)), centerY + radius * float(sin(4.f / 5.f * pie)) };
	Point2f point4{ centerX + radius * float(cos(6.f / 5.f * pie)), centerY + radius * float(sin(6.f / 5.f * pie)) };
	Point2f point5{ centerX + radius * float(cos(8.f / 5.f * pie)), centerY + radius * float(sin(8.f / 5.f * pie)) };


	SetColor(magenta);

	DrawLine(point1, point3, 2);
	DrawLine(point3, point5, 2);
	DrawLine(point5, point2, 2);
	DrawLine(point2, point4, 2);
	DrawLine(point4, point1, 2);

}
	
void DrawHouse() {
	float centerX{ 150.F };
	float centerY{ 380.f };
	float width{ 200.f };
	float height{ 80.f };

	Color4f red{ 1, 0.f, 0.f, 1 };
	Color4f white{ 1, 1.f, 1.f, 1 };


	SetColor(red);

	FillRect(centerX - (width / 2), centerY - (height / 2), width, height);
 
	//Point2f triangleLeftPoint{centerX - (width/2), centerY};
	//Point2f triangleRightPoint{centerX + (width/2), centerY};  
	//Point2f triangleTopPoint{ centerX, centerY + (height / 2) };
	//FillTriangle(triangleLeftPoint, triangleRightPoint, triangleTopPoint);  I cant get the FillTriangle to work

	SetColor(white);

	DrawRect(centerX - (width / 2), centerY - (height / 2), width, height);
	//DrawTriangle(triangleLeftPoint, triangleRightPoint, triangleTopPoint);
}

void AskGamerPercentages() {
	std::cout << "% people playing games \n";
	std::cout << "In the range [0, 20]? ";
	std::cin >> g_PercentageGamers0To20;
	std::cout << "In the range [21, 40]? ";
	std::cin >> g_PercentageGamers21To40;
	std::cout << "In the range [41, 60]? ";
	std::cin >> g_PercentageGamers41To60;
	std::cout << "Older then 60? ";
	std::cin >> g_PercentageGamersOlder60;
}

void DrawColumnChart() {
	float centerX{ 525.f };
	float bottomY{ 30.f };
	float width{ 80.f };
	float height{ 100.f };
	float numberBar{ -2 };
	Color4f	cyan{ 0.372549f, 0.619607f, 0.6277450f, 1.f };
	Color4f deepBlue{ 0.254901f, 0.411764f, 1.f, 1.f };
	Color4f lightBlue{ 0.529411f, 0.807843f, 0.980392f, 1.f };
	Color4f darkBlue{ 0.f, 0.f, 1.f, 1.f };

	SetColor(cyan);
	FillRect(centerX + (width * numberBar / 4), bottomY, width / 4, height / 100 * g_PercentageGamers0To20);
	++numberBar;

	SetColor(deepBlue);
	FillRect(centerX + (width * numberBar / 4), bottomY, width / 4, height / 100 * g_PercentageGamers21To40);
	++numberBar;
	SetColor(lightBlue);
	FillRect(centerX + (width * numberBar / 4), bottomY, width / 4, height / 100 * g_PercentageGamers41To60);
	++numberBar;
	SetColor(darkBlue);
	FillRect(centerX + (width * numberBar / 4), bottomY, width / 4, height / 100 * g_PercentageGamersOlder60);
	++numberBar;
}
#pragma endregion ownDefinitions