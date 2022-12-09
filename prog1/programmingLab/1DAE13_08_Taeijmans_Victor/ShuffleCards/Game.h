#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 1500 };
float g_WindowHeight{ g_WindowWidth*(2.5f/6.f) };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_SizeArrCardTextures{ 52 };
Texture g_ArrCardTextures[g_SizeArrCardTextures]{};
const int g_NrOfNumberOnCards{ 13 };
const int g_Columns{ 13 };
const float g_Margin{ 1.f };

// Declare your own functions here
void InitCards();
void DrawCards();
void DeleteCards();
void SwapTextures(Texture* pTextures, int size, int idx1, int idx2);
void ShuffleTextures(Texture* pTextures, int size, int nrOfShuffles);
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
