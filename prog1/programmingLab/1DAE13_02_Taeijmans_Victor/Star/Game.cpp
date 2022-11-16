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
	DrawStar();

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
void DrawStar() {
	float pie{ 3.1415f };
	float outerRadius{ 200.f };
	float middleRadius{ outerRadius*13.f/20.f };
	float innerRadius{ outerRadius*6.f/20.f };

	Color4f red{ 1.f, 0.f, 0.f, 1.f };

	Point2f outerPoint1{ float(cos(0.f / 2.f * pie)) * outerRadius + g_WindowWidth / 2.f, float(sin(0.f / 2.f * pie)) * outerRadius + g_WindowHeight / 2.f };
	Point2f outerPoint2{ float(cos(1.f / 2.f * pie)) * outerRadius + g_WindowWidth / 2.f, float(sin(1.f / 2.f * pie)) * outerRadius + g_WindowHeight / 2.f };
	Point2f outerPoint3{ float(cos(2.f / 2.f * pie)) * outerRadius + g_WindowWidth / 2.f, float(sin(2.f / 2.f * pie)) * outerRadius + g_WindowHeight / 2.f };
	Point2f outerPoint4{ float(cos(3.f / 2.f * pie)) * outerRadius + g_WindowWidth / 2.f, float(sin(3.f / 2.f * pie)) * outerRadius + g_WindowHeight / 2.f};

	Point2f middlePoint1{ float(cos(1.f / 4.f * pie)) * middleRadius + g_WindowWidth / 2, float(sin(1.f / 4.f * pie)) * middleRadius + g_WindowHeight / 2.f };
	Point2f middlePoint2{ float(cos(3.f / 4.f * pie)) * middleRadius + g_WindowWidth / 2, float(sin(3.f / 4.f * pie)) * middleRadius + g_WindowHeight / 2.f };
	Point2f middlePoint3{ float(cos(5.f / 4.f * pie)) * middleRadius + g_WindowWidth / 2, float(sin(5.f / 4.f * pie)) * middleRadius + g_WindowHeight / 2.f };
	Point2f middlePoint4{ float(cos(7.f / 4.f * pie)) * middleRadius + g_WindowWidth / 2, float(sin(7.f / 4.f * pie)) * middleRadius + g_WindowHeight / 2.f };

	Point2f innerPoint1{ float(cos(1.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(1.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };
	Point2f innerPoint2{ float(cos(3.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(3.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };
	Point2f innerPoint3{ float(cos(5.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(5.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };
	Point2f innerPoint4{ float(cos(7.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(7.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };
	Point2f innerPoint5{ float(cos(9.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(9.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };
	Point2f innerPoint6{ float(cos(11.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(11.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };
	Point2f innerPoint7{ float(cos(13.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(13.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };
	Point2f innerPoint8{ float(cos(15.f / 8.f * pie)) * innerRadius + g_WindowWidth / 2, float(sin(15.f / 8.f * pie)) * innerRadius + g_WindowHeight / 2.f };

	SetColor(red);

	DrawLine(outerPoint1, innerPoint1);
	DrawLine(innerPoint1, middlePoint1);

	DrawLine(middlePoint1, innerPoint2);
	DrawLine(innerPoint2, outerPoint2);

	DrawLine(outerPoint2, innerPoint3);
	DrawLine(innerPoint3, middlePoint2);

	DrawLine(middlePoint2, innerPoint4);
	DrawLine(innerPoint4, outerPoint3);

	DrawLine(outerPoint3, innerPoint5);
	DrawLine(innerPoint5, middlePoint3);

	DrawLine(middlePoint3, innerPoint6);
	DrawLine(innerPoint6, outerPoint4);

	DrawLine(outerPoint4, innerPoint7);
	DrawLine(innerPoint7, middlePoint4);

	DrawLine(middlePoint4, innerPoint8);
	DrawLine(innerPoint8, outerPoint1);

}
#pragma endregion ownDefinitions