#pragma once

#include <iostream>
#include <string>
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "GameplayScreen.h"
#include "FadeAnimation.h"

//Allegro Inits
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <map>

#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager
{
private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	//for testing
	std::string text;
	GameScreen *currentScreen, *newScreen;

	ALLEGRO_BITMAP *transitionImage;

	FadeAnimation transition;

	void Transition();

	bool startTransition;

	std::map<std::string, GameScreen*> screenDirectory;

public:
	~ScreenManager();
	static ScreenManager &GetInstance();

	void AddScreen(std::string newScreen);

	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

