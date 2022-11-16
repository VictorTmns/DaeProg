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
	ClearBackground(0.f, 0.f, 0.f);

	drawYellowBar();
	drawRedBar();

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
void drawYellowBar() {
	const int margin{ 10 };
	const int height{ 80 };
	const int borderWidth{ 4 };
	const int redBarGrowth{ 15 };
	const int redBarDelay{ 30 };
	Color4f yellow{ 1.f, 1.f, 0.f, 1.f };
	Color4f white{ 1.f, 1.f, 1.f, 1.f };

	SetColor(yellow);
	FillRect(margin, g_WindowHeight - margin - height, float(g_NrFrames % int(g_WindowWidth + 1 - 2 * margin)), height);

	SetColor(white);
	DrawRect(margin, g_WindowHeight - margin - height, g_WindowWidth - 2 * margin, height, borderWidth);
}

void drawRedBar() {
	const int margin{ 10 };
	const int height{ 80 };
	const int borderWidth{ 4 };
	const int redBarGrowth{ 15 };
	const int redBarDelay{ 30 };

	Color4f red{ 1.f, 0.f, 0.f, 1.f };
	Color4f white{ 1.f, 1.f, 1.f, 1.f };

	SetColor(red);
	FillRect(margin, margin, floorf(float(g_NrFrames % (2 * int(g_WindowWidth + redBarGrowth - 2 * margin))) / redBarDelay) * redBarGrowth, height);

	SetColor(white);
	DrawRect(margin, margin, g_WindowWidth - 2 * margin, height, borderWidth);


}
#pragma endregion ownDefinitions