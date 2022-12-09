#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	Vector2f vector1{ 80.f, 0.f };
	Vector2f vector2{ 0.f, 50.f };
	Vector2f vector3{ 60.f, 80.f };

	std::cout << ToString(Vector2f{ 40.f, 30.f }) << "\n\n\n";
	std::cout << "-- DotProduct--\n";

	std::cout << "v1 = " << ToString(vector1) << "\tv2 = " <<ToString(vector2) << "\tDot product = " << DotProductVectors(vector1, vector2) << "\n";
	std::cout << "v1 = " << ToString(vector1) << "\tpara = " <<ToString(vector3) << "\tDot product = " << DotProductVectors(vector1, vector3) << "\n";


	std::cout << "-- CrossProduct--\n";

	std::cout << "v1 = " << ToString(vector1) << "\tv2 = " <<ToString(vector2) << "\tCross product = " << CrossProductVectors(vector1, vector2) << "\n";
	std::cout << "v2 = " << ToString(vector2) << "\tv1 = " <<ToString(vector1) << "\tCross product = " << CrossProductVectors(vector2, vector1) << "\n";


	std::cout << "-- Length--\n";

	std::cout << "v = " << ToString(vector1) << "\tLength = " << CalcLengthVector(vector1) << "\n";
	std::cout << "v = " << ToString(vector2) << "\tLength = " << CalcLengthVector(vector2) << "\n";
	std::cout << "v = " << ToString(vector3) << "\tLength = " << CalcLengthVector(vector3) << "\n";


	std::cout << "-- scalar --\n";

	std::cout << "v = " << ToString(vector1) << "\tscalar = " << 2 << "\tscaled = " << ToString(ScaleLengthVector(vector1, 2)) << "\n";
	std::cout << "v = " << ToString(vector2) << "\tscalar = " << 3 << "\tscaled = " << ToString(ScaleLengthVector(vector2, 3)) << "\n";
	std::cout << "v = " << ToString(vector3) << "\tscalar = " << 8 << "\tscaled = " << ToString(ScaleLengthVector(vector3, 8)) << "\n";


	std::cout << "-- normalized --\n";

	std::cout << "v = " << ToString(vector1) << "\tnormalize = " << ToString(NormalizeVector(vector1)) << "\n";
	std::cout << "v = " << ToString(vector2) << "\tnormalize = " << ToString(NormalizeVector(vector2)) << "\n";
	std::cout << "v = " << ToString(vector3) << "\tnormalize = " << ToString(NormalizeVector(vector3)) << "\n";


	std::cout << "-- angle between --\n";
	std::cout << "v1 = " << ToString(vector1) << "\tv2 = " << ToString(vector2) << "\tAngle = " << AngleBetweenVectors(vector1, vector2) << " Rad" << "\n";
	std::cout << "v1 = " << ToString(vector1) << "\tv2 = " << ToString(vector3) << "\tAngle = " << AngleBetweenVectors(vector1, vector3) << " Rad" << "\n";
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	Vector2f vector1{ 30.f, 40.f };
	Vector2f vector2{ 60.f, 20.f };
	Point2f startPoint{ 300.f, 150.f };

	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawVector(startPoint, Vector2f{ 40.f, 30.f });

		
	vector1 = Vector2f{ 70.f, 10.f };
	vector2 = Vector2f{ 10.f, 70.f };
	startPoint = Point2f{ 100.f, 100.f };
	SetColor(1.f, 0.f, 0.f, 1.f);
	DrawVector(startPoint, vector1);
	DrawVector(Point2f{ startPoint.x + vector1.x, startPoint.y + vector1.y }, vector2);
	SetColor(0.f, 1.f, 0.f, 1.f);
	DrawVector(Point2f{ startPoint.x, startPoint.y }, AddVectors(vector1, vector2));
			

	vector1 = Vector2f{ 70.f, 10.f };
	vector2 = Vector2f{ 20.f, 80.f };
	startPoint = Point2f{ 100.f, 400.f };
	SetColor(1.f, 0.f, 0.f, 1.f);
	DrawVector(startPoint, vector1);
	DrawVector(Point2f{ startPoint.x + vector1.x, startPoint.y + vector1.y }, Vector2f{ vector2.x * -1 , vector2.y * -1 });
	SetColor(0.f, 1.f, 0.f, 1.f);
	DrawVector(Point2f{ startPoint.x, startPoint.y }, SubstractVectors(vector1, vector2));
			

	vector1 = Vector2f{ 70.f, 10.f };
	vector2 = Vector2f{ 20.f, 80.f };
	startPoint = Point2f{ 100.f, 400.f };
	SetColor(1.f, 0.f, 0.f, 1.f);
	DrawVector(startPoint, vector1);
	DrawVector(Point2f{ startPoint.x + vector1.x, startPoint.y + vector1.y }, Vector2f{ vector2.x * -1 , vector2.y * -1 });
	SetColor(0.f, 1.f, 0.f, 1.f);
	DrawVector(Point2f{ startPoint.x, startPoint.y }, SubstractVectors(vector1, vector2));


	startPoint = Point2f{ 400.f, 600.f };
	float radius{ 60.f };
	float angle{ g_Frames % 500 / 500.f * g_Pi * 2.f };
	Vector2f clockVector{ cosf(angle) * radius, sinf(angle) * radius };
	Vector2f normalXVector{ 0.71f, 0.71f };
	DrawVector(startPoint, clockVector);

	float dot{ DotProductVectors(clockVector, normalXVector) };
	SetColor(1.f, 0.f, 0.f, 1.f);
	DrawVector(startPoint, ScaleLengthVector(normalXVector, dot));

}

void Update(float elapsedSec)
{
	g_Frames++;
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