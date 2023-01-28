#include "pch.h"
#include "Game.h"
#include "iostream"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_pDie1 = new Die{ Point2f{g_WindowWidth * 2 / 3, g_WindowHeight / 2}, 0.8f };
	g_pDie2 = new Die{ Point2f{g_WindowWidth * 1 / 3, g_WindowHeight / 2}, 0.8f };

	bool loaded{};
	loaded = TextureFromFile("Resources/temp_winner.png", g_TempWinnerTexture);
	if (loaded == false) std::cout << "couldn't load temp_winner texture";

	loaded = TextureFromFile("Resources/actual_winner.png", g_WinTexture);
	if (loaded == false) std::cout << "couldn't load actual_winner texture";

	loaded = TextureFromString("WE HAVE A WINNER!", "Resources/Minercraftory.ttf", 40, Color4f{ 1.f, 1.f, 1.f, 1.f }, g_WinTextTexture);
	if (loaded == false) std::cout << "couldn't load winner text texture";
}


void Draw()
{
	ClearBackground(1.f, 1.f, 1.f);

	// Put your own draw statements here
	DrawPlayers();
	switch (g_Gamestate)
	{
	case GameState::reset:
		break;
	case GameState::playing:
		g_pDie1->Draw();
		g_pDie2->Draw();
		break;
	case GameState::win:
		ShowWinTexture();
		break;
	default:
		break;
	}
}

void Update(float elapsedSec)
{
	switch (g_Gamestate)
	{
	case GameState::reset:
		g_CurrentPlayer = 0;
		g_Gamestate = GameState::playing;
		InitPlayers();
		break;
	case GameState::playing:
		g_DeltaTime += elapsedSec;
		if (g_DeltaTime >= 0.05f)
		{
			UpdateDice();
			g_DeltaTime -= 0.05f;
		}
		break;
	case GameState::win:
		break;
	default:
		break;
	}
}

void End()
{
	// free game resources here
	DeleteTexture(g_TempWinnerTexture);
	DeleteTexture(g_WinTexture);
	DeleteTexture(g_WinTextTexture);

	delete g_pDie1;
	g_pDie1 = nullptr;

	delete g_pDie2;
	g_pDie2 = nullptr;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (g_Gamestate)
	{
	case GameState::reset:
		break;
	case GameState::playing:
		break;
	case GameState::win:
		{
		switch (key)
		case SDLK_r:
			DeletePlayers();
			g_Gamestate = GameState::reset;
			break;
		}
		break;
	default:
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
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (g_Gamestate)
	{
	case GameState::reset:
		break;
	case GameState::playing:
		switch (e.button)
		{
		case SDL_BUTTON_LEFT:
		{
			const Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
			if (g_pDie1->CheckHit(mousePos) || g_pDie2->CheckHit(mousePos))
			{
				if (g_IsDiceRolling)
				{
					UpdatePlayerScore();
					g_IsDiceRolling = false;
				}
				else
				{
					g_IsDiceRolling = true;
				}
			}
			break;
		}
		}
		break;
	case GameState::win:
		break;
	default:
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void UpdateDice()
{
	if (g_IsDiceRolling) 
	{
		g_pDie1->Randomize(true);
		g_pDie2->Randomize(true);
	}
}
void InitPlayers()
{
	g_NrOfPlayers = (rand() % 4) + 4;
	g_pArrPlayers = new Player[g_NrOfPlayers]{};

	for (int idx = 0; idx < g_NrOfPlayers; idx++)
	{
		g_pArrPlayers[idx].color = Color4f{ float(rand() % 101) / 100.f, float(rand() % 101) / 100.f,float(rand() % 101) / 100.f , 1.f };
	}

}
void DeletePlayers()
{
	delete[] g_pArrPlayers;
	g_pArrPlayers = nullptr;
}
void DrawPlayers()
{
	int highScore{};
	for (int idx = 0; idx < g_NrOfPlayers; idx++)
	{
		SetColor(g_pArrPlayers[idx].color);
		FillRect(10.f + (g_TempWinnerTexture.width+8.f)*idx, 10.f, g_TempWinnerTexture.width, g_TempWinnerTexture.height);

		if (g_pArrPlayers[idx].score > highScore)
		{
			highScore = g_pArrPlayers[idx].score;
		}
	}

	for (int idx = 0; idx < g_NrOfPlayers; idx++)
	{
		if (g_pArrPlayers[idx].score == highScore && g_Gamestate == GameState::playing)
		{
			const Rectf destRect{ 10.f + (g_TempWinnerTexture.width + 8.f) * idx, 10.f, g_TempWinnerTexture.width, g_TempWinnerTexture.height };
			DrawTexture(g_TempWinnerTexture, destRect);
		}
	}
}
void UpdatePlayerScore()
{
	g_pDie1->Randomize(false);
	g_pDie2->Randomize(false);

	if (g_pDie1->GetDots() > g_pDie2->GetDots())
	{
		g_pArrPlayers[g_CurrentPlayer].score += g_pDie1->GetDots();
	}
	else
	{
		g_pArrPlayers[g_CurrentPlayer].score += g_pDie2->GetDots();
	}

	std::cout << "score player " + std::to_string(g_CurrentPlayer + 1) + ": " + std::to_string(g_pArrPlayers[g_CurrentPlayer].score) + "\n";

	if (g_pArrPlayers[g_CurrentPlayer].score >= 15)
	{
		g_Gamestate = GameState::win;
		std::cout << "====================!!WINNER!!====================\n";
	}
	else
	{
		g_CurrentPlayer++; 
		if (g_CurrentPlayer >= g_NrOfPlayers) g_CurrentPlayer = 0;
	}


}
void ShowWinTexture()
{
	const Rectf textBoundingBox{ g_WindowWidth / 2 - g_WinTextTexture.width / 2, 200.f , g_WinTextTexture.width, g_WinTextTexture.height };
	SetColor(0.5f, 0.5f, 0.5f, 0.5f);
	FillRect(textBoundingBox);
	DrawTexture(g_WinTextTexture, textBoundingBox);

	const Rectf destRect{ 10.f + (g_TempWinnerTexture.width + 8.f) * g_CurrentPlayer, 10.f, g_TempWinnerTexture.width, g_TempWinnerTexture.height };
	DrawTexture(g_WinTexture, destRect);
}
#pragma endregion ownDefinitions