#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Sword
{
public:
	Sword(sf::Texture* texture, float SwitchTime, float speed, int column);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);




private:
	sf::Sprite sword;
	Animation animation;
	int row;
	float speed;
	int column;
	bool IsMoving;

};

