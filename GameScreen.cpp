#include "GameScreen.h"


GameScreen::GameScreen(void)
{
}


GameScreen::~GameScreen(void)
{
}

void GameScreen::LoadContent()
{
}

void GameScreen::UnloadContent()
{
	attributes.clear(); 
	contents.clear(); 
}

void GameScreen::Update(ALLEGRO_EVENT ev)
{
}

void GameScreen::Draw(ALLEGRO_DISPLAY *display)
{
}

InputManager GameScreen::GetInput()
{
	return input;
}