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
	DrawStatisticsOneDice();
	DrawStatisticsTwoDice();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	TrowOneDice();
	TrowTwoDice();
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
void TrowOneDice() {

	int trow{ (rand() % 6) + 1 };

	switch (trow)
	{
	case 1:
		++G_AmountOneTrowsOneDice;
		break;
	case 2:
		++G_AmountTwoTrowsOneDice;
		break;
	case 3:
		++G_AmountThreeTrowsOneDice;
		break;
	case 4:
		++G_AmountFourTrowsOneDice;
		break;
	case 5:
		++G_AmountFiveTrowsOneDice;
		break;
	case 6:
		++G_AmountSixTrowsOneDice;
		break;
	default:
		break;
	}

}

void TrowTwoDice() {

	int trow{ (rand() % 6) + 1 };
	int trow2{ (rand() % 6) + 1 };
	int totalTrow{ trow + trow2 };

	switch (totalTrow)
	{
	case 1:
		++G_AmountOneTrowsTwoDice;
		break;
	case 2:
		++G_AmountTwoTrowsTwoDice;
		break;
	case 3:
		++G_AmountThreeTrowsTwoDice;
		break;
	case 4:
		++G_AmountFourTrowsTwoDice;
		break;
	case 5:
		++G_AmountFiveTrowsTwoDice;
		break;
	case 6:
		++G_AmountSixTrowsTwoDice;
		break;
	case 7:
		++G_AmountSevenTrowsTwoDice;
		break;
	case 8:
		++G_AmountEightTrowsTwoDice;
		break;
	case 9:
		++G_AmountNineTrowsTwoDice;
		break;
	case 10:
		++G_AmountTenTrowsTwoDice;
		break;
	case 11:
		++G_AmountElevenTrowsTwoDice;
		break;
	case 12:
		++G_AmountTwelfTrowsTwoDice;
		break;
	default:
		break;
	}
}

void DrawStatisticsOneDice() {
	float barHeight{ 22.f };
	float OuterMargin{ 5.f };
	float margin{ 3.f };

	SetColor(1.f, 0.f, 0.f, 1.f);
	FillRect(OuterMargin,OuterMargin + barHeight * 1 + margin * 1, float(G_AmountOneTrowsOneDice), barHeight);
	FillRect(OuterMargin,OuterMargin + barHeight * 2 + margin * 2, float(G_AmountTwoTrowsOneDice), barHeight);
	FillRect(OuterMargin,OuterMargin + barHeight * 3 + margin * 3, float(G_AmountThreeTrowsOneDice), barHeight);
	FillRect(OuterMargin,OuterMargin + barHeight * 4 + margin * 4, float(G_AmountFourTrowsOneDice), barHeight);
	FillRect(OuterMargin,OuterMargin + barHeight * 5 + margin * 5, float(G_AmountFiveTrowsOneDice), barHeight);
	FillRect(OuterMargin,OuterMargin + barHeight * 6 + margin * 6, float(G_AmountSixTrowsOneDice), barHeight);


}

void DrawStatisticsTwoDice() {
	float barHeight{22.f};
	float OuterMargin{ 5.f };
	float margin{ 3.f };

	SetColor(0.f, 0.f, 1.f, 1.f);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 1 - margin * 1, float(G_AmountTwoTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 2 - margin * 2, float(G_AmountThreeTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 3 - margin * 3, float(G_AmountFourTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 4 - margin * 4, float(G_AmountFiveTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 5 - margin * 5, float(G_AmountSixTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 6 - margin * 6, float(G_AmountSevenTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 7 - margin * 7, float(G_AmountEightTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 8 - margin * 8, float(G_AmountNineTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 9 - margin * 9, float(G_AmountTenTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 10 - margin * 10, float(G_AmountElevenTrowsTwoDice), barHeight);
	FillRect(OuterMargin, g_WindowHeight - OuterMargin - barHeight * 11 - margin * 11, float(G_AmountTwelfTrowsTwoDice), barHeight);

}
#pragma endregion ownDefinitions