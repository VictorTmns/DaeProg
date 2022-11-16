#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_Bullet1Player0 = Bullet{ Point2f{0.f, 0.f}, 0, Color4f(0.f, 0.f, 0.f, 1.f), false, 0 };
	g_Bullet1Player1 = Bullet{ Point2f{0.f, 0.f}, 0, Color4f(0.f, 0.f, 0.f, 1.f), false, 0 };
	g_Bullet1Player2 = Bullet{ Point2f{0.f, 0.f}, 0, Color4f(0.f, 0.f, 0.f, 1.f), false, 0 };
	g_Bullet1Player3 = Bullet{ Point2f{0.f, 0.f}, 0, Color4f(0.f, 0.f, 0.f, 1.f), false, 0 };

	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawPlayer1();
	UpdatePlayer1();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
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
	switch (key)
	{
	case SDLK_q:
		std::cout << "'a' key pressed\n";
		g_Player1.dirDegrees += g_TurningSpeedJets;
		break;
	case SDLK_d:
		std::cout << "'d' key pressed\n";
		g_Player1.dirDegrees -= g_TurningSpeedJets;
		break;
	case SDLK_s:
		std::cout << "'s' key pressed\n";

		break;
	}
	std::cout << g_Player1.dirDegrees;
}

void OnKeyUpEvent(SDL_Keycode key)
{
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
void DrawPlayer1() {
	SetColor(g_Player1.color);
	FillRect(g_Player1.pos, g_SizeJets, g_SizeJets);



	const float pi{ 3.1415f };

	const float dirRadans{ (g_Player1.dirDegrees / 360.f) * 2 * pi };
	const float xMovement{ cos(dirRadans) };
	const float yMovement{ sin(dirRadans) };

	DrawLine(g_Player1.pos.x + g_SizeJets / 2, g_Player1.pos.y + g_SizeJets / 2 , g_Player1.pos.x + g_SizeJets / 2 + xMovement * 40, g_Player1.pos.y + g_SizeJets / 2 + yMovement * 40);

}

void UpdatePlayer1() {
	const float pi{ 3.1415f };

	if (g_Player1.dirDegrees >= 360) {
		g_Player1.dirDegrees -= 360;
	}
	else if (g_Player1.dirDegrees <= 0) {
		g_Player1.dirDegrees += 360;
	}

	const float dirRadians{ (g_Player1.dirDegrees / 360.f) * 2* pi };
	const float xMovement{ cos(dirRadians) };
	const float yMovement{ sin(dirRadians) };

	g_Player1.pos.x += g_SpeedJets * xMovement;
	g_Player1.pos.y += g_SpeedJets * yMovement;


}
#pragma endregion ownDefinitions