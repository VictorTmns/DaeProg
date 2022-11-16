#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EventsAndDrawing - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
enum class ColorStatus {
	gray,
	green
};
enum class Status {
	unmoving,
	moving
};
enum class Direction {
	left,
	right
};

ColorStatus g_RectColorState{ ColorStatus::gray };
Status g_RectState{ Status::unmoving };

const int g_Margin{ 50 };
const int g_MinWidthRect{ 60 };
const int g_MinHeightRect{ 40 };


float g_RectWidth{ float((rand() % int(g_WindowWidth - (g_Margin * 2) - g_MinWidthRect)) + g_MinWidthRect) };
float g_RectHeight{ float((rand() % int(g_WindowHeight - (g_Margin * 2) - g_MinHeightRect)) + g_MinHeightRect) };
Point2f g_RectPos{ float(rand() % int(g_WindowWidth - (g_Margin * 2) - g_RectWidth)) + g_Margin, float(rand() % int(g_WindowHeight - (g_Margin * 2) - g_RectHeight)) + g_Margin };



float g_LinePosX{ 0.f };

Status g_LineState{ Status::unmoving };

Direction g_LineDirection{ Direction::right};

const Color4f g_LineColor(1.f, 0.f, 0.f, 1.f);

// Declare your own functions here
void DrawRect();
void UpdateRect();
void RegenerateRect();

void UpdateLine();
void DrawLine();

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
