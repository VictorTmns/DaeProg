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
	ClearBackground(0.529f, 0.808f, 92.2f);

	SetColor(0.1333f, 0.54509f, 0.1333f);
	FillRect(0, 0, 800, 100);

	SetColor(1, 0.74091f, 0);
	FillRect(450, 70, 100, 140);

	SetColor(0.8f, 0.2f, 0.1f);
	FillRect(440, 170, 120, 40);

	SetColor(0.5f, 0.2f, 0.05f);
	FillRect(460, 73, 20, 50);

	SetColor(0.529f, 0.808f, 1);
	FillRect(510, 85, 30, 30);

	SetColor(0, 0, 0);
	FillEllipse(200, 140, 10, 10);
	DrawLine(200, 140, 200, 100, 3.0f);
	DrawLine(200, 130, 210, 105, 3.0f);
	DrawLine(200, 130, 190, 105, 3.0f);
	DrawLine(200, 100, 210, 75, 3.0f);
	DrawLine(200, 100, 190, 75, 3.0f);

	SetColor(1, 1, 1);
	DrawArc(200, 140, 7, 7, 3.1415f, 6.282f, 2.0f);
	FillEllipse(197, 144, 2, 2);
	FillEllipse(203, 144, 2, 2);



	

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

#pragma endregion ownDefinitions