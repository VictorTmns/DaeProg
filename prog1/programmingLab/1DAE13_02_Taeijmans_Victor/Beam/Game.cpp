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
	ClearBackground(0.f, 0.f, 0.f );


	// Put your own draw statements here
	DrawDrawings();

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

void DrawDrawings() {
	float squareSize{ 200.f };
	float border{ 10.f };

	Color4f green(0.f, 1.f, 0.f, 1.f);
	Color4f white(1.f, 1.f, 1.f, 1.f);

	SetColor(green);
	FillRect(border, border, squareSize, squareSize);
	FillRect(g_WindowWidth - border - squareSize, g_WindowHeight - border - squareSize, squareSize, squareSize);

	SetColor(white);
	DrawLine(border, border, border + squareSize, border);
	DrawLine(border, border, border , border + squareSize);
	DrawLine(border + squareSize, border, border + squareSize, border + squareSize);
	DrawLine(border, border + squareSize, border + squareSize, border + squareSize);

	DrawLine(g_WindowWidth - border, g_WindowHeight - border, g_WindowWidth - border - squareSize, g_WindowHeight - border);
	DrawLine(g_WindowWidth - border, g_WindowHeight - border, g_WindowWidth - border, g_WindowHeight - border - squareSize);
	DrawLine(g_WindowWidth - border - squareSize, g_WindowHeight - border - squareSize, g_WindowWidth - border - squareSize, g_WindowHeight - border);
	DrawLine(g_WindowWidth - border - squareSize, g_WindowHeight - border - squareSize, g_WindowWidth - border, g_WindowHeight - border - squareSize);

	DrawLine(border, border, g_WindowWidth - border - squareSize, g_WindowHeight - border - squareSize);
	DrawLine(border, border + squareSize, g_WindowWidth - border - squareSize, g_WindowHeight - border );
	DrawLine(border + squareSize, border, g_WindowWidth - border, g_WindowHeight - border - squareSize);
	DrawLine(border + squareSize, border + squareSize, g_WindowWidth - border, g_WindowHeight - border);


}

#pragma endregion ownDefinitions