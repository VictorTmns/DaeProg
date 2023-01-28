#pragma once
using namespace utils;
#include "Fraction.h"
#include "Light.h"
#include "DaeEllipse.h"
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "GraphicClasses - Taeijmans, Victor - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Fraction *pFraction{ new Fraction{3, 5} };


Light* pLight1{ new Light{Rectf{10.f, 100.f, 25.f, 30.f}, Color4f{1.f, 0.25f, 0.f, 1.f} } };
Light* pLight2{ new Light{Rectf{40.f, 100.f, 55.f, 30.f}, Color4f{0.f, 0.75f, 1.f, 1.f} } };
Light* pLight3{ new Light{Rectf{10.f, 145.f, 40.f, 30.f}, Color4f{1.f, 0.25f, 1.f, 1.f} } };
Light* pLight4{ new Light{Rectf{55.f, 145.f, 40.f, 30.f}, Color4f{0.2f, 0.9f, 0.7f, 1.f} } };
Light* pLight5{ new Light{Rectf{10.f, 190.f, 60.f, 30.f}, Color4f{0.4f, 0.1f, 0.9f, 1.f} } };
Light* pLight6{ new Light{Rectf{75.f, 190.f, 20.f, 30.f}, Color4f{0.f, 0.5f, 0.4f, 1.f} } };

int g_NumberOfLightsOn{};

DaeEllipse* pEllipse1{ new DaeEllipse{Point2f{ 200.f, 50.f}, 40.f, 30.f, Color4f{0.5f, 0.5f, 0.f, 1.f} } };
// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
