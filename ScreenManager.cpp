#include "ScreenManager.h"

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

ScreenManager::ScreenManager(void)
{
}


ScreenManager::~ScreenManager(void)
{
}

void ScreenManager::AddScreen(std::string screenName)
{
	transition.SetAlpha(0);
	startTransition = true;
	newScreen = screenDirectory[screenName];
	transition.SetIsActive(true);
}

void ScreenManager::Initialize()
{
	screenDirectory["SplashScreen"] = new SplashScreen(); 
	screenDirectory["TitleScreen"] = new TitleScreen();
	screenDirectory["GameplayScreen"] = new GameplayScreen();

	currentScreen = screenDirectory["SplashScreen"];
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
	transitionImage = al_load_bitmap("transitionImage.png");
	std::pair<float, float> position(0, 0);
	transition.LoadContent(transitionImage,"",position);
	startTransition = false;
}

void ScreenManager::UnloadContent()
{
	al_destroy_bitmap(transitionImage);
	transition.UnloadContent();
	currentScreen->UnloadContent();

	std::map<std::string, GameScreen*>::iterator tempIterator; 

	for(tempIterator = screenDirectory.begin(); tempIterator != screenDirectory.end();
		tempIterator++)
		delete tempIterator->second;

	screenDirectory.clear();
}

void ScreenManager::Update(ALLEGRO_EVENT ev)
{
	if(!startTransition)
		currentScreen->Update(ev);
	else 
		Transition();
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->Draw(display);
	if(startTransition)
		transition.Draw(display);
}

void ScreenManager::Transition()
{
	transition.Update(currentScreen->GetInput());
	if(transition.GetAlpha() >= 255)
	{
		transition.SetAlpha(255);
		currentScreen->UnloadContent();
		currentScreen = newScreen;
		currentScreen->LoadContent();
		al_rest(1.0);
	}
	else if(transition.GetAlpha() <= 0)
	{
		startTransition = false;
		transition.SetIsActive(false);
	}
}