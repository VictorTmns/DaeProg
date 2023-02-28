#pragma once
#include "BaseGame.h"
#include <vector>
class Card;
class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:
	std::vector<int> m_Numbers{};
	std::vector<Card*> m_pVectorCards{};

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;


	void PrintVector(const std::vector<int>& vect);

	void Swap(std::vector<Card*>& m_pCards, int idx1, int idx2);
	void InitCards();
	void DrawCards() const;
	void ShuffleCards(std::vector<Card*>& m_pCards, const int nrShuffles);
	void CleanupCards();

};