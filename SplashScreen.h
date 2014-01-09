#pragma once

#include "ScreenManager.h"
#include "InputManager.h"
#include "FileManager.h"
#include "FadeAnimation.h"
//#include "MenuManager.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

class SplashScreen : public GameScreen
{
private:
	ALLEGRO_FONT *font;

	std::vector<ALLEGRO_BITMAP*> images;
	std::vector<FadeAnimation*> fade;
public:
	SplashScreen(void);
	~SplashScreen(void);

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

