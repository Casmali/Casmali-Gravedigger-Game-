#include "GameplayScreen.h"


GameplayScreen::GameplayScreen(void)
{
}


GameplayScreen::~GameplayScreen(void)
{
}

void GameplayScreen::LoadContent()
{
	player.LoadContent();
}

void GameplayScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	player.UnloadContent();
}

void GameplayScreen::Update(ALLEGRO_EVENT ev)
{
	player.Update(ev, input);
}

void GameplayScreen::Draw(ALLEGRO_DISPLAY *display)
{
	player.Draw(display);
}