#include "headers/Player.h"

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Player::Player(sf::Texture* texture, float SwitchTime, float speed, int column) :
	animation(texture, SwitchTime, column)
{
	this->speed = speed;
	row = 0;
	faceRight = false;

	body.setSize(sf::Vector2f(16.0f, 16.0f));
	body.setPosition(0, 0);
	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	faceRight = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y = -speed * deltaTime;
		row = 3;
		faceRight = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y = speed * deltaTime;
		row = 0;
		faceRight = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	{
		movement.x = -speed * deltaTime;
		row = 1;
		faceRight = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		movement.x = speed * deltaTime;
		row = 2;
		faceRight = true;
	}

	animation.Update(row, 3, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}