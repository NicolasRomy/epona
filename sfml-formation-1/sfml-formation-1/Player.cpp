#include "headers/Player.h"
#include <iostream>


Player::Player(sf::Texture* texture, float SwitchTime, float speed, int column):
	animation(texture, SwitchTime)
{
	this->speed = speed;
	this->column = column;
	row = 0;
	IsMoving = false;

	body.setSize(sf::Vector2f(16.0f*5, 16.0f*5));
	body.setPosition(0, 0);
	body.setTexture(texture);
}


void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	IsMoving = false;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y = -speed * deltaTime;
		row = 3;
		IsMoving = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y = speed * deltaTime;
		row = 0;
		IsMoving = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	{
		movement.x = -speed * deltaTime;
		row = 1;
		IsMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		movement.x = speed * deltaTime;
		row = 2;
		IsMoving = true;
	}

 	animation.Update(deltaTime, IsMoving, row, column);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}


void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}