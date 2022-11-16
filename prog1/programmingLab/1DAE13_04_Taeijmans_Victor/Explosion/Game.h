#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 400 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_MousePos{};

enum class BombState {
	neutral,
	explode
};


BombState g_BombElementState{ BombState::neutral };
const float g_BombSize{60.f};
const Point2f g_BombPos{ g_WindowWidth/2 - g_BombSize / 2, g_WindowHeight/2 - g_BombSize / 2 };
int g_ExplosionDuration{ 0 };

// Declare your own functions here
void ProcessMouseClick();
void DrawBomb();
void DrawExplosion();
void ResetExplosion();
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
