/*#pragma once
#include <SFML/Graphics.hpp>
#include "headers/Animation.h"
#include <vector>
#include "Animation.cpp"

class HealthPotion
{
public:
	HealthPotion(sf::Texture* texture, float SwitchTime, int column);
;
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	
	sf::Sprite body;	
	Animation animation;
	bool IsMoving = true;
	int row = 0;
	int column = 0;

};

*/