#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	DrawConcentricLines();
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
	switch (key)
	{
		break;
	case SDLK_RIGHT:
		SwitchColor();
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{

}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float( g_WindowHeight - e.y ) ;
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
void DrawConcentricLines() {
	const int amountVerticalLines{ int(g_WindowHeight / 10) + 1 };
	const int amountHorizontalLines{ int(g_WindowWidth / 10) + 1 };
	const float lineThickness{ 2.f };

	switch (colorLines)
	{
	case Color::red:
		SetColor(1.f, 0.f, 0.f, 1.f);
		break;
	case Color::green:
		SetColor(0.f, 1.f, 0.f, 1.f);
		break;
	case Color::blue:
		SetColor(0.f, 0.f, 1.f, 1.f);
		break;
	default:
		break;
	}

	for (int i = 0; i < amountVerticalLines; i++)
	{
		DrawLine(0.f, i * 10.f, g_MousePos.x, g_MousePos.y, lineThickness);
		DrawLine(g_WindowWidth, i * 10.f, g_MousePos.x, g_MousePos.y, lineThickness);
	}

	for (int i = 0; i < amountHorizontalLines; i++)
	{
		DrawLine( i * 10.f, 0.f, g_MousePos.x, g_MousePos.y, lineThickness);
		DrawLine(i * 10.f, g_WindowHeight, g_MousePos.x, g_MousePos.y, lineThickness);
	}
}


void SwitchColor() {
	switch (colorLines)
	{
	case Color::red:
		colorLines = Color::green;
		break;
	case Color::green:
		colorLines = Color::blue;
		break;
	case Color::blue:
		colorLines = Color::red;
		break;
	default:
		break;
	}
}
#pragma endregion ownDefinitions