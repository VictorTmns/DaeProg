#include "pch.h"
#include "Game.h"
#include <iostream>


//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitRotatingPentagrams();
	InitRandStats();
	InitClickGrid();

}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);
	DrawRotatingPentagrams();
	DrawRandStats();
	DrawClickGrid();
	DrawClickPolygon();
	DrawMousePoints();


}

void Update(float elapsedSec)
{
	UpdateRotatingPentagrams(elapsedSec);
	UpdateRandStats();
	UpdateMousePoints();
}

void End()
{
	DeleteRandStats();
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	AddMousePos(g_ArrTraceCircles, g_SizeArrTraceCircles, mousePos);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
		AddClickedPoint(g_ArrMouseClicks, g_MaxPoints, mousePos);
		break;
	}
	case SDL_BUTTON_RIGHT:
	{
		Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
		ToggleCell(g_ArrClickGrid, g_SizeArrClickGrid, mousePos);
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void AddClickedPoint(Point2f* pPoints, int size, const Point2f &newPoint)
{
	for (int idx = 0; idx < size-1; idx++)
	{
		Swap(pPoints, idx, idx + 1);
	}
	pPoints[size - 1] = newPoint;
}
void Swap(Point2f* pInts, int idx1, int idx2)
{
	Point2f holdVarialbe{ pInts[idx1] };
	pInts[idx1] = pInts[idx2];
	pInts[idx2] = holdVarialbe;

}
void DrawClickPolygon() {
	float radiusClickPoints{ 10.f };
	for (int idx = 0; idx < g_MaxPoints-1; idx++)
	{
		SetColor(1.f, 1.f, 1.f, 1.f);
		Point2f point1{ g_ArrMouseClicks[idx] };
		Point2f point2{ g_ArrMouseClicks[idx + 1] };
		DrawLine(point1.x, point1.y, point2.x, point2.y);
	}
	for (int idx = 0; idx < g_MaxPoints; idx++)
	{
		SetColor(1.f, 0.f, 0.f, 0.5f);
		FillCircle(g_ArrMouseClicks[idx], radiusClickPoints);
	}
}

void InitRotatingPentagrams()
{
	float minAngluarSpeed{0.2f};
	float maxAngluarSpeed{1.1f};
	for (int idx = 0; idx < g_NrRotatingPentagrams; idx++)
	{
		g_ArrAngularSpeed[idx].angle = 0.f;
		g_ArrAngularSpeed[idx].speed = (rand() % int((maxAngluarSpeed - minAngluarSpeed) * 10.f)) / 10.f + minAngluarSpeed;
	}

}
void DrawRotatingPentagrams()
{
	Point2f pos{ 400.f, 200.f };
	float radius{ 80.f };

	SetColor(0.f, 1.f, 0.f);
	for (int idx = 0; idx < g_NrRotatingPentagrams; idx++)
	{
		DrawPentagram(pos, radius, g_ArrAngularSpeed[idx].angle);

	}
}
void DrawPentagram(const Point2f& centerPos, float radius, float angle)
{
	Point2f point1(centerPos.x + radius * cosf(0 / g_Pi * 2 + angle), centerPos.y + radius * sinf(0 / g_Pi * 2 + angle));
	Point2f point2(centerPos.x + radius * cosf(2 / g_Pi * 2 + angle), centerPos.y + radius * sinf(2 / g_Pi * 2 + angle));
	Point2f point3(centerPos.x + radius * cosf(4 / g_Pi * 2 + angle), centerPos.y + radius * sinf(4 / g_Pi * 2 + angle));
	Point2f point4(centerPos.x + radius * cosf(6 / g_Pi * 2 + angle), centerPos.y + radius * sinf(6 / g_Pi * 2 + angle));
	Point2f point5(centerPos.x + radius * cosf(8 / g_Pi * 2 + angle), centerPos.y + radius * sinf(8 / g_Pi * 2 + angle));

	DrawLine(point1, point3);
	DrawLine(point3, point5);
	DrawLine(point5, point2);
	DrawLine(point2, point4);
	DrawLine(point4, point1);
}
void UpdateRotatingPentagrams(float elapsedSec)
{
	for (int idx = 0; idx < g_NrRotatingPentagrams; idx++)
	{
		g_ArrAngularSpeed[idx].angle = g_ArrAngularSpeed[idx].angle + g_ArrAngularSpeed[idx].speed * elapsedSec;
	}
}

void InitRandStats()
{
	bool loaded{};
	for (int idx = 0; idx < g_SizeArrStatsRand; idx++)
	{
		loaded = TextureFromString(std::to_string(idx), "08_Resources/DIN-Light.otf", 21, Color4f(0.f, 1.f, 1.f, 1.f), g_ArrStatsRandTextures[idx]);
		if (loaded = false) std::cout << "texture couldn't load";
	}

}
void DrawRandStats()
{
	Point2f topLeft{ 10.f, g_WindowHeight - 10.f };
	float textureNumberWidht{ 30.f };
	for (int idx = 0; idx < g_SizeArrStatsRand; idx++)
	{
		Point2f pos{ topLeft.x, topLeft.y - g_ArrStatsRandTextures[idx].height * (idx + 1) };
		DrawTexture(g_ArrStatsRandTextures[idx], pos);
		DrawRect(pos.x + textureNumberWidht, pos.y, float(g_ArrStatsRand[idx]), g_ArrStatsRandTextures[idx].height);
	}
}
void UpdateRandStats()
{
	int idx{ rand() % g_SizeArrStatsRand };
	g_ArrStatsRand[idx]++;
}
void DeleteRandStats()
{
	for (int idx = 0; idx < g_SizeArrStatsRand; idx++)
	{
		DeleteTexture(g_ArrStatsRandTextures[idx]);
	}
}

void DrawMousePoints()
{
	for (int idx = 0; idx < g_SizeArrTraceCircles; idx++)
	{
		SetColor(0.f, 0.f, 1.f, float(g_ArrTraceCircles[idx].age) / float(g_MaxAgeCircles));
		FillCircle(g_ArrTraceCircles[idx].pos, float(g_ArrTraceCircles[idx].age / g_CircleShrinkSpeed));
	}
}
void UpdateMousePoints()
{
	for (int idx = 0; idx < g_SizeArrTraceCircles; idx++)
	{
		if (g_ArrTraceCircles[idx].age > 0) g_ArrTraceCircles[idx].age--;
	}
	g_CoolDown--;
}
void AddMousePos(g_TraceCircles* pTraceCircles, int size, const Point2f& newPos)
{

	for (int idx = 0; idx < size; idx++)
	{

		if (pTraceCircles[idx].age <= 0 && g_CoolDown <= 0)
		{
			pTraceCircles[idx].pos = newPos;
			pTraceCircles[idx].age = g_MaxAgeCircles;
			g_CoolDown = g_MaxCoolDown;
			return;
		}
	}
}

void DrawClickGrid()
{
	for (int idx = 0; idx < g_SizeArrClickGrid; idx++)
	{
		if (g_ArrClickGrid[idx])
		{
			SetColor(1.f, 0.5f, 0.2f, 1.f);
		}
		else
		{
			SetColor(0.5f, 0.5f, 0.5f, 1.f);
		}

		const int row{ int(idx / g_NrHorizontalCells) };
		const int column{ idx%g_NrHorizontalCells };
		FillRect(g_LeftBottemGrid.x + g_SizeCellClickGrid * column, g_LeftBottemGrid.y + g_SizeCellClickGrid * row, g_SizeCellClickGrid, g_SizeCellClickGrid);
		SetColor(1.f, 1.f, 1.f, 1.f);
		DrawRect(g_LeftBottemGrid.x + g_SizeCellClickGrid * column, g_LeftBottemGrid.y + g_SizeCellClickGrid * row, g_SizeCellClickGrid, g_SizeCellClickGrid);
	}
}
void ToggleCell(bool* pBools, int size, const Point2f& clickPoint)
{
	if (IsPointInRect(g_LeftBottemGrid.x, g_LeftBottemGrid.y, g_NrHorizontalCells * g_SizeCellClickGrid, g_NrVerticalCells * g_SizeCellClickGrid, clickPoint))
	{
		const int column{ int(clickPoint.x / g_SizeCellClickGrid) };
		const int row{ int(clickPoint.y / g_SizeCellClickGrid) };
		const int idx{ row * g_NrHorizontalCells + column };
		g_ArrClickGrid[idx] = !g_ArrClickGrid[idx];
	}
}
void InitClickGrid() 
{
	for (int idx = 0; idx < g_SizeArrClickGrid; idx++)
	{
		g_ArrClickGrid[idx] = false;
	}
}
#pragma endregion ownDefinitions