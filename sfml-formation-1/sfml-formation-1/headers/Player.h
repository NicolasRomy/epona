#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture* texture, float SwitchTime, float speed, int column);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);




private:
	sf::Sprite body;
	Animation animation;
	int row;
	float speed;
	int column;
	bool IsMoving;

};

