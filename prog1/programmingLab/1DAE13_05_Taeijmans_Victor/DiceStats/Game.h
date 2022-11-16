#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DiceStats - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int G_AmountOneTrowsOneDice{};
int G_AmountTwoTrowsOneDice{};
int G_AmountThreeTrowsOneDice{};
int G_AmountFourTrowsOneDice{};
int G_AmountFiveTrowsOneDice{};
int G_AmountSixTrowsOneDice{};

int G_AmountOneTrowsTwoDice{};
int G_AmountTwoTrowsTwoDice{};
int G_AmountThreeTrowsTwoDice{};
int G_AmountFourTrowsTwoDice{};
int G_AmountFiveTrowsTwoDice{};
int G_AmountSixTrowsTwoDice{};
int G_AmountSevenTrowsTwoDice{};
int G_AmountEightTrowsTwoDice{};
int G_AmountNineTrowsTwoDice{};
int G_AmountTenTrowsTwoDice{};
int G_AmountElevenTrowsTwoDice{};
int G_AmountTwelfTrowsTwoDice{};
// Declare your own functions here
void TrowOneDice();
void TrowTwoDice();

void DrawStatisticsOneDice();
void DrawStatisticsTwoDice();
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
