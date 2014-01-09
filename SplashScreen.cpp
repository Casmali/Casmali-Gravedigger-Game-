#include "SplashScreen.h"

SplashScreen::SplashScreen(void)
{
}


SplashScreen::~SplashScreen(void)
{
}

void SplashScreen::LoadContent()
{
	font = al_load_font("arial.ttf", 30, NULL);
	fileManager.LoadContent("file1.txt",attributes,contents);

	for(int i = 0; i < attributes.size(); i++)
	{
		for(int j = 0; j < attributes[i].size(); j++)
		{
			if(attributes[i][j] == "Image")
			{
				std::pair<float, float> position(0, 0);
				images.push_back(al_load_bitmap(contents[i][j].c_str()));
				fade.push_back(new FadeAnimation);
				fade[fade.size()-1]->LoadContent(images[fade.size()-1], "",position);
				fade[fade.size()-1]->SetIsActive(true);
			}
		}
	}
}

void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	al_destroy_font(font);
	for(int i = 0; i < fade.size(); i++)
	{
		al_destroy_bitmap(images[i]);
		delete fade[i];
	}
	fade.clear();
}

void SplashScreen::Update(ALLEGRO_EVENT ev)
{
	if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().AddScreen("TitleScreen");
}

void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
	al_draw_text(font,al_map_rgb(0,0,255),100,100,NULL,"SplashScreen");
}