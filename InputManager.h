#pragma once

#include <allegro5\allegro.h>
#include <allegro5\keyboard.h>
#include <vector>

class InputManager
{
private:
	ALLEGRO_KEYBOARD_STATE keystate;

public:
	InputManager(void);
	~InputManager(void);

	bool IsKeyPressed(ALLEGRO_EVENT ev, int key);
	bool IsKeyPressed(ALLEGRO_EVENT ev, std::vector<int> keys);

	bool IsKeyReleased(ALLEGRO_EVENT ev, int key);
	bool IsKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys);
};

