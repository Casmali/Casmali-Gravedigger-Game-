#include "Animation.h"


Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}

void Animation::LoadContent(ALLEGRO_BITMAP *image,std::string text, std::pair<float, float> position)
{
	this->image = image;
	this->text = text;
	this->position = position;

	alpha = 255;
	font = al_load_font("arial.ttf", 30, NULL);
	sourceRect = image;
	isActive = false;
}

void Animation::UnloadContent()
{
	al_destroy_font(font);
	alpha = NULL;
	position = std::pair<float, float>(0, 0);
}

void Animation::Update(InputManager input)
{
}

void Animation::Draw(ALLEGRO_DISPLAY *display)
{
	if(sourceRect != NULL)
		al_draw_tinted_bitmap(sourceRect,al_map_rgba(0,0,0,alpha),
		position.first,position.second,NULL);
	else if(image != NULL)
		al_draw_tinted_bitmap(image,al_map_rgba(0,0,0,alpha),
		position.first,position.second,NULL);

	if(text != "")
		al_draw_text(font,al_map_rgba(255,255,255,alpha),
		position.first,position.second,NULL,text.c_str());
}

void Animation::SetAlpha(float alpha)
{
	this->alpha = alpha;
}

float Animation::GetAlpha()
{
	return alpha;
}

bool Animation::GetIsActive()
{
	return isActive;
}

void Animation::SetIsActive(bool value)
{
	isActive = value;
}