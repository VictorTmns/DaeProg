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
void DrawConcentricSquare(const Point2f& leftBottomPos, float size, int numberOfSquares);
void DrawConcentricSquare(float bottom, float left, float size, int numberOfSquares);
void DrawTriangles();
void DrawEquilateralTriangle(const Point2f& leftBottomPos, float verticesSize, bool isFilled = false);
void DrawEquilateralTriangle(float bottom, float left, float verticesSize, bool isFilled = false);
void DrawPentagrams();
void DrawPentagram(const Point2f& centerPos, float radius);
void DrawLineairGradients();
void DrawLineairGradient(const Point2f& leftBottomPos, float width, float height, const Color4f& startColor, const Color4f& finalColor);
void DrawDotGrids();
void DrawDotGrid(const Point2f& leftBottomPos, const float radiusDots, const float margin,  const int numberOfDotsHorizontal, const int numberOfDotsVertical, const Color4f& color);
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
