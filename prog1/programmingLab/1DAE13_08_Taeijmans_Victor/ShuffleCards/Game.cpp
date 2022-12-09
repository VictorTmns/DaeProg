#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitCards();
}

void Draw()
{
	ClearBackground();
	DrawCards();

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
	DeleteCards();
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
	switch (key)
	{
	case SDLK_s:
		ShuffleTextures(g_ArrCardTextures, g_SizeArrCardTextures, 1000);
		break;
	}
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
void InitCards()
{
	const std::string path{ "Resources/Cards/" };
	const std::string extension{ ".png" };
	for (int idx = 0; idx < g_SizeArrCardTextures; idx++)
	{
		const int cardNumber{ (int(idx / g_NrOfNumberOnCards) + 1) * 100 + ((idx % g_NrOfNumberOnCards) + 1) };
		const std::string cardPath{ path + std::to_string(cardNumber) + extension };

		bool loaded{ TextureFromFile(cardPath, g_ArrCardTextures[idx]) };
		if (loaded == false) std::cout << "Texture couldn't load";
	}
}
void DrawCards()
{
	const float widthCard{ g_WindowWidth / g_Columns - g_Margin };
	const float heightCard{ g_WindowHeight / (g_SizeArrCardTextures / g_Columns) - g_Margin };
	for (int idx = 0; idx < g_SizeArrCardTextures; idx++)
	{
		const int row{ idx / g_NrOfNumberOnCards };
		const int column{ idx % g_NrOfNumberOnCards };
		DrawTexture(g_ArrCardTextures[idx], Rectf{ (widthCard + g_Margin) * column , (heightCard + g_Margin) * row, widthCard - g_Margin, heightCard - g_Margin});
	}
}
void DeleteCards()
{
	for (int idx = 0; idx < g_SizeArrCardTextures; idx++)
	{
		DeleteTexture(g_ArrCardTextures[idx]);
	}
}
void SwapTextures(Texture* pTextures, int size, int idx1, int idx2)
{
	Texture holdVar{ pTextures[idx1] };
	pTextures[idx1] = pTextures[idx2];
	pTextures[idx2] = holdVar;
}
void ShuffleTextures(Texture* pTextures, int size, int nrOfShuffles)
{
	for (int i = 0; i < nrOfShuffles; i++)
	{
	int randIdx1{ rand() % size };
	int randIdx2{};
	do
	{
		randIdx2 = rand() % size ;
	} while (randIdx1 == randIdx2);
	SwapTextures(pTextures, size, randIdx1, randIdx2);
	}
	
}
#pragma endregion ownDefinitions