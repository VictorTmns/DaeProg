#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_PacmanPos.x = g_WindowWidth / 2;
	g_PacmanPos.y = g_WindowHeight / 2;
}

void Draw()
{
	ClearBackground(0.f,0.f,0.f);

	// Put your own draw statements here
	DrawPacman();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdatePacman();

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
	switch (key)
	{
	case SDLK_LEFT:
		//std::cout << "Left arrow key released\n";
		g_Dir = PacmanDirection::left;
		break;
	case SDLK_RIGHT:
		//std::cout << "Right arrow key released\n";
		g_Dir = PacmanDirection::right;
		break;
	case SDLK_UP:
		//std::cout << "Left arrow key released\n";
		g_Dir = PacmanDirection::up;
		break;
	case SDLK_DOWN:
		//std::cout << "Right arrow key released\n";
		g_Dir = PacmanDirection::down;
		break;
	case SDLK_1:
	case SDLK_KP_1:
		//std::cout << "Key 1 released\n";
		break;
	}
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
void DrawPacman()
{
	SetColor(1.f, 0.87f, 0.f);

	const float pi{ 3.1415f };
	const float mouthSize{ pi / 2.5f }; // angle size of mouth opening
	const float pacmanSize{ 2 * pi - mouthSize }; // angle size of pacman

	float startAngle{ 0.f }; // looks towards the right
	
	switch (g_Dir)
	{
	case PacmanDirection::down:
		startAngle = 3 * pi / 2;
		break;
	case PacmanDirection::left:
		startAngle = pi;
		break;
		break;
	case PacmanDirection::up:
		startAngle = pi / 2;
		break;
	case PacmanDirection::neutral:
	case PacmanDirection::right:
	default:
		startAngle = 0.f;
	}

	startAngle += mouthSize / 2;

	if (g_MouthIsOpen == true)
	{
	FillArc(g_PacmanPos, g_PacmanRadius, g_PacmanRadius, startAngle, startAngle + pacmanSize);
	}
	else 
	{
		FillEllipse(g_PacmanPos, g_PacmanRadius, g_PacmanRadius);
	}
}

void UpdatePacman()
{
	const int speed{ 2 };
	switch (g_Dir)
	{
	case PacmanDirection::down:
		g_PacmanPos.y -= speed;
		break;
	case PacmanDirection::up:
		g_PacmanPos.y += speed;
		break;
	case PacmanDirection::right:
		g_PacmanPos.x += speed;
		break;
	case PacmanDirection::left:
		g_PacmanPos.x -= speed;
		break;
	};

	const int maxWait{ 10 };
	if (g_Dir != PacmanDirection::neutral)
	{
		++g_Counter;
		if (g_Counter >= maxWait) {
			g_MouthIsOpen = !g_MouthIsOpen;
			g_Counter = 0;
		}
	}
}

#pragma endregion ownDefinitions