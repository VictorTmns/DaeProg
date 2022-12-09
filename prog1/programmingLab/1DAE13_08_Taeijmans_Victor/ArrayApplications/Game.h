#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_MaxPoints{ 10 };
Point2f g_ArrMouseClicks[g_MaxPoints]{};
int g_NextIdxArrMouseClicks{};

const int g_NrRotatingPentagrams{5};
AngleSpeed g_ArrAngularSpeed[g_NrRotatingPentagrams]{};

const int g_SizeArrStatsRand{ 6 };
int g_ArrStatsRand[g_SizeArrStatsRand]{};
Texture g_ArrStatsRandTextures[g_SizeArrStatsRand]{};


struct g_TraceCircles {
	Point2f pos;
	int age;
};

const int g_SizeArrTraceCircles{ 10 };
g_TraceCircles g_ArrTraceCircles[g_SizeArrTraceCircles]{};
const int g_MaxCoolDown{ 30 };
int g_CoolDown{ g_MaxCoolDown };
int g_CircleShrinkSpeed{ 10 };
const int g_MaxAgeCircles{ 15 * g_CircleShrinkSpeed };

const Point2f g_LeftBottemGrid{ 10.f, 10.f };
const float g_SizeCellClickGrid{ 60.f };
const int g_NrVerticalCells{ 3 };
const int g_NrHorizontalCells{ 4 };
const int g_SizeArrClickGrid{ g_NrHorizontalCells * g_NrVerticalCells };
bool g_ArrClickGrid[g_SizeArrClickGrid]{};

// Declare your own functions here
void AddClickedPoint(Point2f* pInts, int size, const Point2f& newPoint);
void Swap(Point2f* pInts, int idx1, int idx2);
void DrawClickPolygon();

void InitRotatingPentagrams();
void DrawRotatingPentagrams();
void UpdateRotatingPentagrams(float elapsedSec);
void DrawPentagram(const Point2f& centerPos, float radius, float angle);

void InitRandStats();
void DrawRandStats();
void UpdateRandStats();
void DeleteRandStats();

void DrawMousePoints();
void UpdateMousePoints();
void AddMousePos(g_TraceCircles* pPoints, int size, const Point2f& newPos);

void InitClickGrid();
void DrawClickGrid();
void ToggleCell(bool* pBools, int size, const Point2f& clickPoint);
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
