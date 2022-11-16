#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	PrintVersions();
	InitMovingSquare();
}

void Draw()
{
	ClearBackground();
	DrawMovingSquare();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateMovingSquare();
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
	switch (key)
	{
	case SDLK_LEFT:
		if(g_MovingSquareSpeed > g_MinMovingSquareSpeed) --g_MovingSquareSpeed;
		break;
	case SDLK_RIGHT:
		if(g_MovingSquareSpeed < g_MaxMovingSquareSpeed) ++g_MovingSquareSpeed;
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };

		if (mousePos.x >= g_MovingSquarePos.x && mousePos.x <= g_MovingSquarePos.x + g_MovingSquareSize
			&& mousePos.y >= g_MovingSquarePos.y && mousePos.y <= g_MovingSquarePos.y + g_MovingSquareSize)
		{

			switch (g_MovingSquareActive)
			{
			case true:
				g_MovingSquareActive = false;
				break;
			case false:
				g_MovingSquareActive = true;
				break;
			}

		}
		else {
			std::cout << "You clicked outside the square.\n";
		}
		break;

	}
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void PrintVersions() {
	const int amountOfVersions{ 10 };

	std::cout << "Version History: \n";

	for (int i = 0; i < amountOfVersions; i++)
	{
		const int patchNumber{ rand() % 11 };

		const std::string version{  std::to_string(i + 1) + "." + std::to_string(i * 2) + "." + std::to_string(patchNumber) };


		switch (patchNumber)
		{
		case 0:
			std::cout << version;
			break;

		default:
		std::string patchVersion{ "" };

			patchVersion = std::to_string(patchNumber);

			switch (patchNumber)
			{
			case 1:
				patchVersion += "st";
				break;
			case 2:
				patchVersion += "nd";
				break;
			case 3:
				patchVersion += "rd";
				break;
			default:
				patchVersion += "th";
				break;
			}
			std::cout << version << "\t-> " << patchVersion << " patch";
			break;
		}

		std::cout << "\n";
	}
}

void InitMovingSquare() {
	g_MovingSquareDirection = Direction::leftSide;
	g_MovingSquareActive = true;
	g_MovingSquarePos = Point2f{ 0.f, 0.f };
	g_MovingSquareSpeed = 1.f;
}

void DrawMovingSquare() {
	const Color4f yellow{ 1.f, 1.f, 0.f, 1.f };

	SetColor(yellow);
	FillRect(g_MovingSquarePos, g_MovingSquareSize, g_MovingSquareSize);
}

void UpdateMovingSquare() {

	UpdateMovingSquarePos();
	UpdateMovingSquareDir();
	
}

void UpdateMovingSquarePos() {
	if (g_MovingSquareActive) {

		switch (g_MovingSquareDirection)
		{
		case Direction::leftSide:
			g_MovingSquarePos.y += g_MovingSquareSpeed;
			break;
		case Direction::topside:
			g_MovingSquarePos.x += g_MovingSquareSpeed;
			break;
		case Direction::diagonal:
			g_MovingSquarePos.x -= g_MovingSquareSpeed;
			g_MovingSquarePos.y -= g_MovingSquareSpeed;
			break;
		}

	}
}

void UpdateMovingSquareDir() {
	if (g_MovingSquarePos.y > g_WindowHeight - g_MovingSquareSize) {
		const float pixelsOverWindowBorder{ float(int(g_MovingSquarePos.y) % int(g_WindowHeight - g_MovingSquareSize)) };

		g_MovingSquareDirection = Direction::topside;
		g_MovingSquarePos.y -= pixelsOverWindowBorder;
	}
	else if (g_MovingSquarePos.x > g_WindowWidth - g_MovingSquareSize) {
		const float pixelsOverWindowBorder{ float(int(g_MovingSquarePos.x) % int(g_WindowWidth - g_MovingSquareSize)) };

		g_MovingSquareDirection = Direction::diagonal;
		g_MovingSquarePos.x -= pixelsOverWindowBorder;
	}
	else if (g_MovingSquarePos.x < 0 || g_MovingSquarePos.y < 0) {
		const float pixelsOverWindowBorderX{ g_MovingSquarePos.x * -1 };
		const float pixelsOverWindowBorderY{ g_MovingSquarePos.y * -1 };


		g_MovingSquareDirection = Direction::leftSide;
		g_MovingSquarePos.x += pixelsOverWindowBorderX;
		g_MovingSquarePos.y += pixelsOverWindowBorderY;
	}
}


#pragma endregion ownDefinitions