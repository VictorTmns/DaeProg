#pragma once
using namespace utils;

#include <chrono>

#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_BallVelocity(100.f, 80.f);
Point2f g_BallPos(g_WindowWidth / 2, g_WindowHeight / 2);
float g_BallRadius{ 20.f };

Point2f g_SquareVelocity(0.f, 0.f);
Point2f g_SquarePos(g_WindowWidth / 3, g_WindowHeight);
float g_SquareSize{ 15.f };
bool g_SquareActive{ false };

int g_Frames{ 1 };
std::chrono::steady_clock::time_point g_T1;
std::chrono::steady_clock::time_point g_T2;

// Declare your own functions here
void UpdateBall(const float elapsedSeconds);
void DrawBall();
void UpdateSquare(const float elapsedSeconds);
void DrawSquare();
void DisplayFrameInfo();
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
