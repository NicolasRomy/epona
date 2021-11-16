#include "headers/Player.h"
#include "headers/Sword.h"
#include <iostream>
void sword::Update(float deltaTime, Player player)
{
	sf::Vector2f movement(0.0f, 0.0f);
	IsMoving = false;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && row == 0)
	{
		std::cout << "0";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && row == 1)
	{
		std::cout << "1";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && row == 2)
	{
		std::cout << "2";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && row == 3)
	{
		std::cout << "3";
	}

	if (movement.x != 0 || movement.y != 0)
		IsMoving = true;
	else
		IsMoving = false;


	animation.Update(deltaTime, IsMoving, row, column);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}


void sword::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void sword::ShowLifebar(int nbBar, sf::RenderWindow& window)
{
	float temp = nbBar / lifeMax;
	float coef = life * temp;
	int i = 0;
	while (coef > 1)
	{
		coef--;

		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(5, 20));
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setPosition(130 + i * 7, 5);
		window.draw(rectangle);

		i++;

		std::cout << coef << std::endl;

	}

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(5, -20 * coef));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(130 + i * 7, 25);
	window.draw(rectangle);


}

void sword::loseHealth(int pvLose)
{
	life -= pvLose;
}

sf::FloatRect sword::getGlobalBound()
{
	return body.getGlobalBounds();
}
