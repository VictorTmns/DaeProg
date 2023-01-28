#pragma once
using namespace utils;
#include "Die.h"
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Ex59 - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
enum class GameState
{
	reset,
	playing,
	win
};

GameState g_Gamestate{ GameState::reset };

Die* g_pDie1{};
Die* g_pDie2{};

bool g_IsDiceRolling{false};

struct Player
{
	int score;
	Color4f color;
};

int g_NrOfPlayers{};
Player* g_pArrPlayers{};
int g_CurrentPlayer{};

Texture g_TempWinnerTexture{};
Texture g_WinTexture{};
Texture g_WinTextTexture{};

float g_DeltaTime{};
// Declare your own functions here
void UpdateDice();
void InitPlayers();
void DrawPlayers();
void DeletePlayers();
void UpdatePlayerScore();
void ShowWinTexture();
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
