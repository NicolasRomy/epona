#include "headers/Ennemy.h"
#include <iostream>

Ennemy::Ennemy(sf::Texture* texture, float SwitchTime, float speed, int column):
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



void Ennemy::Update(float deltaTime, std::vector<sf::Vector2f> chemin)
{
	sf::Vector2f movement(0.0f, 0.0f);
	sf::Vector2f position = body.getPosition();
	int number = chemin.size();

	totalTime += deltaTime;

	if (totalTime >= 1.f)
	{
		totalTime -= 1.f;	
		path++;
		IsMoving = true;
		normalisation = chemin[path] / sqrt(chemin[path].x * chemin[path].x + chemin[path].y * chemin[path].y);
	
			if (path >= number - 1)
			{
				path = -1;
			}
	}
	if (normalisation.x > 0)
		row = 2;	
	if (normalisation.x < 0)
		row = 1;	
	if (normalisation.y > 0)
		row = 0;	
	if (normalisation.y < 0)
		row = 3;

	movement.x = speed * deltaTime;

	animation.Update( deltaTime, IsMoving, row , column);
	body.setTextureRect(animation.uvRect);
	body.move(normalisation);	
	std::cout << position.x << " || " << position.y << " || " << totalTime << std::endl;

}

void Ennemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}


