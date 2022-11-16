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
	ClearBackground();

	// Put your own draw statements here


	DrawRedRectangle();
	DrawGreenRectangle();
	DrawYellowRectangle();
	DrawBlueRectangle();


}

void Update(float elapsedSec)
{
	g_NrFrames++;
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

void DrawGreenRectangle() {
	float side{ 60 };
	float xPos{ float(int(g_NrFrames) % int(g_WindowWidth - side)) };
	float yPos{ g_WindowHeight - float(int(g_NrFrames) % int(g_WindowHeight - side)) - side };

	const Color4f green{0.f, 1.f, 0.f, 0.5f};
	const Color4f black{0.f, 0.f, 0.f, 1.f};

	SetColor(green);
	FillRect(xPos, yPos, side, side);

	SetColor(black);
	DrawRect(xPos, yPos, side, side);
}

void DrawRedRectangle() {
	float side{ 60 };
	float xPos{ float(int(g_NrFrames) % int(g_WindowWidth - side)) };
	float yPos{ float(int(g_NrFrames) % int(g_WindowHeight - side)) };

	const Color4f red{1.f, 0.f, 0.f, 0.5f};
	const Color4f black{0.f, 0.f, 0.f, 1.f};

	SetColor(red);
	FillRect(xPos, yPos, side, side);

	SetColor(black);
	DrawRect(xPos, yPos, side, side);
}

void DrawYellowRectangle() {
	float side{ 60 };
	float xPos{ g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth - side)) - side };
	float yPos{ float(int(g_NrFrames) % int(g_WindowHeight - side)) };

	const Color4f yellow{1.f, 1.f, 0.f, 0.5f};
	const Color4f black{0.f, 0.f, 0.f, 1.f};

	SetColor(yellow);
	FillRect(xPos, yPos, side, side);

	SetColor(black);
	DrawRect(xPos, yPos, side, side);
}

void DrawBlueRectangle() {
	float side{ 60 };
	float xPos{ g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth - side)) - side };
	float yPos{ g_WindowHeight - float(int(g_NrFrames) % int(g_WindowHeight - side)) - side };


	const Color4f blue{0.f, 0.f, 1.f, 0.5f};
	const Color4f black{0.f, 0.f, 0.f, 1.f};

	SetColor(blue);
	FillRect(xPos, yPos, side, side);

	SetColor(black);
	DrawRect(xPos, yPos, side, side);
}

#pragma endregion ownDefinitions