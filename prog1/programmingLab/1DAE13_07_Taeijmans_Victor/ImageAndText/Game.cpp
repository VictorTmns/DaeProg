#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	bool loaded{ TextureFromFile("Resources/DAE.png", g_DaeTexture) };
	if (loaded == false) std::cout << "texture couldn't load";

	loaded = TextureFromString("DAE is the best, PROG is even better", "Resources/DIN-Light.otf",
								21, Color4f(0.f, 0.f, 0.f, 0.f), g_FontTexture);
	if (loaded == false) std::cout << "texture couldn't load";
}

void Draw()
{
	ClearBackground();

	Point2f texturePos{ g_WindowWidth / 2 - g_DaeTexture.width/2,
						g_WindowHeight / 2 - g_DaeTexture.height / 2 };
	DrawTexture(g_DaeTexture, texturePos);

	const float scale{ 0.5f };
	const float w{ g_DaeTexture.width * scale };
	const float h{ g_DaeTexture.height * scale };
	const float margin{ 3.f };
	Rectf logoDest{ g_WindowWidth - w - margin,
					g_WindowHeight - h - margin,
					w,  h};
	DrawTexture(g_DaeTexture, logoDest);

	DrawTexture(g_FontTexture, Point2f{ g_WindowWidth / 2 - g_FontTexture.width/2, margin });


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
	DeleteTexture(g_DaeTexture);
	DeleteTexture(g_FontTexture);
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