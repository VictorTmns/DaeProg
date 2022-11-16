#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MatchesGame - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_AmountMatchesMainPile{ 21 };
int g_AmountMatchesPlayerPile{};
int g_AmountMatchesComputerPile{};
bool g_GameActive{ true };
bool g_PlayerTurn{ true };
std::string g_PlayerMoves{ "\nYour moves: " };
std::string g_PcMoves{ "\nComputer moves moves: " };

// Declare your own functions here
void DrawMatchesMainPile();
void DrawMatchesPlayerPile();
void DrawMatchesComputerPile();
void ComputerPickMatches();
void CheckEndConditions();
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
