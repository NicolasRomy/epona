#include "headers/Pickup.h"
#include <iostream>

HealthPotion::HealthPotion(sf::Texture* texture, float SwitchTime, int column, int uvRectW, int uvRectH):
	animation(texture, SwitchTime, uvRectW, uvRectH)
{
	body.setPosition(50, 50);
	body.setTexture(*texture);
}



void HealthPotion::Update(float deltaTime, Player* player)
{
	animation.Update(deltaTime, IsMoving, row, column);
	body.setTextureRect(animation.uvRect);

	player->getGlobalBound();
	
	if (body.getGlobalBounds().intersects(player->getGlobalBound())) 
	{
		std::cout << "ok" << std::endl;
		player->maxHealth();
		body.setPosition(-500, -500);
	}

}

void HealthPotion::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
