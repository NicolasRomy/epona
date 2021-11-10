#include "headers/Ennemy.h"
#include <iostream>

Ennemy::Ennemy(sf::Texture* texture, float SwitchTime, float speed, int column) :
	animation(texture, SwitchTime)
{
	this->speed = speed;
	this->column = column;
	row = 0;
	turn = false;
	IsMoving = false;

	body.setSize(sf::Vector2f(16.0f, 16.0f));
	body.setPosition(30, 0);
	body.setTexture(texture);
}

void Ennemy::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	sf::Vector2f position = body.getPosition();
	std::cout << position.y << std::endl;

	if (position.y < 100)
	{
		movement.y = speed * deltaTime;
		row = 0;
		IsMoving = true;
	}
	else
		turn = true; 

	if 	(turn == true)
	{
		if (position.y > 0)
		{
			movement.y = -speed * deltaTime;
			row = 3;
			IsMoving = true;
		}
		else
			turn = false;
	}
		

	animation.Update( deltaTime, IsMoving, row , column);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Ennemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}


