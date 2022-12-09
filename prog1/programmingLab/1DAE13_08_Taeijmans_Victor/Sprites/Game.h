#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
struct Sprite
{
    Texture texture;
    int frames;
    int cols;
    float frameTime;
    int currentFrame;
    float accumulatedTime;
};

Sprite g_KnightSprite{};
Point2f g_KnightPosition{100.f, 100.f};

Sprite g_TiboSprite{};
Point2f g_TiboPosition{250.f, 10.f};
// Declare your own functions here
void InitKnight();
void DrawKnight();
void UpdateKnight(float elapsedSec);
void DeleteKnight();
void InitTibo();
void DrawTibo();
void UpdateTibo(float elapsedSec);
void DeleteTibo();
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
