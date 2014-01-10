#pragma once

#include<allegro5\allegro.h>
#include"InputManager.h"
#include"FileManager.h"
#include<vector>
#include<string>

class Player
{
private: 
	ALLEGRO_BITMAP *playerImage;
	std::pair<float, float> position;
	float moveSpeed;
	FileManager fileManager;

	std::vector<std::vector<std::string>> attributes; 
	std::vector<std::vector<std::string>> contents;

public:
	Player(void);
	~Player(void);

	void LoadContent(); 
	void UnloadContent(); 
	void Update(ALLEGRO_EVENT ev, InputManager input);
	void Draw(ALLEGRO_DISPLAY *display);
};

