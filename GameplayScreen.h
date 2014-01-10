#pragma once

#include"GameScreen.h"
#include"Player.h"

class GameplayScreen : public GameScreen
{
private: 
	Player player;
public:
	GameplayScreen(void);
	~GameplayScreen(void);

	void LoadContent(); 
	void UnloadContent(); 
	void Update(ALLEGRO_EVENT ev); 
	void Draw(ALLEGRO_DISPLAY *display);
};

