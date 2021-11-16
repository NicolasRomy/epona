/*#include "Pickup.h"
#include <iostream>

HealthPotion::HealthPotion(sf::Texture* texture, float SwitchTime, int column) :
	animation(texture, SwitchTime) 
{
	body.setPosition(50, 50);
	body.setTexture(*texture);
}	

void HealthPotion::Update(float deltaTime)
{
	animation.Update(deltaTime, IsMoving, row, column);
	body.setTextureRect(animation.uvRect);
}

void HealthPotion::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
*/