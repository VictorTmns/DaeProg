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
	// Put your own draw statements here
	pFraction->Draw(Point2f(10.f, 10.f), 20.f);

	pLight1->Draw();
	pLight2->Draw();
	pLight3->Draw();
	pLight4->Draw();
	pLight5->Draw();
	pLight6->Draw();

	pEllipse1->Draw();
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
	delete pFraction;
	pFraction = nullptr;

	delete pLight1;
	pLight1 = nullptr;
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
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	pEllipse1->ActivateTest(mousePos);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (pLight1->IsHit(mousePos) ||pLight2->IsHit(mousePos) ||pLight3->IsHit(mousePos) 
			||pLight4->IsHit(mousePos) ||pLight5->IsHit(mousePos) ||pLight3->IsHit(mousePos))
		{

		}
	default:
		break;
	}

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions