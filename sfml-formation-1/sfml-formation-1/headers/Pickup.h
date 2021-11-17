#pragma once
#include <SFML/Graphics.hpp>
#include "headers/Animation.h"
#include "Player.h"
#include <vector>

class HealthPotion
{
public:
	HealthPotion(sf::Texture* texture, float SwitchTime, int column, int uvRectW, int uvRectH);
	void Update(float deltaTime, Player* player);
	void Draw(sf::RenderWindow& window);
	
	sf::Sprite body;	
	Animation animation;
	bool IsMoving = true;
	int row = 0;
	int column = 0;

};
