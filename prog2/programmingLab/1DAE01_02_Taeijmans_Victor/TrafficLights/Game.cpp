#include "pch.h"
#include "Game.h"
#include "TrafficLight.h"

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
	InitTrafficLights();
}

void Game::Cleanup( )
{
	DeleteTrafficLights();
}

void Game::Update( float elapsedSec )
{
	UpdateTrafficLights(elapsedSec);
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
	DrawTrafficLights();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
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

	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		CheckHitsTrafficLights(Point2f{ float(e.x), float(e.y) });
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::InitTrafficLights()
{
	for (int i = 0; i < m_ColumnsTrafficLights; i++)
	{
		for (size_t j = 0; j < m_RowTrafficLights; j++)
		{
			const Rectf destRect
			{
				((GetViewPort().width - m_Margin) / m_ColumnsTrafficLights) * i + m_Margin,
				((GetViewPort().height - m_Margin) / m_RowTrafficLights) * j + m_Margin,
				(GetViewPort().width - (m_Margin * m_ColumnsTrafficLights+1)) / m_ColumnsTrafficLights,
				(GetViewPort().height - (m_Margin * m_RowTrafficLights +1)) / m_RowTrafficLights,
			};
			m_TrafficLights.push_back(new TrafficLight{destRect});
		}
	}
}
void Game::DrawTrafficLights() const
{
	for (TrafficLight* p_TrafficLight : m_TrafficLights)
	{
		p_TrafficLight->Draw();
	}
}
void Game::UpdateTrafficLights(float elapsedSed)
{
	for (TrafficLight* p_TrafficLight : m_TrafficLights)
	{
		p_TrafficLight->Update(elapsedSed);
	}
}
void Game::DeleteTrafficLights()
{
	for (int idx = 0; idx < m_TrafficLights.size(); idx++)
	{
		delete m_TrafficLights[idx];
		m_TrafficLights[idx] = nullptr;
	}
}
void Game::CheckHitsTrafficLights(const Point2f& mousePos)
{
	for (TrafficLight* p_TrafficLight : m_TrafficLights)
	{
		p_TrafficLight->DoHitTest(mousePos);
	}
}
