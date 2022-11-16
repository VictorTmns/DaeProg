#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawDvdLogo();
}

void Update(float elapsedSec)
{
	g_NrFrames++;

	float accesibleWidth{g_WindowWidth-g_Width};
	float accesibleHeight{g_WindowHeight-g_Height};

	int horizontalDirection{ ((g_NrFrames % int(accesibleWidth * 2)) / int(accesibleWidth)) * 2 - 1 };
	int verticalDirection{ ((g_NrFrames % int(accesibleHeight * 2)) / int(accesibleHeight)) * 2 - 1 };

	g_XPos += horizontalDirection;
	g_YPos += verticalDirection;
}

void End()
{
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
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawDvdLogo() {
	const float pi{ 3.1415f };
	const Color4f purple(0.29411f, 0.f, 0.5098f, 1.f);
	const Color4f black(0.f, 0.f, 0.f, 1.f);

	SetColor(purple);
	FillRect(g_XPos, g_YPos, g_Width, g_Height);

	SetColor(black);
	const float d1Width{ g_Width / 4.f };
	const float d1Height{ g_Width*  3.f/ 8.f };
	const float d1Bottom{ g_YPos + 14.f / 32.f * g_Height };
	const float d1Left{ g_XPos + 1.f / 8.f * g_Width };

	FillRect(d1Left, d1Bottom, d1Width/3, d1Height);
	FillArc(d1Left + d1Width / 3, d1Bottom + d1Height / 2, d1Width * 2 / 3, d1Height / 2, -pi * 1 / 2, pi / 2);
	SetColor(purple);
	FillArc(d1Left + d1Width / 3, d1Bottom + d1Height / 2, d1Width * 2/6 , d1Height * 1 / 3, -pi * 1 / 2, pi / 2);


	SetColor(black);
	const float vWidth{ g_Width / 4.f };
	const float vHeight{ g_Width*  3.f/ 8.f };
	const float vBottom{ g_YPos + 14.f / 32.f * g_Height };
	const float vLeft{ g_XPos + 3.f / 8.f * g_Width };

	const Point2f bigTriangleLeft(vLeft, vHeight + vBottom);
	const Point2f bigTriangleRight(vLeft + vWidth, vHeight + vBottom);
	const Point2f bigTriangleBottom(vLeft+ vWidth/2, vBottom);

	SetColor(black);
	FillTriangle(bigTriangleLeft, bigTriangleBottom, bigTriangleRight);

	const Point2f smallTriangleLeft(vLeft + vWidth/4, vHeight + vBottom);
	const Point2f smallTriangleRight(vLeft + vWidth - vWidth/4, vHeight + vBottom);
	const Point2f smallTriangleBottom(vLeft + vWidth / 2, vBottom+ vHeight* 3/8);

	SetColor(purple);
	FillTriangle(smallTriangleLeft, smallTriangleBottom, smallTriangleRight);


	SetColor(black);
	const float d2Width{ g_Width / 4.f };
	const float d2Height{ g_Width * 3.f / 8.f };
	const float d2Bottom{ g_YPos + 14.f / 32.f * g_Height };
	const float d2Left{ g_XPos + 21.f / 32.f * g_Width };

	FillRect(d2Left, d2Bottom, d2Width / 3.f, d2Height);
	FillArc(d2Left + d2Width / 3.f, d2Bottom + d2Height / 2, d2Width * 2 / 3, d2Height / 2, -pi * 1 / 2, pi / 2);
	SetColor(purple);
	FillArc(d2Left + d2Width / 3, d2Bottom + d2Height / 2, d2Width * 2 / 6, d2Height * 1 / 3, -pi * 1 / 2, pi / 2);


	SetColor(black);
	const float cdWidth{ g_Width * 3.f / 4.f };
	const float cdHeight{ g_Width * 2.f / 8.f };
	const float cdBottom{ g_YPos + 1.f / 8.f * g_Height };
	const float cdLeft{ g_XPos + 1.f / 8.f * g_Width };

	SetColor(black);
	FillEllipse(cdLeft + cdWidth / 2, cdBottom + cdHeight / 2, cdWidth / 2, cdHeight / 2);

	SetColor(purple);
	FillEllipse(cdLeft + cdWidth / 2, cdBottom + cdHeight / 2, cdWidth / 6, cdHeight / 6);

}
#pragma endregion ownDefinitions