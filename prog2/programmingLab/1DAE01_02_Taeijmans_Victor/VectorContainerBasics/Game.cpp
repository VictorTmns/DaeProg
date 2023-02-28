#include "pch.h"
#include "Game.h"
#include <iostream>
#include "Card.h"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	InitCards();
}

void Game::Cleanup( )
{
	CleanupCards();
}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
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

void Game::Draw( ) const
{
	ClearBackground( );
	DrawCards();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	switch ( e.keysym.sym )
	{
	case SDLK_EQUALS:
		m_Numbers.push_back(rand() % 31);
		PrintVector(m_Numbers);
		break;
	case SDLK_MINUS:
		if (m_Numbers.size() > 0)
		{
			m_Numbers.pop_back();
		}
		PrintVector(m_Numbers);
		break;
	case SDLK_UP:
		//for (int i = 0; i < m_Numbers.size(); i++)
		//{
		//	m_Numbers[i]++;
		//}

		for (int& number : m_Numbers)
		{
			number++;
		}
		PrintVector(m_Numbers);
		
		break;
	case SDLK_DOWN:
		//for (int i = 0; i < m_Numbers.size(); i++)
		//{
		//	m_Numbers[i]--;
		//}

		for (int& number : m_Numbers)
		{
			number--;
		}
		PrintVector(m_Numbers);
		break;
	case SDLK_s:
		ShuffleCards(m_pVectorCards, 50);
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::PrintVector(const std::vector<int>& vect)
{
	//for (int i = 0; i < vect.size(); i++)
	//{
	//	std::cout << vect[i] << " ";
	//}
	for (int number : m_Numbers)
	{
		std::cout << number << " ";
	}

	std::cout << std::endl;
}

void Game::Swap(std::vector<Card*>& m_pCards, int idx1, int idx2)
{
	Card* holder{ m_pCards[idx1] };
	m_pCards[idx1] = m_pCards[idx2];
	m_pCards[idx2] = holder;
}
void Game::InitCards()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			m_pVectorCards.push_back(new Card(Card::Suit(i + 1), j + 1));
		}
	}
}
void Game::DrawCards() const
{
	for (int idx = 0; idx < m_pVectorCards.size(); idx++)
	{
		const Rectf boundingBox{
			(m_pVectorCards[idx]->GetWidth() / 4) * (idx % 13),
			(m_pVectorCards[idx]->GetHeight() / 2) * int(idx / 13),
			m_pVectorCards[idx]->GetWidth()/2 ,
			m_pVectorCards[idx]->GetHeight()/2
		};
		m_pVectorCards[idx]->Draw(boundingBox);
	}

}
void Game::ShuffleCards(std::vector<Card*>& m_pCards, const int nrShuffles)
{
	for (int i = 0; i < nrShuffles; i++)
	{
		const int idx1{ int(rand() % m_pCards.size()) };
		int idx2{};
		do
		{
			idx2 = int(rand() % m_pCards.size());
		} while (idx1 == idx2);
		Swap(m_pCards, idx1, idx2);
	}
}
void Game::CleanupCards()
{
	for (int idx = 0; idx < m_pVectorCards.size(); idx++)
	{
		delete m_pVectorCards[idx];
		m_pVectorCards[idx] = nullptr;
	}
}