#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "SpaceInvaders - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
struct PlayerJet
{
	Point2f pos;
	int dirDegrees;
	const Color4f color;
};

struct Bullet
{
	Point2f pos;
	int dirDegrees;
	Color4f color;
	bool active;
	int bulletCooldown;
}g_Bullet1Player0, g_Bullet1Player1, g_Bullet1Player2, g_Bullet1Player3;


const float g_SizeJets{ 20.f };
const float g_SpeedJets{ 2.f };
const int g_TurningSpeedJets{ 15 };
const int bulletCooldown{ 40 };

PlayerJet g_Player1{
 Point2f(g_WindowWidth / 4.f, g_WindowHeight / 2.f),
90,
 Color4f(0.f, 0.f, 0.f, 1.f)
};
// Declare your own functions here
void DrawPlayer1();
void UpdatePlayer1();
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
