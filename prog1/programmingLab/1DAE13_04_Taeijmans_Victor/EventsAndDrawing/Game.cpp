#include "pch.h"
#include "Game.h"
#include "time.h"
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
	DrawRect();
	DrawLine();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	UpdateRect();
	UpdateLine();
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
	case SDLK_r:
		switch (g_RectState)
		{
		case Status::unmoving:
			g_RectState = Status::moving;
			break;
		case Status::moving:
			g_RectState = Status::unmoving;
			break;
		default:
			break;
		}
		break;
	case SDLK_i:
		switch (g_LineState)
		{
		case Status::unmoving:
			g_LineState = Status::moving;
			break;
		case Status::moving:
			g_LineState = Status::unmoving;
			break;
		default:
			break;
		}
	default:
		break;
	}
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
		//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:

		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	if (((mousePos.x >= g_RectPos.x && mousePos.x <= g_RectPos.x + g_RectWidth) || (mousePos.x >= (g_RectPos.x - g_WindowWidth) && mousePos.x <= (g_RectPos.x - g_WindowWidth) + g_RectWidth))
		&& (mousePos.y >= g_RectPos.y && mousePos.y <= g_RectPos.y + g_RectHeight))
		{
			
		switch (g_RectColorState)
			{
			case ColorStatus::gray:
				g_RectColorState = ColorStatus::green;
				break;
			case ColorStatus::green:
				g_RectColorState = ColorStatus::gray;
				RegenerateRect();
				break;
			default:
				break;
			};
		};

		break;
	}

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
void DrawRect() {
	Color4f rectColor{};

	switch (g_RectColorState)
	{
	case ColorStatus::gray:
		rectColor = Color4f(0.8f, 0.8f, 0.8f, 1.f);
		break;
	case ColorStatus::green:
		rectColor = Color4f(0.f, 1.f, 0.f, 1.f);
		break;
	default:
		break;
	};

	SetColor(rectColor);
	FillRect(g_RectPos, g_RectWidth, g_RectHeight);
	FillRect(g_RectPos.x - g_WindowWidth, g_RectPos.y, g_RectWidth, g_RectHeight);



}

void UpdateRect() {
	switch (g_RectState)
	{
	case Status::unmoving:
		break;
	case Status::moving:
		g_RectPos.x++;
		break;
	default:
		break;
	};

	if (g_RectPos.x > g_WindowWidth) {
		g_RectPos.x = 0;
	};
}

void RegenerateRect() {
	g_RectWidth = float((rand() % int(g_WindowWidth - (g_Margin * 2) - g_MinWidthRect)) + g_MinWidthRect);
	g_RectHeight = float((rand() % int(g_WindowHeight - (g_Margin * 2) - g_MinHeightRect)) + g_MinHeightRect);
	g_RectPos.x = float(rand() % int(g_WindowWidth - (g_Margin * 2) - g_RectWidth) + g_Margin);
	g_RectPos.y = float(rand() % int(g_WindowHeight - (g_Margin * 2) - g_RectHeight) + g_Margin) ;

}

void DrawLine() {
	SetColor(g_LineColor);

	DrawLine(g_LinePosX, 0, g_LinePosX, g_WindowHeight);
}

void UpdateLine() {
	switch (g_LineState)
	{
	case Status::moving:
		switch (g_LineDirection)
		{
		case Direction::left:
			--g_LinePosX;
			break;
		case Direction::right:
			++g_LinePosX;
			break;
		default:
			break;
		}

		if (g_LinePosX > g_WindowWidth)
		{
			g_LineDirection = Direction::left;
		}
		else if (g_LinePosX < 0) {
			g_LineDirection = Direction::right;
		}

		break;
	default:
		break;
	}
}
#pragma endregion ownDefinitions