#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "StaticDrawing - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 700 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_PercentageGamers0To20{};
int g_PercentageGamers21To40{};
int g_PercentageGamers41To60{};
int g_PercentageGamersOlder60{};

// Declare your own functions here
void DrawBelgianFlag();
void DrawCheckBoard();
void DrawColorSpectrum();
void DrawPentagram();
void DrawHouse();
void DrawColumnChart();
void AskGamerPercentages();

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
