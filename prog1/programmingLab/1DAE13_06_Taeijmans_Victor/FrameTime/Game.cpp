#include "pch.h"
#include "Game.h"
#include <iostream>

#include <chrono>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	std::chrono::steady_clock::time_point g_T1 = std::chrono::steady_clock::now();
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBall();
	DrawSquare();
}

void Update(float elapsedSec)
{
	g_Frames++;

	if (g_Frames % 100 == 0)
	{
		DisplayFrameInfo();
	}
	UpdateBall(elapsedSec);
	UpdateSquare(elapsedSec);
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
	case SDLK_s:
		g_SquareActive = true;
		break;
	default:
		break;
	}
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
void DisplayFrameInfo()
{
	std::chrono::steady_clock::time_point g_T2 = std::chrono::steady_clock::now();

	float elapsedSeconds = std::chrono::duration<float>(g_T2 - g_T1).count();

	g_T1 = g_T2;


	std::cout << "Number of frames: " << g_Frames <<  ", AcculatedTime: " <<  elapsedSeconds <<  ", Fps: " <<  100/elapsedSeconds << "\n";
}

void UpdateBall(const float elapsedSeconds)
{
	const float acceleration{ 0.f };
	g_BallVelocity = Point2f(g_BallVelocity.x + acceleration * elapsedSeconds, g_BallVelocity.y + acceleration * elapsedSeconds);
	g_BallPos = Point2f(g_BallPos.x + g_BallVelocity.x * elapsedSeconds, g_BallPos.y + g_BallVelocity.y * elapsedSeconds);

	if ((g_BallPos.x - g_BallRadius) <= 0 || (g_BallPos.x + g_BallRadius) > g_WindowWidth)
	{
		g_BallVelocity.x *= -1;
	}

	if ((g_BallPos.y - g_BallRadius) <= 0 || (g_BallPos.y + g_BallRadius) > g_WindowHeight)
	{
		g_BallVelocity.y *= -1;
	}

}
void DrawBall()
{
	FillEllipse(g_BallPos, g_BallRadius, g_BallRadius);
}
void UpdateSquare(const float elapsedSeconds)
{
	const float gravity{ -9.81f };
	const float acceleration{ 0.f };

	switch (g_SquareActive)
	{
	case true:
	g_SquareVelocity = Point2f(g_SquareVelocity.x + acceleration * elapsedSeconds, g_SquareVelocity.y + gravity * elapsedSeconds);
	g_SquarePos = Point2f(g_SquarePos.x + g_SquareVelocity.x * elapsedSeconds, g_SquarePos.y + g_SquareVelocity.y * elapsedSeconds);
	break;
	default:
		break;
	}


	if ((g_SquarePos.y - g_SquareSize) <= 0)
	{
		g_SquareVelocity.y *= -1;
	}
	if ((g_SquarePos.y + g_SquareSize) >= g_WindowHeight)
	{
		g_SquareActive = false;
	}

}
void DrawSquare()
{
	FillRect(g_SquarePos, g_SquareSize, g_SquareSize);
}

#pragma endregion ownDefinitions