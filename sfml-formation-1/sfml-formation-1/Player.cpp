#include "headers/Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, float SwitchTime, float speed, int column, float lifeMax, int uvRectW, int uvRectH ):
	animation(texture, SwitchTime, uvRectW, uvRectH)
{
	this->speed = speed;
	this->column = column;
	this->lifeMax = lifeMax;
	row = 0;
	IsMoving = false;
	life = lifeMax;
	body.setPosition(8, 8);
	body.setTexture(*texture);
}



void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	IsMoving = false;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& body.getPosition().y > -100)
	{
		movement.y += -speed * deltaTime;
		row = 3;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && body.getPosition().y < 500)
	{
		movement.y += speed * deltaTime;
		row = 0;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && body.getPosition().x > -100)
	{
		movement.x += -speed * deltaTime;
		row = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && body.getPosition().x < 500)
	{
		movement.x += speed * deltaTime;
		row = 2;
	}
		normalisation = movement / sqrt(movement.x * movement.x + movement.y * movement.y);	

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
	while( coef > 1 )
	{
		coef--;
	
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(5, 20));
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setPosition(body.getPosition().x + 50 + i * 7, body.getPosition().y + -60);
		window.draw(rectangle);

		i++;

	}
	if (coef >0) {
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(5, -20 * coef));
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setPosition(body.getPosition().x + 50 + i * 7, body.getPosition().y + -40);
		window.draw(rectangle);
	}
	else {
		sf::Texture gameover;
		sf::Sprite  gameover_sprite;
		gameover.loadFromFile("gameover.jpg");
		gameover_sprite.setTexture(gameover);
		gameover_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 180,128 }));
		gameover_sprite.setPosition(0, 0);
		window.draw(gameover_sprite);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			exit(0);
		}
	}
}

void Player::loseHealth(int pvLose)
{
	life -= pvLose;
}

void Player::maxHealth()
{
	life = lifeMax;
}

sf::FloatRect Player::getGlobalBound()
{
	return body.getGlobalBounds();
}


