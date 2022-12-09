#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitTextures();
	InitGame();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);
	// Put your own draw statements here
	switch (g_GameState)
	{
	case gameState::playing:

		DrawGrid();
		DrawTicValues();
		break;
	case gameState::ended:


		break;
	}
}

void Update(float elapsedSec)
{

}

void End()
{
	// free game resources here
	DeleteTextures();
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
	case SDLK_a:
		switch (g_ticValuePlayer1)
		{
		case OxoGridValues::X:
			g_ticValuePlayer1 = OxoGridValues::O;
			break;
		case OxoGridValues::O:
			g_ticValuePlayer1 = OxoGridValues::X;
			break;
		}
	case SDLK_i:
		switch (g_ticValuePlayer2)
		{
		case OxoGridValues::X:
			g_ticValuePlayer2 = OxoGridValues::O;
			break;
		case OxoGridValues::O:
			g_ticValuePlayer2 = OxoGridValues::X;
			break;
		}
		//std::cout << "Right arrow key released\n";
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		switch (g_PlayerTurn)
		{
		case playerTurn::player1:
			if (TikBox(g_ArrOxoGrid, g_SizeArrOxoGrid, mousePos, g_ticValuePlayer1)) { g_PlayerTurn = playerTurn::player2; }
			break;
		case playerTurn::player2:
			if (TikBox(g_ArrOxoGrid, g_SizeArrOxoGrid, mousePos, g_ticValuePlayer2)) g_PlayerTurn = playerTurn::player1;
			break;
		default:
			break;
		}
		checkWinCondition();
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void InitTextures()
{
	bool loaded{};
	loaded = TextureFromFile("Resources/GreenO.png", g_GreenOTexture);
	if (loaded == false) std::cout << "failed to load GreenOTexture";

	loaded = TextureFromFile("Resources/GreenX.png", g_GreenXTexture);
	if (loaded == false) std::cout << "failed to load GreenXTexture";

	loaded = TextureFromFile("Resources/WhiteO.png", g_WhiteOTexture);
	if (loaded == false) std::cout << "failed to load WhiteOTexture";

	loaded = TextureFromFile("Resources/WhiteX.png", g_WhiteXTexture);
	if (loaded == false) std::cout << "failed to load WhiteXTexture";

	loaded = TextureFromFile("Resources/FreeCell.png", g_EmptyCellTexture);
	if (loaded == false) std::cout << "failed to load FreeCellTexture";

	loaded = TextureFromFile("Resources/Win.png", g_WinTexture);
	if (loaded == false) std::cout << "failed to load WinTexture";

	loaded = TextureFromFile("Resources/OXO.png", g_BackgroundTexture);
	if (loaded == false) std::cout << "failed to load OXOTexture";

}
void DeleteTextures()
{
	DeleteTexture(g_GreenOTexture);
	DeleteTexture(g_GreenXTexture);
	DeleteTexture(g_WhiteOTexture);
	DeleteTexture(g_WhiteXTexture);
	DeleteTexture(g_EmptyCellTexture);
	DeleteTexture(g_WinTexture);
	DeleteTexture(g_BackgroundTexture);

}

void InitGame() {
	g_GameState = gameState::playing;
	g_ticValuePlayer1 = OxoGridValues::X;
	g_ticValuePlayer2 = OxoGridValues::X;
	InitGrid();
}

void InitGrid()
{
	for (int idx = 0; idx < g_SizeArrOxoGrid; idx++)
	{
		g_ArrOxoGrid[idx] = OxoGridValues::empty;
	}
}
void DrawGrid()
{
	const float cellSize{ (g_SizeGrid - ((g_NrColOxoGrid - 1) * g_MarginGrid)) / g_NrColOxoGrid };
	for (int idx = 0; idx < g_SizeArrOxoGrid; idx++)
	{
		const int row{ idx / g_NrColOxoGrid };
		const int col{ idx % g_NrColOxoGrid };
		Rectf CellPoss{g_LeftBottomGrid.x + (cellSize + g_MarginGrid) * col,
				g_LeftBottomGrid.y + (cellSize + g_MarginGrid) * row,
				cellSize, cellSize };
		
		switch (g_ArrOxoGrid[idx])
		{
		case OxoGridValues::X:
			DrawTexture(g_WhiteXTexture, CellPoss);
			break;
		case OxoGridValues::O:
			DrawTexture(g_WhiteOTexture, CellPoss);
			break;
		case OxoGridValues::empty:
			DrawTexture(g_EmptyCellTexture, CellPoss);
			break;
		default:
			break;
		}
	}
}
bool TikBox(OxoGridValues* pGridValues, int size, Point2f& clickPos, OxoGridValues newOxoValue)
{
	Point2f posOnGrid{ clickPos.x - g_LeftBottomGrid.x, clickPos.y - g_LeftBottomGrid.y };

	switch (g_PlayerTurn)
	{
	case playerTurn::player1:
		std::cout << "p1: ";
		break;
	case playerTurn::player2:
		std::cout << "p2: ";
		break;
	default:
		break;
	}

	// checks if the clicked point is outside the oxo grid
	if (!IsPointInRect(Rectf(g_LeftBottomGrid.x, g_LeftBottomGrid.y, g_SizeGrid, g_SizeGrid), clickPos))
	{
		std::cout << "out grid\n";
		return false;
	}

	// checks if the clicked point is in the margins of the oxo grid
	const float cellSize{ (g_SizeGrid - ((g_NrColOxoGrid - 1) * g_MarginGrid)) / g_NrColOxoGrid };
	if (int(posOnGrid.x) % int(cellSize + g_MarginGrid) > cellSize || int(posOnGrid.y) % int(cellSize + g_MarginGrid) > cellSize)
	{
		std::cout << "in margin\n";
		return false;
	}

	// calculates the row, column and index of the clicked cell
	int column{ int(posOnGrid.y / (cellSize + g_MarginGrid)) };
	int row{ int(posOnGrid.x / (cellSize + g_MarginGrid)) };
	int idx{ column * g_NrColOxoGrid + row };

	// checkes if the clicked cel is emty
	if (!(g_ArrOxoGrid[idx] == OxoGridValues::empty))
	{
		std::cout << "This cell already has a value\n";
		return false;
	}

	g_ArrOxoGrid[idx] = newOxoValue;
		std::cout << "succesfull\n";
	return true;
}
bool CheckWiningConditions(bool* pBools, int size)
{
	return NULL;
}
void DrawTicValues()
{
	if (g_PlayerTurn == playerTurn::player2) {
		switch (g_ticValuePlayer1)
		{
		case OxoGridValues::X:
			DrawTexture(g_WhiteXTexture, Point2f{ g_MarginTicValues, g_MarginTicValues });
			break;
		case OxoGridValues::O:
			DrawTexture(g_WhiteOTexture, Point2f{ g_MarginTicValues, g_MarginTicValues });
			break;
		}
	}
	else
	{
		switch (g_ticValuePlayer1)
		{
		case OxoGridValues::X:
			DrawTexture(g_GreenXTexture, Point2f{ g_MarginTicValues, g_MarginTicValues });
			break;
		case OxoGridValues::O:
			DrawTexture(g_GreenOTexture, Point2f{ g_MarginTicValues, g_MarginTicValues });
			break;
		}
	}

	if (g_PlayerTurn == playerTurn::player2) {
		switch (g_ticValuePlayer2)
		{
		case OxoGridValues::X:
			DrawTexture(g_GreenXTexture, Point2f{ g_WindowWidth - g_MarginTicValues - g_GreenXTexture.width,  g_MarginTicValues });
			break;
		case OxoGridValues::O:
			DrawTexture(g_GreenOTexture, Point2f{ g_WindowWidth - g_MarginTicValues - g_GreenOTexture.width,  g_MarginTicValues });
			break;
		}

	}
	else
	{
		switch (g_ticValuePlayer2)
		{
		case OxoGridValues::X:
			DrawTexture(g_WhiteXTexture, Point2f{ g_WindowWidth - g_MarginTicValues - g_WhiteXTexture.width,  g_MarginTicValues });
			break;
		case OxoGridValues::O:
			DrawTexture(g_WhiteOTexture, Point2f{ g_WindowWidth - g_MarginTicValues - g_WhiteOTexture.width,  g_MarginTicValues });
			break;
		}
	}
}
void CheckWinCondition() 
{

}
#pragma endregion ownDefinitions