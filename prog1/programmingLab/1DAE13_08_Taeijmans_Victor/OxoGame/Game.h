#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
enum class gameState {
	playing,
	ended
};

gameState g_GameState{};

enum class OxoGridValues {
	X,
	O,
	empty
};

const int g_SizeArrOxoGrid{ 9 };
const int g_NrColOxoGrid{ 3 };
OxoGridValues g_ArrOxoGrid[g_SizeArrOxoGrid]{};
OxoGridValues g_ticValuePlayer1{};
OxoGridValues g_ticValuePlayer2{};

float marginTicValue{};

enum class playerTurn {
	player1,
	player2
};

playerTurn g_PlayerTurn{};

Texture g_GreenOTexture{};
Texture g_GreenXTexture{};
Texture g_WhiteOTexture{};
Texture g_WhiteXTexture{};
Texture g_EmptyCellTexture{};
Texture g_WinTexture{};
Texture g_BackgroundTexture{};

float g_SizeGrid{150.f};
float g_MarginGrid{5.f};
Point2f g_LeftBottomGrid{ g_WindowWidth / 2 - g_SizeGrid / 2,
						  g_WindowHeight / 2 - g_SizeGrid / 2 };

float g_MarginTicValues{ 30.f };
// Declare your own functions here
void InitTextures();
void DeleteTextures();

void InitGame();

void InitGrid();
void DrawGrid();
bool TikBox(OxoGridValues* pGridValues, int size, Point2f& clickPos, OxoGridValues newOxoValue);
bool CheckWiningCondition(bool* pBools, int size);
void DrawTicValues();
void checkWinCondition();
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
