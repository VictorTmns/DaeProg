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
	ClearBackground();

	DrawStairs();
	DrawSpinningLines();
	DrawConcentricSquares();
	DrawSpiral();
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
	
	switch (key)
	{
	case SDLK_UP:
		if (g_NumberOfLoops < 20) ++g_NumberOfLoops;
		std::cout << g_NumberOfLoops << "\n";
		break;
	case SDLK_DOWN:
		if (g_NumberOfLoops > 5 ) --g_NumberOfLoops;
		std::cout << g_NumberOfLoops << "\n";
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{

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
void DrawStairs() {
	const Point2f startPoint{ 15.f, 270.f };
	const float sideStairs{ 200.f };
	

	const float lineLength{ sideStairs / g_NumberOfLoops };

	SetColor(1.f, 0.f, 0.f, 1.f);

	for (int i = 0; i < g_NumberOfLoops; i++)
	{
		switch (i % 2)
		{
		case 0:
			SetColor(1.f, 0.f, 0.f, 1.f);
			break;
		case 1:
			SetColor(0.f, 0.f, 1.f, 1.f);
			break;
		default:
			break;
		}

		Point2f point1{ startPoint.x + lineLength * i, startPoint.y + lineLength * i };
		Point2f point2{ startPoint.x + lineLength * (i + 1), startPoint.y + lineLength * i };
		Point2f point3{ startPoint.x + lineLength * (i + 1), startPoint.y + lineLength * (i + 1) };

		DrawLine(point1, point2, 4.f);
		DrawLine(point2, point3, 4.f);



	}
}

void DrawSpinningLines() {
	const Point2f startPoint{ 265.f, 270.f };
	const float sideLength{ 200.f };
	const int amountSpinningLines{ g_NumberOfLoops };
	const float lineThickness{ 2.f };

	for (int i = 0; i < amountSpinningLines; i++)
	{
		SetColor(1.f, 0.f, 0.f, 1.f);
		DrawLine(startPoint.x + sideLength * i / amountSpinningLines, startPoint.y, startPoint.x + sideLength, startPoint.y + sideLength * i / amountSpinningLines, lineThickness);

		SetColor(0.f, 1.f, 0.f, 1.f);
		DrawLine(startPoint.x, startPoint.y + sideLength - sideLength * i / amountSpinningLines, startPoint.x + sideLength * i / amountSpinningLines, startPoint.y, lineThickness);

		SetColor(0.f, 0.f, 1.f, 1.f);
		DrawLine(startPoint.x - sideLength * i / amountSpinningLines + sideLength, startPoint.y + sideLength, startPoint.x, startPoint.y - sideLength * i / amountSpinningLines + sideLength, lineThickness);

		SetColor(1.f, 1.f, 0.f, 1.f);
		DrawLine(startPoint.x + sideLength, startPoint.y + sideLength * i / amountSpinningLines, startPoint.x + sideLength - sideLength * i / amountSpinningLines, startPoint.y + sideLength, lineThickness);

	}
}

void DrawConcentricSquares() {
	const float maxSideSize{ 200.f };
	const float minSideSize{ 40.f };
	const int amountOfSteps{ g_NumberOfLoops };
	const Point2f startPoint{ 20.f, 20.f };

	float stepSize{ (maxSideSize - minSideSize) / (amountOfSteps - 1) };

	for (int i = 0; i < amountOfSteps; i++)
	{
		DrawRect(startPoint.x + stepSize / 2 * i, startPoint.x + stepSize / 2 * i, maxSideSize - stepSize * i, maxSideSize - stepSize * i);
	}
	//DrawRect(startPoint.x + stepSize / 2 * 5, startPoint.x + stepSize / 2 * 5, minSideSize, minSideSize);

}

void DrawSpiral() {
	const float maxSideSize{ 200.f };
	const float minSideSize{ 30.f };
	const int amountOfSteps{ g_NumberOfLoops };
	const Point2f startPoint{ 275.f, 20.f };

	const float stepSize{ (maxSideSize - minSideSize) / (amountOfSteps - 1) / 2 };

	SetColor(1.f, 0.f, 0.f, 1.f);

	for (int i = 0; i < amountOfSteps; i++)
	{
		const float distanceFromOuterBox{ stepSize * i };
		const float distanceFromOuterBoxShrink{ stepSize * (i + 1) };

		const Point2f point1{ startPoint.x + distanceFromOuterBox				, startPoint.y + distanceFromOuterBox };
		const Point2f point2{ startPoint.x - distanceFromOuterBox + maxSideSize	, startPoint.y + distanceFromOuterBox };
		const Point2f point3{ startPoint.x - distanceFromOuterBox + maxSideSize	, startPoint.y - distanceFromOuterBox + maxSideSize };
		const Point2f point4{ startPoint.x + distanceFromOuterBoxShrink			, startPoint.y - distanceFromOuterBox + maxSideSize };
		const Point2f point5{ startPoint.x + distanceFromOuterBoxShrink			, startPoint.y + distanceFromOuterBoxShrink };


		DrawLine(point1, point2);
		DrawLine(point2, point3);
		DrawLine(point3, point4);
		DrawLine(point4, point5);
		//DrawLine(startPoint.x + stepSize * i / 2, startPoint.y + stepSize * i / 2, startPoint.x + maxSideSize - stepSize * i / 2, startPoint.y + stepSize * i / 2);
		//DrawLine(startPoint.x + maxSideSize - stepSize * i / 2, startPoint.y + stepSize * i / 2, startPoint.x + maxSideSize - stepSize * i / 2, startPoint.y - stepSize * i / 2 + maxSideSize);
	}

}
#pragma endregion ownDefinitions