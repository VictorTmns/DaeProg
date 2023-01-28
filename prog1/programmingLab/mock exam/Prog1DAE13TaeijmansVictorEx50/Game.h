#pragma once
using namespace utils;
#include "Tile.h"
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Ex50 - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 300 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
bool g_GameActive{true};
Texture g_WinTexture{};

const int g_NrOfTiles{ 4 };
const int g_NrOfColumns{ 2 };
Tile* g_ArrTiles[g_NrOfTiles]{};
const int g_NrOfAnimals{ 6 };
const float g_TileSize{ 128.f };
const Point2f g_LeftMiddle{ (g_WindowWidth - (g_TileSize * g_NrOfColumns)) / 2, g_WindowHeight / 2 };
// Declare your own functions here
void InitTileArray();
int GetIndex(const Point2f& pos);
void CheckWinCondition();
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
