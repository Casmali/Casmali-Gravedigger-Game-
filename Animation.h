#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <string>
#include "InputManager.h"

class Animation
{
public:
	Animation(void);
	~Animation(void);

	virtual void LoadContent(ALLEGRO_BITMAP *image,std::string text, std::pair<float, float> position);
	virtual void UnloadContent();
	virtual void Update(InputManager input);
	void Draw(ALLEGRO_DISPLAY *display);

	virtual void SetAlpha(float value);

	float GetAlpha();
	bool GetIsActive();
	
	void SetIsActive(bool value);

protected:
	ALLEGRO_BITMAP *image, *sourceRect;
	std::string text;
	ALLEGRO_FONT *font;
	std::pair<float,float> position;
	float alpha;
	bool isActive;
};

