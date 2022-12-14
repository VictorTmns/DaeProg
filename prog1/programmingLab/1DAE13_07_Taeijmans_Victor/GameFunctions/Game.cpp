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
	ClearBackground(0.f, 0.f, 0.f);
	TestIsPointInCircle();
	TestIsPointInRect();
	TestIsOverlappping();


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

	g_MousePos = Point2f(float( e.x ), float( g_WindowHeight - e.y )) ;

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
void TestIsPointInCircle()
{
	if (IsPointInCircle(g_Circle, g_MousePos))
	{
		SetColor(1.f, 0.f, 0.f);
		FillCircle(g_Circle.center, g_Circle.radius+5.f);
	}

		SetColor(1.f, 1.f, 1.f);


	FillCircle(g_Circle);
}
void TestIsPointInRect()
{
	if (IsPointInRect(g_Rect, g_MousePos))
	{
		SetColor(1.f, 0.f, 0.f);
		FillRect(g_Rect.left-5.f, g_Rect.bottom-5.f, g_Rect.width+10.f, g_Rect.height+10.f);
	}



		SetColor(1.f, 1.f, 1.f);
	FillRect(g_Rect);
}

void TestIsOverlappping() 
{

	if (IsOverlapping(g_Rect, Rectf(g_MousePos.x - 40.f, g_MousePos.y, 40.f, 10.f)))
	{
		SetColor(1.f, 0.f, 0.f, 0.5f);
	}
	else
	{
		SetColor(0.f, 1.f, 0.f, 0.5f);
	}
	FillRect(g_MousePos.x - 40.f, g_MousePos.y, 40.f, 10.f);


	if (IsOverlapping(g_Circle, Circlef(g_MousePos.x + 40.f, g_MousePos.y, 40.f)))
	{
		SetColor(1.f, 0.f, 0.f, 0.5f);
	}
	else
	{
		SetColor(0.f, 1.f, 0.f, 0.5f);
	}
	FillCircle(g_MousePos.x + 40.f, g_MousePos.y, 40.f);
}
#pragma endregion ownDefinitions