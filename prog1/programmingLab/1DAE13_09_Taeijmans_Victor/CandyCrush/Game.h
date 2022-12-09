#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Candy Crush - Warre Stoop, Victor Taeijmans - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 560 };
float g_WindowHeight{ 720 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Texture g_RegularBlueTexture{};
Texture g_StripedHorizontalBlueTexture{};
Texture g_StripedVerticalBlueTexture{};
Texture g_WrappedBlueTexture{};

Texture g_RegularGreenTexture{};
Texture g_StripedHorizontalGreenTexture{};
Texture g_StripedVerticalGreenTexture{};
Texture g_WrappedGreenTexture{};

Texture g_RegularOrangeTexture{};
Texture g_StripedHorizontalOrangeTexture{};
Texture g_StripedVerticalOrangeTexture{};
Texture g_WrappedOrangeTexture{};

Texture g_RegularPurpleTexture{};
Texture g_StripedHorizontalPurpleTexture{};
Texture g_StripedVerticalPurpleTexture{};
Texture g_WrappedPurpleTexture{};

Texture g_RegularRedTexture{};
Texture g_StripedHorizontalRedTexture{};
Texture g_StripedVerticalRedTexture{};
Texture g_WrappedRedTexture{};

Texture g_RegularYellowTexture{};
Texture g_StripedHorizontalYellowTexture{};
Texture g_StripedVerticalYellowTexture{};
Texture g_WrappedYellowTexture{};

enum class gameState
{
	playing,
	winState,
	menu
};

enum class animationStat
{
	neutral,
	swap,
	breaking,
	fall
};

animationStat g_AnimationStat{};

gameState g_GameState{};

enum class candyColor
{
	red,
	green,
	yellow,
	orange,
	blue,
	purple,

};

enum class candyType
{
	normal,
	stripedVertical,
	stripedHorizontal,
	wrappedBomb,
	empty,
};


struct cell
{
	bool blocked;
	candyColor cellCandyColor;
	candyType cellCandyType;
	bool animationPlaying;
};

int g_SizeArrCandyGrid{ 80 };
cell* g_PArrCandyGrid{ new cell[g_SizeArrCandyGrid]{} };
int g_NrOfColums{ 8 };
float g_CellSize{};

float g_BottomMargin{ 100.f };
float g_CandyGridMargin{ 20.f };

float g_CandySize{40.f};

int g_IdxFirstClicked{-1};

struct swapAnimaton
{
	int idxCandy1;
	int idxCandy2;
	float currentSec;
};

swapAnimaton g_SwapAnimation{};


float g_NrSecsSwapAnimation{ 2.f };
// Declare your own functions here
void InitCandyGrid();
void DrawCandyGrid();
void UpdateCandyGrid(float elapsedSec);
void DeleteCandyGrid();

void InitCandyTextures();
void DrawCandies();
void DrawCandy(int idx);
void DeleteCandyTextures();



bool IsValidCombination(int idx1, int idx2);
bool IsMatchingCombination(int idx1, int idx2);
bool MatchesWithNeighbors(int idx);

void HandleMouseClick(const SDL_MouseButtonEvent& e, const Point2f& mousePos);

void InitSwap(int idx1, int idx2);
void DrawSwapAnimation();
void UpdateSwapAnimation(float elapsedSec);

void InitGame();
void DrawMenu();

int CalcClickedIndex(Point2f clickedPoint);
Point2f CalcLeftBottomGrid();
int GetIndex(int row, int column);
int GetRow(int idx);
int GetColumn(int idx);
void swap(cell* pCells, int size, int idx1, int idx2);
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
