#pragma once


#include "ScreenManager.h"
//#include <vector>
//#include "Animation.h"
//#include "FadeAnimation.h"
#include "FileManager.h"
#include <sstream>
//#include <string>
//#include "TitleScreen.h"

class Animation;

class MenuManager
{
private:
	std::vector<std::string> menuItems;
	std::vector<ALLEGRO_BITMAP*> menuImages;
	std::vector<std::string> menuLinks;

	std::vector<std::vector<Animation*> > animation;

	int itemNumber;

	FileManager fileManager;

	std::vector<std::vector<std::string> > attributes;
	std::vector<std::vector<std::string> > contents;

	std::vector<std::string> animationTypes;

	std::pair<float, float> position;
	int axis;
	std::string align;
	ALLEGRO_FONT *font;

	void SetMenuItems();
	void SetAnimations();

	std::vector<Animation*> tempAnimation;
public:
	MenuManager();
	~MenuManager();

	void LoadContent(std::string id);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev, InputManager &input);
	void Draw(ALLEGRO_DISPLAY *display);
};

