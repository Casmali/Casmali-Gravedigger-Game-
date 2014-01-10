#include "Player.h"


Player::Player(void)
{
}


Player::~Player(void)
{
}

void Player::LoadContent()
{
	fileManager.LoadContent("Load/Player.txt", attributes, contents);
	for(int i = 0; i < attributes.size(); i++)
	{
		for(int j = 0; j < attributes[i].size(); j++)
		{
			if(attributes[i][j] == "Image")
				playerImage = al_load_bitmap(contents[i][j].c_str());
			else if(attributes[i][j] == "Position")
			{
				std::stringstream str;
				float position[2];
				str << contents[i][j];

				std::string value;

				int counter = 0;
				while(std::getline(str, value, ','))
				{
					position[counter]  = atof(value.c_str());
					counter++;
				}

				this->position.first = position[0]; 
				this->position.second = position[1];
			}
		}
	}
}

void Player::UnloadContent()
{
	attributes.clear(); 
	contents.clear();
	al_destroy_bitmap(playerImage);
}

void Player::Update(ALLEGRO_EVENT ev, InputManager input)
{

}

void Player::Draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(playerImage, position.first, position.second, NULL);
}