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
	ClearBackground();

	DrawBomb();
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		g_MousePos = Point2f(float(e.x), float(g_WindowHeight - e.y));
		ProcessMouseClick();
		break;
	default:
		break;
	}
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
void ProcessMouseClick() {

	switch (g_BombElementState)
	{
	case BombState::neutral:
		if ((g_MousePos.x > g_BombPos.x && g_MousePos.x < g_BombPos.x + g_BombSize)
			&& (g_MousePos.y > g_BombPos.y && g_MousePos.y < g_BombPos.y + g_BombSize)) {
			g_BombElementState = BombState::explode;
		}
		break;
	default:
		break;
	}


}


void DrawBomb() {
	const Color4f black{ 0.f, 0.f, 0.f, 1.f };

	switch (g_BombElementState)
	{
	case BombState::neutral:
		SetColor(black);
		FillRect(g_BombPos, g_BombSize, g_BombSize);
		break;
	case BombState::explode:
		DrawExplosion();
		break;
	default:
		break;
	}
}

void DrawExplosion() {
	const Color4f transparantBlack{ 0.f, 0.f, 0.f, 0.5f };
	const Color4f transparantRed{ 1.f, 0.f, 0.f, 0.5f };

	g_ExplosionDuration += 4;

	SetColor(transparantBlack);
	FillRect(g_BombPos, g_BombSize, g_BombSize);

	SetColor(transparantRed);
	FillRect(g_BombPos.x + g_ExplosionDuration, g_BombPos.y + g_ExplosionDuration, g_BombSize, g_BombSize);
	FillRect(g_BombPos.x + g_ExplosionDuration, g_BombPos.y - g_ExplosionDuration, g_BombSize, g_BombSize);
	FillRect(g_BombPos.x - g_ExplosionDuration, g_BombPos.y + g_ExplosionDuration, g_BombSize, g_BombSize);
	FillRect(g_BombPos.x - g_ExplosionDuration, g_BombPos.y - g_ExplosionDuration, g_BombSize, g_BombSize);

	if (g_BombPos.x + g_ExplosionDuration > g_WindowWidth) {
		ResetExplosion();
	}

}

void ResetExplosion() {
	g_BombElementState = BombState::neutral;
	g_ExplosionDuration = 0;

}
#pragma endregion ownDefinitions