#include "pch.h"
#include "Game.h"
#include <iostream>
#include <string>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawMatchesMainPile();
	DrawMatchesPlayerPile();
	DrawMatchesComputerPile();
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
	if (g_GameActive)
	{
		switch (key)
		{
		case SDLK_1:
		case SDLK_KP_1:
			g_AmountMatchesPlayerPile += 1;
			g_AmountMatchesMainPile -= 1;
			g_PlayerMoves += ", 1";
			CheckEndConditions();


			ComputerPickMatches();
			break;
		case SDLK_2:
		case SDLK_KP_2:
			g_AmountMatchesPlayerPile += 2;
			g_AmountMatchesMainPile -= 2;
			g_PlayerMoves += ", 2";
			CheckEndConditions();

			ComputerPickMatches();
			break;
		case SDLK_3:
		case SDLK_KP_3:
			g_AmountMatchesPlayerPile += 3;
			g_AmountMatchesMainPile -= 3;
			g_PlayerMoves += ", 3";
			CheckEndConditions();

			ComputerPickMatches();
			break;
		}
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
void DrawMatchesMainPile() {
	const float OuterMargin{ 10.f };
	const float InnerMargin{ 8.f };
	const float matchWidth{ 5.f };
	const float matchHeight{ 60.f };
	const float matchTipHeight{ 10.f };
	const Point2f startPoint{ OuterMargin, g_WindowHeight - matchHeight - OuterMargin };

	for (int i = 0; i < g_AmountMatchesMainPile; i++)
	{
		const Point2f matchPos{ startPoint.x + (matchWidth + InnerMargin) * i, startPoint.y };
		const Point2f matchTip{ startPoint.x + (matchWidth + InnerMargin) * i, startPoint.y + matchHeight - matchTipHeight };

		SetColor(1.f, 0.f, 0.f, 1.f);
		FillRect(matchPos, matchWidth, matchHeight);
		SetColor(1.f, 1.f, 0.f, 1.f);
		FillRect(matchTip, matchWidth, matchTipHeight);


	}

}

void DrawMatchesPlayerPile() {
	const float OuterMargin{ 10.f };
	const float InnerMargin{ 8.f };
	const float matchWidth{ 5.f };
	const float matchHeight{ 60.f };
	const float matchTipHeight{ 10.f };
	const Point2f startPoint{ OuterMargin, OuterMargin };

	for (int i = 0; i < g_AmountMatchesPlayerPile; i++)
	{
		const Point2f matchPos{ startPoint.x + (matchWidth + InnerMargin) * i, startPoint.y };
		const Point2f matchTip{ startPoint.x + (matchWidth + InnerMargin) * i, startPoint.y + matchHeight - matchTipHeight };

		SetColor(1.f, 0.f, 0.f, 1.f);
		FillRect(matchPos, matchWidth, matchHeight);
		SetColor(1.f, 1.f, 0.f, 1.f);
		FillRect(matchTip, matchWidth, matchTipHeight);


	}
}

void DrawMatchesComputerPile() {
	const float OuterMargin{ 10.f };
	const float InnerMargin{ 8.f };
	const float matchWidth{ 5.f };
	const float matchHeight{ 60.f };
	const float matchTipHeight{ 10.f };
	const Point2f startPoint{ g_WindowWidth / 2, OuterMargin };

	for (int i = 0; i < g_AmountMatchesComputerPile; i++)
	{
		const Point2f matchPos{ startPoint.x + (matchWidth + InnerMargin) * i, startPoint.y };
		const Point2f matchTip{ startPoint.x + (matchWidth + InnerMargin) * i, startPoint.y + matchHeight - matchTipHeight };

		SetColor(1.f, 0.f, 0.f, 1.f);
		FillRect(matchPos, matchWidth, matchHeight);
		SetColor(1.f, 1.f, 0.f, 1.f);
		FillRect(matchTip, matchWidth, matchTipHeight);


	}
}

void ComputerPickMatches() {
	g_PlayerTurn = false;


	const int amountMatches = rand() % 3 + 1;
	g_AmountMatchesMainPile -= amountMatches;
	g_AmountMatchesComputerPile += amountMatches;
	g_PcMoves += ", " + std::to_string(amountMatches);
	CheckEndConditions();

	g_PlayerTurn = true;
}

void CheckEndConditions() {
	if (!(g_AmountMatchesMainPile > 0)) {
		std::cout << g_PlayerMoves << g_PcMoves;
		switch (g_PlayerTurn)
		{
		case 0:
			std::cout << "\nYou win :)";
			break;
		case 1:
			std::cout << "You lose :(";
			break;
		}
		g_GameActive = false;
	}
}
#pragma endregion ownDefinitions