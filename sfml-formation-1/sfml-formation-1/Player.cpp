#include "headers/Player.h"
#include <iostream>


Player::Player(sf::Texture* texture, float SwitchTime, float speed, int column):
	animation(texture, SwitchTime)
{
	this->speed = speed;
	this->column = column;
	row = 0;
	IsMoving = false;

	body.setSize(sf::Vector2f(16.0f, 16.0f));
	body.setPosition(0, 0);
	body.setTexture(texture);
}


void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	IsMoving = false;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& body.getPosition().y > 0)
	{
		movement.y = -speed * deltaTime;
		row = 3;
		IsMoving = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && body.getPosition().y < 112)
	{
		movement.y = speed * deltaTime;
		row = 0;
		IsMoving = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && body.getPosition().x > 0)
	{
		movement.x = -speed * deltaTime;
		row = 1;
		IsMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && body.getPosition().x < 164)
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