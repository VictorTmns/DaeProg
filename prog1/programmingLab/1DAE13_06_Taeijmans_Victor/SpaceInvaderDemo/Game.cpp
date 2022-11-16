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
	ClearBackground(0.f,0.f,0.f);

	// Put your own draw statements here
	DrawInvader();
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



void DrawInvader()
{
	Color4f fillClr{ 0.f, 1.f, 0.f, 1.f }; // should be changed to RGB 70, 212, 82
	float left{ 20.f };
	float bottom{ g_WindowHeight / 2 };
	float pixelSize{ 6 };

	//body
	SetColor(0.f,1.f,0.f);
	const Rectf body{ left + 2 * pixelSize, bottom + 2 * pixelSize, 7 * pixelSize, 5 * pixelSize };
	FillRect(body);
	SetColor(0.f, 0.f, 0.f);
	FillRect(body.left + pixelSize, body.bottom, pixelSize * 5, pixelSize);

	SetColor(fillClr);
	//antenna ears left
	FillRect(body.left + pixelSize, body.bottom + body.height, pixelSize, pixelSize);
	FillRect(body.left, body.bottom + body.height + pixelSize, pixelSize, pixelSize);

	//antenna ears right
	FillRect(body.left + pixelSize * 5, body.bottom + body.height, pixelSize, pixelSize);
	FillRect(body.left + pixelSize * 6, body.bottom + body.height + pixelSize, pixelSize, pixelSize);

	//eyes 
	SetColor(0.f, 0.f, 0.f);
	FillRect(body.left + pixelSize, body.bottom + pixelSize * 3, pixelSize, pixelSize);
	FillRect(body.left + pixelSize * 5, body.bottom + pixelSize * 3, pixelSize, pixelSize);

	//sholder
	SetColor(fillClr);
	FillRect(body.left - pixelSize, body.bottom + 2 * pixelSize, pixelSize, pixelSize * 2);
	FillRect(body.left + pixelSize * 7, body.bottom + 2 * pixelSize, pixelSize, pixelSize * 2);

	//arms 
	FillRect(body.left - 2 * pixelSize, body.bottom + 2 * pixelSize, pixelSize, pixelSize * 4);
	FillRect(body.left + body.width + pixelSize, body.bottom + 2 * pixelSize, pixelSize, pixelSize * 4);
}

#pragma endregion ownDefinitions