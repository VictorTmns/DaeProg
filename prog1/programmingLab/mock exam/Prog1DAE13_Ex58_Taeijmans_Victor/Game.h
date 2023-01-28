#pragma once
using namespace utils;
#include "Vehicle.h"
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "mock exam - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Texture g_BackgroundTexture{};
Texture g_PauseTexture{};
Texture g_WinTexture{};
Texture g_LoseTexture{};

enum class GameState
{
	reset,
	lose, 
	win ,
	pause,
	play
};

GameState g_Gamestat{ GameState::reset };


enum class Direction
{
	down,
	left,
	right
};

struct Chicken
{
	Point2f pos;
	float width;
	float height;
	float speed;
	Texture chickenTexture;
	Direction walkingDirection;
};

Chicken g_chicken{};

const int g_NrOfVehicles{ 5 };
Vehicle* g_ArrVehicles[g_NrOfVehicles]{};
// Declare your own functions here
void DrawTextTexture(const Texture& textTexture);
void MoveChicken(float elapsedSec);
void DrawChicken();
void DrawVehicles();
void UpdateVehicles(float elapsedSecs);
void ResetVehicles();
void CheckWinCondition();
void CheckColisions();
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
