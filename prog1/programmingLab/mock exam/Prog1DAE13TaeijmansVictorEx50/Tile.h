#pragma once
#include "pch.h"
#include "utils.h"

class Tile 
{
private:
	Rectf m_BoundingBox;
	utils::Texture m_TileTextue;
	int m_NrOfAnimals;
	int m_CurrentAnimal;
	bool m_IsActive;
	bool m_IsChangeble;
public:
	Tile(const Rectf& boundingBox, const std::string& imagePath, const int numberOfAnimals);


	void Draw();

	//setters
	void CheckActivation(const Point2f& mousePos);
	bool CheckHit(const Point2f& mousePos);

	void Deactivate();
	void Shuffle();
	//getters
	int GetCurrentAnimal();

};