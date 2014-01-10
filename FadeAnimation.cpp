#include "FadeAnimation.h"


FadeAnimation::FadeAnimation(void)
{
}


FadeAnimation::~FadeAnimation(void)
{
}

void FadeAnimation::LoadContent(ALLEGRO_BITMAP *image,std::string text, std::pair<float, float> position)
{
	Animation::LoadContent(image, text, position); 
	fadeSpeed = 5.0f;
	increase = false;
}

void FadeAnimation::UnloadContent()
{
	Animation::UnloadContent(); 
	fadeSpeed = NULL;
}

void FadeAnimation::Update(InputManager inp)
{
	if(isActive)
	{
		if(!increase)
			alpha -= fadeSpeed;
		else
			alpha += fadeSpeed;

		if(alpha <= 0)
		{
			alpha = 0;
			increase = true;
		}
		else if(alpha >= 255)
		{
			alpha = 255;
			increase = false;
		}
	}
	else
		alpha = 255;
}

void FadeAnimation::SetAlpha(int value)
{
	alpha = value;
	if(alpha == 0)
		increase = true;
	else if(alpha == 255)
		increase = false;
} 
