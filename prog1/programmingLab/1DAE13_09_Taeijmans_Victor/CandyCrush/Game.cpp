#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitCandyTextures();
	InitGame();
	InitCandyGrid();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);
	switch (g_GameState)
	{
	case gameState::playing:
		DrawCandyGrid();
		DrawCandies();
		DrawMenu();
		switch (g_AnimationStat)
		{
		case animationStat::neutral:
			break;
		case animationStat::swap:
			DrawSwapAnimation();
			break;
		case animationStat::breaking:
			break;
		case animationStat::fall:
			break;
		default:
			break;
		}

		break;
	case gameState::winState:
		break;
	case gameState::menu:
		break;
	}
}

void Update(float elapsedSec)
{
	switch (g_GameState)
	{
	case gameState::playing:
		switch (g_AnimationStat)
		{
		case animationStat::neutral:
			break;
		case animationStat::swap:
			UpdateSwapAnimation(elapsedSec);
			break;
		case animationStat::breaking:
			break;
		case animationStat::fall:
			UpdateCandyGrid(elapsedSec);
			break;
		default:
			break;
		}
		break;
	case gameState::winState:
		break;
	case gameState::menu:
		break;
	}
}

void End()
{
	InitCandyTextures();
	DeleteCandyGrid();
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

	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	switch (g_AnimationStat)
	{
	case animationStat::neutral:
		HandleMouseClick(e, mousePos);
		break;
	default:
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void InitGame()
{
	g_GameState = gameState::playing;
	g_AnimationStat = animationStat::neutral;
}
void InitCandyGrid()
{
	for (int idx = 0; idx < g_SizeArrCandyGrid; idx++)
	{
		g_PArrCandyGrid[idx].cellCandyType = candyType::normal;
		g_PArrCandyGrid[idx].cellCandyColor = candyColor(rand()%6);	}

	if ((g_WindowHeight - g_CandyGridMargin * 2 - g_BottomMargin) / (g_SizeArrCandyGrid / g_NrOfColums)
	> (g_WindowWidth - g_CandyGridMargin * 2) / g_NrOfColums)
	{
		g_CellSize = (g_WindowWidth - g_CandyGridMargin * 2) / g_NrOfColums;
	}
	else
	{
		g_CellSize = (g_WindowHeight - g_CandyGridMargin * 2 - g_BottomMargin) / (g_SizeArrCandyGrid / g_NrOfColums);
	}
}
void DrawCandyGrid()
{
	float widthGrid{ g_CellSize * g_NrOfColums };
	float heightGrid{ g_CellSize * (g_SizeArrCandyGrid / g_NrOfColums) };
	
	Point2f centerGrid{ g_WindowWidth / 2, (g_WindowHeight - g_BottomMargin) / 2 + g_BottomMargin };
	const Point2f leftBottomGrid{ centerGrid.x - widthGrid/2, centerGrid.y - heightGrid/2 };
	

	
	for (int idx = 0; idx < g_SizeArrCandyGrid; idx++)
	{
		int Row{ GetRow(idx) };
		int Column{ GetColumn(idx) };
		SetColor(0.1f, 0.1f, 1.f, 0.3f);
		if (g_IdxFirstClicked == idx) SetColor(0.9f, 0.9f, 1.f, 0.4f);
		FillRect(leftBottomGrid.x + g_CellSize * Column, leftBottomGrid.y + g_CellSize * Row, g_CellSize, g_CellSize);

		SetColor(0.f, 0.f, 0.f);
		DrawRect(leftBottomGrid.x + g_CellSize * Column, leftBottomGrid.y + g_CellSize * Row, g_CellSize, g_CellSize);

	}
}
void UpdateCandyGrid(float elapsedSec)
{

}
void DeleteCandyGrid()
{
	delete[] g_PArrCandyGrid;
	g_PArrCandyGrid = nullptr;
}
void InitCandyTextures()
{
	bool loaded{};
	std::string path{ "Resources/" };
	std::string extension{ ".png" };
	std::string typeCandy{ "" };
	std::string colorCandy{ "" };



	colorCandy = "Blue";
	typeCandy = "regular";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_RegularBlueTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;
	typeCandy = "stripedHorizontal";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedHorizontalBlueTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;
	typeCandy = "stripedVertical";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedVerticalBlueTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;
	typeCandy = "wrappedBomb";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_WrappedBlueTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;


	colorCandy = "Green";
	typeCandy = "regular";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_RegularGreenTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedHorizontal";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedHorizontalGreenTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedVertical";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedVerticalGreenTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "wrappedBomb";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_WrappedGreenTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;


	colorCandy = "Orange";
	typeCandy = "regular";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_RegularOrangeTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedHorizontal";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedHorizontalOrangeTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedVertical";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedVerticalOrangeTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "wrappedBomb";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_WrappedOrangeTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;


	colorCandy = "Purple";
	typeCandy = "regular";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_RegularPurpleTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedHorizontal";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedHorizontalPurpleTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedVertical";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedVerticalPurpleTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "wrappedBomb";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_WrappedPurpleTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;


	colorCandy = "Red";
	typeCandy = "regular";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_RegularRedTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedHorizontal";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedHorizontalRedTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "stripedVertical";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedVerticalRedTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;
	typeCandy = "wrappedBomb";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_WrappedRedTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy; typeCandy;


	colorCandy = "Yellow";
	typeCandy = "regular";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_RegularYellowTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;typeCandy;
	typeCandy = "stripedHorizontal";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedHorizontalYellowTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;typeCandy;
	typeCandy = "stripedVertical";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_StripedVerticalYellowTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;typeCandy;
	typeCandy = "wrappedBomb";
	loaded = TextureFromFile(path + typeCandy + colorCandy + extension, g_WrappedYellowTexture);
	if (loaded == false) std::cout << "failed to load " << colorCandy + typeCandy;typeCandy;


}
void DrawCandies()
{

	for (int idx = 0; idx < g_SizeArrCandyGrid; idx++)
	{
		if (!g_PArrCandyGrid[idx].animationPlaying)
		{
			DrawCandy(idx);
		}

		
	}
}
void DrawCandy(int idx)
{
	const Point2f leftBottomGrid{ CalcLeftBottomGrid()};
	int Row{ GetRow(idx) };
	int Column{ GetColumn(idx) };
	Point2f candyPos{ leftBottomGrid.x + g_CellSize * Column + g_CellSize / 2 - g_CandySize / 2,
					  leftBottomGrid.y + g_CellSize * Row + g_CellSize / 2 - g_CandySize / 2 };



	switch (g_PArrCandyGrid[idx].cellCandyType)
	{
	case candyType::normal:
		switch (g_PArrCandyGrid[idx].cellCandyColor)
		{
		case candyColor::red:
			DrawTexture(g_RegularRedTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::green:
			DrawTexture(g_RegularGreenTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::yellow:
			DrawTexture(g_RegularYellowTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::orange:
			DrawTexture(g_RegularOrangeTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::blue:
			DrawTexture(g_RegularBlueTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::purple:
			DrawTexture(g_RegularPurpleTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		}
		break;
	case candyType::stripedVertical:
		switch (g_PArrCandyGrid[idx].cellCandyColor)
		{
		case candyColor::red:
			DrawTexture(g_StripedVerticalRedTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::green:
			DrawTexture(g_StripedVerticalGreenTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::yellow:
			DrawTexture(g_StripedVerticalYellowTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::orange:
			DrawTexture(g_StripedVerticalOrangeTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::blue:
			DrawTexture(g_StripedVerticalBlueTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::purple:
			DrawTexture(g_StripedVerticalPurpleTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		}
		break;
	case candyType::stripedHorizontal:
		switch (g_PArrCandyGrid[idx].cellCandyColor)
		{
		case candyColor::red:
			DrawTexture(g_StripedHorizontalRedTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::green:
			DrawTexture(g_StripedHorizontalGreenTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::yellow:
			DrawTexture(g_StripedHorizontalYellowTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::orange:
			DrawTexture(g_StripedHorizontalOrangeTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::blue:
			DrawTexture(g_StripedHorizontalBlueTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::purple:
			DrawTexture(g_StripedHorizontalPurpleTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		}
		break;
	case candyType::wrappedBomb:
		switch (g_PArrCandyGrid[idx].cellCandyColor)
		{
		case candyColor::red:
			DrawTexture(g_WrappedRedTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::green:
			DrawTexture(g_WrappedGreenTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::yellow:
			DrawTexture(g_WrappedYellowTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::orange:
			DrawTexture(g_WrappedOrangeTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::blue:
			DrawTexture(g_WrappedBlueTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		case candyColor::purple:
			DrawTexture(g_WrappedPurpleTexture, Rectf{ candyPos.x, candyPos.y, g_CandySize, g_CandySize });
			break;
		}
		break;
	case candyType::empty:
		break;
	}

}
void DeleteCandyTextures()
{
	DeleteTexture(g_RegularBlueTexture);
	DeleteTexture(g_StripedHorizontalBlueTexture);
	DeleteTexture(g_StripedVerticalBlueTexture);
	DeleteTexture(g_WrappedBlueTexture);
				
	DeleteTexture(g_RegularGreenTexture);
	DeleteTexture(g_StripedHorizontalGreenTexture);
	DeleteTexture(g_StripedVerticalGreenTexture);
	DeleteTexture(g_WrappedGreenTexture);
				
	DeleteTexture(g_RegularOrangeTexture);
	DeleteTexture(g_StripedHorizontalOrangeTexture);
	DeleteTexture(g_StripedVerticalOrangeTexture);
	DeleteTexture(g_WrappedOrangeTexture);
				
	DeleteTexture(g_RegularPurpleTexture);
	DeleteTexture(g_StripedHorizontalPurpleTexture);
	DeleteTexture(g_StripedVerticalPurpleTexture);
	DeleteTexture(g_WrappedPurpleTexture);
				
	DeleteTexture(g_RegularRedTexture);
	DeleteTexture(g_StripedHorizontalRedTexture);
	DeleteTexture(g_StripedVerticalRedTexture);
	DeleteTexture(g_WrappedRedTexture);
				
	DeleteTexture(g_RegularYellowTexture);
	DeleteTexture(g_StripedHorizontalYellowTexture);
	DeleteTexture(g_StripedVerticalYellowTexture);
	DeleteTexture(g_WrappedYellowTexture);

}
int CalcClickedIndex(Point2f clickedPoint)
{
	const float widthGrid{ g_CellSize * g_NrOfColums };
	const float heightGrid{ g_CellSize * (g_SizeArrCandyGrid / g_NrOfColums) };

	const Point2f centerGrid{ g_WindowWidth / 2, (g_WindowHeight - g_BottomMargin) / 2 + g_BottomMargin };
	const Point2f leftBottomGrid{ centerGrid.x - widthGrid / 2, centerGrid.y - heightGrid / 2 };

	const int column{ int((clickedPoint.x - leftBottomGrid.x) / g_CellSize) % g_NrOfColums };
	const int row{ int((clickedPoint.y - leftBottomGrid.y)/g_CellSize) };
	const int idx{ column + row * g_NrOfColums };

	return idx;
}
bool IsValidCombination(int idx1, int idx2)
{
	if (idx1 == idx2 - 1 || idx1 == idx2 + 1 || idx1 == idx2 - g_NrOfColums || idx1 == idx2 + g_NrOfColums)
	{
		return true;
	}
	return false;
}
bool IsMatchingCombination(int idx1, int idx2)
{
	swap(g_PArrCandyGrid, g_SizeArrCandyGrid, idx1, idx2);

	if (MatchesWithNeighbors(idx1 + 1) || MatchesWithNeighbors(idx1 - 1)
		|| MatchesWithNeighbors(idx1 + g_NrOfColums) || MatchesWithNeighbors(idx1 - g_NrOfColums)
		|| MatchesWithNeighbors(idx2 + 1) || MatchesWithNeighbors(idx2 - 1)
		|| MatchesWithNeighbors(idx2 + g_NrOfColums) || MatchesWithNeighbors(idx2 - g_NrOfColums)) 
	{
		swap(g_PArrCandyGrid, g_SizeArrCandyGrid, idx1, idx2);
		return true;
	}

	swap(g_PArrCandyGrid, g_SizeArrCandyGrid, idx1, idx2);
	return false;
}
bool MatchesWithNeighbors(int idx)
{
	if (g_PArrCandyGrid[idx-1].cellCandyColor == g_PArrCandyGrid[idx].cellCandyColor
		&& g_PArrCandyGrid[idx].cellCandyColor == g_PArrCandyGrid[idx + 1].cellCandyColor)
	{
		return true;
	}

	if (g_PArrCandyGrid[idx-g_NrOfColums].cellCandyColor == g_PArrCandyGrid[idx].cellCandyColor
		&& g_PArrCandyGrid[idx].cellCandyColor == g_PArrCandyGrid[idx + g_NrOfColums].cellCandyColor)
	{
		return true;
	}

	return false;
}

void InitSwap(int idx1, int idx2)
{

	g_SwapAnimation.idxCandy1 = idx1;
	g_SwapAnimation.idxCandy2 = idx2;
	g_SwapAnimation.currentSec = 0;

}
void DrawSwapAnimation() 
{
	const Point2f leftBottomGrid{ CalcLeftBottomGrid() };


	int Row{ GetRow(g_SwapAnimation.idxCandy1) };
	int Column{ GetColumn(g_SwapAnimation.idxCandy1) };
	Point2f candy1Pos{ leftBottomGrid.x + g_CellSize * Column + g_CellSize / 2 - g_CandySize / 2,
					  leftBottomGrid.y + g_CellSize * Row + g_CellSize / 2 - g_CandySize / 2 };

	Row = GetRow(g_SwapAnimation.idxCandy2);
	Column = GetColumn(g_SwapAnimation.idxCandy2);
	Point2f candy2Pos{ leftBottomGrid.x + g_CellSize * Column + g_CellSize / 2 - g_CandySize / 2,
					  leftBottomGrid.y + g_CellSize * Row + g_CellSize / 2 - g_CandySize / 2 };


	Vector2f movementVector{ candy2Pos.x - candy1Pos.x, candy2Pos.y - candy1Pos.y };

	Vector2f movementVector2{ ScaleLengthVector(movementVector, -1) };


	movementVector = ScaleLengthVector(movementVector, 1.f / g_NrSecsSwapAnimation);
	movementVector2 = ScaleLengthVector(movementVector2, 1.f / g_NrSecsSwapAnimation);



}
void UpdateSwapAnimation(float elapsedSec) 
{
	g_SwapAnimation.currentSec += elapsedSec;
}

void HandleMouseClick(const SDL_MouseButtonEvent& e, const Point2f& mousePos)
{
	const float widthGrid{ g_CellSize * g_NrOfColums };
	const float heightGrid{ g_CellSize * (g_SizeArrCandyGrid / g_NrOfColums) };
	const Point2f leftBottomGrid{ CalcLeftBottomGrid() };


	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (IsPointInRect(Rectf{ leftBottomGrid.x, leftBottomGrid.y, widthGrid, heightGrid }, mousePos))
		{
			g_IdxFirstClicked = CalcClickedIndex(mousePos);
		}
		break;
	case SDL_BUTTON_RIGHT:
		if (IsPointInRect(Rectf{ leftBottomGrid.x, leftBottomGrid.y, widthGrid, heightGrid }, mousePos))
		{
			int idxSecondClicked{ CalcClickedIndex(mousePos) };

			if (IsValidCombination(g_IdxFirstClicked, idxSecondClicked)
				&& IsMatchingCombination(g_IdxFirstClicked, idxSecondClicked))
			{
				std::cout << "valid\n";
			}
		}
		break;
	}

}

void DrawMenu()
{
	SetColor(1.f, 1.f, 1.f);
	DrawLine(0, g_BottomMargin, g_WindowWidth, g_BottomMargin);
}


#pragma region Utils
Point2f CalcLeftBottomGrid()
{
	const float widthGrid{ g_CellSize * g_NrOfColums };
	const float heightGrid{ g_CellSize * (g_SizeArrCandyGrid / g_NrOfColums) };

	const Point2f centerGrid{ g_WindowWidth / 2, (g_WindowHeight - g_BottomMargin) / 2 + g_BottomMargin };
	const Point2f leftBottomGrid{ centerGrid.x - widthGrid / 2, centerGrid.y - heightGrid / 2 };

	return leftBottomGrid;
}
int GetIndex(int row, int column)
{
	return (g_NrOfColums * row + column);
}
int GetRow(int idx)
{
	return(int(idx / g_NrOfColums));
}
int GetColumn(int idx)
{
	return(idx % g_NrOfColums);
}
void swap(cell* pCells, int size, int idx1, int idx2)
{
	cell temp{ pCells[idx1] };
	pCells[idx1] = pCells[idx2];
	pCells[idx2] = temp;
}

#pragma endregion Utils
#pragma endregion ownDefinitions