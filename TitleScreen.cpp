#include "TitleScreen.h"
#include "MenuManager.h"

MenuManager menu;

TitleScreen::TitleScreen(void)
{
}

TitleScreen::~TitleScreen(void)
{
}

void TitleScreen::LoadContent()
{
	font = al_load_font("arial.ttf", 30, NULL);
	menu.LoadContent("Title");
}

void TitleScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	al_destroy_font(font);
	menu.UnloadContent();
}

void TitleScreen::Update(ALLEGRO_EVENT ev)
{
	menu.Update(ev, input);
}

void TitleScreen::Draw(ALLEGRO_DISPLAY *display)
{
	//al_draw_text(font,al_map_rgb(255,0,0),100,100,NULL,"TitleScreen");
	menu.Draw(display);
}