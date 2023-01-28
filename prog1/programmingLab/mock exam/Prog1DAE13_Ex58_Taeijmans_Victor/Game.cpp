#include "pch.h"
#include "Game.h"
#include "iostream"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	bool loaded{};

	loaded = TextureFromFile("Resources/street.png", g_BackgroundTexture );
	if (loaded == false) std::cout << "failed to load background texture";

	loaded = TextureFromString("Pause", "Resources/consola.ttf", 40, Color4f{ 1.f, 1.f, 1.f, 0.f }, g_PauseTexture);
	if (loaded == false) std::cout << "failed to load background texture";

	loaded = TextureFromString("The chicken survived!", "Resources/consola.ttf", 40, Color4f{ 1.f, 1.f, 1.f, 0.f }, g_WinTexture);
	if (loaded == false) std::cout << "failed to load background texture";

	loaded = TextureFromString("The chicken died!", "Resources/consola.ttf", 40, Color4f{ 1.f, 1.f, 1.f, 0.f }, g_LoseTexture);
	if (loaded == false) std::cout << "failed to load background texture";

	loaded = TextureFromFile("Resources/chicken.bmp", g_chicken.chickenTexture);
	if (loaded == false) std::cout << "failed to load background texture";

	g_chicken.speed = 100.f;
	g_chicken.height = g_chicken.chickenTexture.height;
	g_chicken.width = g_chicken.chickenTexture.width / 3 - 1.f;

	for (int idx = 0; idx < g_NrOfVehicles; idx++)
	{
		g_ArrVehicles[idx] = new Vehicle{ idx };
	}
}

void Draw()
{
	ClearBackground();

	DrawTexture(g_BackgroundTexture, Point2f(0.f, 0.f));

	DrawChicken();
	DrawVehicles();

	Rectf textBoundingBox{};
	switch (g_Gamestat)
	{
	case GameState::reset:
		break;
	case GameState::lose:
		DrawTextTexture(g_LoseTexture);
		break;
	case GameState::win:
		DrawTextTexture(g_WinTexture);
		break;
	case GameState::pause:
		DrawTextTexture(g_PauseTexture);
		break;
	case GameState::play:
		break;
	default:
		break;
	}
	// Put your own draw statements here
	SetColor(1.f, 0.f, 0.f);
	FillCircle(g_chicken.pos, 4.f);
}

void Update(float elapsedSec)
{
	switch (g_Gamestat)
	{
	case GameState::reset:
		g_chicken.pos = Point2f{ g_WindowWidth / 2, g_WindowHeight - 20.f };
		ResetVehicles();
		g_Gamestat = GameState::play;
		break;
	case GameState::lose:
		UpdateVehicles(elapsedSec);
		break;
	case GameState::win:
		break;
	case GameState::pause:
		break;
	case GameState::play:
		MoveChicken(elapsedSec);
		UpdateVehicles(elapsedSec);
		CheckColisions();
		CheckWinCondition();
		break;
	default:
		break;
	}
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
	case SDLK_p:
		if (g_Gamestat == GameState::play)
		{
			g_Gamestat = GameState::pause;
		}
		else if(g_Gamestat == GameState::pause)
		{
			g_Gamestat = GameState::play;
		}
		break;
	case SDLK_r:
		g_Gamestat = GameState::reset;
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
void DrawTextTexture(const Texture& textTexture)
{
	const Rectf textBoundingBox{ g_WindowWidth / 2 - textTexture.width / 2, g_WindowHeight / 2 - textTexture.height / 2, textTexture.width, textTexture.height };

	SetColor(0.4f, 0.4f, 0.4f, 0.6f);

	FillRect(textBoundingBox);
	DrawTexture(textTexture, textBoundingBox);

}
void MoveChicken(float elapsedSec)
{
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );

	g_chicken.walkingDirection = Direction::down;
	if (pStates[SDL_SCANCODE_DOWN])
	{
		g_chicken.pos.y -= elapsedSec * g_chicken.speed;
	}
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		g_chicken.pos.x += elapsedSec * g_chicken.speed;
		g_chicken.walkingDirection = Direction::right;
	}
	if (pStates[SDL_SCANCODE_LEFT])
	{
		g_chicken.pos.x -= elapsedSec * g_chicken.speed;
		g_chicken.walkingDirection = Direction::left;
	}
}
void DrawChicken()
{
	const Rectf sourceRect{ g_chicken.width*int(g_chicken.walkingDirection), g_chicken.height, g_chicken.width, g_chicken.height};
	DrawTexture(g_chicken.chickenTexture, Point2f{ g_chicken.pos.x - g_chicken.width / 2, g_chicken.pos.y - g_chicken.height / 2 }, sourceRect);
}
void DrawVehicles()
{
	for (int idx = 0; idx < g_NrOfVehicles; idx++)
	{
		g_ArrVehicles[idx]->Draw();
	}
}
void UpdateVehicles(float elapsedSecs)
{
	for (int idx = 0; idx < g_NrOfVehicles; idx++)
	{
		g_ArrVehicles[idx]->Update(elapsedSecs, g_WindowWidth);
	}
}
void ResetVehicles()
{
	for (int idx = 0; idx < g_NrOfVehicles; idx++)
	{
		g_ArrVehicles[idx]->Reset();
	}
}
void CheckWinCondition()
{
	if (g_chicken.pos.y <=43.f)
	{
		g_Gamestat = GameState::win;
	}
}
void CheckColisions()
{
	for (int idx = 0; idx < g_NrOfVehicles; idx++)
	{

		if (g_ArrVehicles[idx]->IsIntersecting(g_chicken.pos))
		{
			g_Gamestat = GameState::lose;
		}
	}
}
#pragma endregion ownDefinitions