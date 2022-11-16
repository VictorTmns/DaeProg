#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DrawFunctions - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 400 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here
void DrawSquares();
void DrawConcentricSquare(const Point2f leftBottomPos, float size, int numberOfSquares);
void DrawConcentricSquare(float bottom, float left, float size, int numberOfSquares);
void DrawTriangles();
void DrawEquilateralTriangle(const Point2f leftBottomPos, float verticesSize, bool isFilled = false);
void DrawEquilateralTriangle(float bottom, float left, float verticesSize, bool isFilled = false);
void DrawPentagrams();
void DrawPentagram(const Point2f centerPos, float radius);
void DrawLineairGradients();
void DrawLineairGradient(const Point2f leftBottomPos, float width, float height, Color4f startColor, Color4f finalColor);
Color4f RgbToColor4f(float r, float g, float b, float a = 255);
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
