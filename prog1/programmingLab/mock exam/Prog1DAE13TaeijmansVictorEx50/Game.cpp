#include "pch.h"
#include "Game.h"
#include "iostream"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitTileArray();
	bool loaded{};

	loaded = utils::TextureFromFile("Resources/Names.png", g_WinTexture);
	if (loaded == false) std::cout << "failed to load ";
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	for (int idx = 0; idx < g_NrOfTiles; idx++)
	{
		g_ArrTiles[idx]->Draw();
	}
	if (g_GameActive)
	{
		SetColor(1.f, 0.f, 0.f);
	}
	else
	{
		const int currentAnimal{ g_ArrTiles[0]->GetCurrentAnimal() };
		DrawTexture(g_WinTexture, Point2f{ g_WindowWidth / 2 - g_WinTexture.width / 2,30.f }, Rectf{ 0.f, (g_WinTexture.height / g_NrOfAnimals) * (currentAnimal + 1), g_WinTexture.width, g_WinTexture.height / g_NrOfAnimals });
		SetColor(0.f, 1.f, 0.f);
	}

	DrawRect(g_LeftMiddle.x, g_LeftMiddle.y - g_TileSize, g_TileSize * 2, g_TileSize * 2, 4.f);

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
	switch (key)
	{
	case SDLK_r:
		for (int idx = 0; idx < g_NrOfTiles; idx++)
		{
			g_ArrTiles[idx]->Shuffle();
		}
		g_GameActive = true;
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	for (int idx = 0; idx < g_NrOfTiles; idx++)
	{
		g_ArrTiles[idx]->CheckActivation(mousePos);
	}
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		for (int idx = 0; idx < g_NrOfTiles; idx++)
		{
			if (g_ArrTiles[idx]->CheckHit(mousePos))
			{
				CheckWinCondition();
			}
		}
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void InitTileArray()
{

	for (int idx = 0; idx < g_NrOfTiles; idx++)
	{
		const int row{ int(idx / 2) };
		const int column{ idx % 2 };

		const Rectf boundingBox{ g_LeftMiddle.x + g_TileSize * column, g_LeftMiddle.y - g_TileSize * row, g_TileSize, g_TileSize };
		const std::string imagePath{ "Resources/Tiles" + std::to_string(row) + std::to_string(column) + ".png" };

		g_ArrTiles[idx] = new Tile{ boundingBox, imagePath, g_NrOfAnimals};
	}
}
int GetIndex(const Point2f& pos)
{
	const int row{ int((pos.x - g_LeftMiddle.x) / g_TileSize) };
	const int column{ int(((g_WindowHeight - pos.y) - g_LeftMiddle.x) / g_TileSize) };
	return column + 2 * row;
}
void CheckWinCondition()
{

	if (g_ArrTiles[0]->GetCurrentAnimal() == g_ArrTiles[1]->GetCurrentAnimal() && g_ArrTiles[0]->GetCurrentAnimal() == g_ArrTiles[2]->GetCurrentAnimal()
		&& g_ArrTiles[0]->GetCurrentAnimal() == g_ArrTiles[3]->GetCurrentAnimal())
	{
		for (int idx = 0; idx < g_NrOfTiles; idx++)
		{
			g_ArrTiles[idx]->Deactivate();
		}
		g_GameActive = false;
	}
}
#pragma endregion ownDefinitions