#pragma once
#include "Animation.h"

class FadeAnimation : public Animation
{
public:
	FadeAnimation(void);
	~FadeAnimation(void);

	void LoadContent(ALLEGRO_BITMAP *image,std::string text, std::pair<float, float> position); 
	void UnloadContent(); 
	void Update(InputManager input); 
	
	void SetAlpha(int value);

private:
	float fadeSpeed;
	bool increase;
};

