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
	ClearBackground(0.4f, 0.f, 1.f);
	DrawImage();

	// Put your own draw statements here

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
void DrawImage() {
	const float pos{ float((g_NrFrames % int(g_WindowWidth)) + 1) };

	Color4f white(1.f, 1.f, 1.f, 1.f);
	Color4f yellow(1.f, 1.f, 0.f, 1.f);

	SetColor(white);
	DrawLine(pos, 0, pos, g_WindowHeight);
	DrawLine(g_WindowWidth - pos , 0, g_WindowWidth - pos, g_WindowHeight);

	DrawLine(0, pos, g_WindowWidth, pos);
	DrawLine(0, g_WindowWidth - pos, g_WindowWidth, g_WindowWidth - pos);

	SetColor(yellow);
	DrawLine(pos, 0, g_WindowWidth, pos);
	DrawLine(g_WindowWidth, pos, g_WindowWidth - pos, g_WindowHeight);
	DrawLine(g_WindowWidth - pos, g_WindowHeight, 0, g_WindowHeight - pos);
	DrawLine(0, g_WindowHeight - pos, pos, 0);


}
#pragma endregion ownDefinitions