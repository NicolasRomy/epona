#include "headers/Player.h"
#include <iostream>


Player::Player(sf::Texture* texture, float SwitchTime, float speed, int column, float lifeMax):
	animation(texture, SwitchTime)
{
	this->speed = speed;
	this->column = column;
	this->lifeMax = lifeMax;
	row = 0;
	IsMoving = false;
	life = lifeMax;
	body.setPosition(0, 0);
	body.setTexture(*texture);
}


void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	IsMoving = false;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& body.getPosition().y > 0)
	{
		movement.y += -speed * deltaTime;
		row = 3;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && body.getPosition().y < 112)
	{
		movement.y += speed * deltaTime;
		row = 0;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && body.getPosition().x > 0)
	{
		movement.x += -speed * deltaTime;
		row = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && body.getPosition().x < 164)
	{
		movement.x += speed * deltaTime;
		row = 2;
	}

	if (movement.x != 0 || movement.y != 0)
		IsMoving = true;
	else
		IsMoving = false;


 	animation.Update(deltaTime, IsMoving, row, column);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}


void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::ShowLifebar(int nbBar, sf::RenderWindow& window)
{
	float temp = nbBar / lifeMax ;
	float coef = life * temp;	
	int i = 0;
	while( coef > 1)
	{
		coef--;
	
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(5, 20));
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setPosition(130 + i * 7, 5);
		window.draw(rectangle);

		i++;

		std::cout <<coef<< std::endl;

	}

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(5, - 20*coef));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(130 + i * 7, 25);
	window.draw(rectangle);





}