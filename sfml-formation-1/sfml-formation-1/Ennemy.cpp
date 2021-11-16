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

	body.setPosition(30, 0);
	body.setTexture(*texture);

}

bool Ennemy::IsArrived(sf::Vector2f path)
{
	float range = 1.f;
	sf::Vector2f sizeTarget(range, range);
	sf::FloatRect r1(path, sizeTarget);
	return body.getGlobalBounds().intersects(r1);
}

void Ennemy::Update(float deltaTime, std::vector<sf::Vector2f> chemin)
{
	sf::Vector2f movement(0.0f, 0.0f);
	sf::Vector2f position = body.getPosition();
	int number = chemin.size();

	totalTime += deltaTime;

    movement = chemin[path] - body.getPosition();
	normalisation = movement / sqrt(movement.x * movement.x + movement.y * movement.y);	

	if (verif)
	{		
		IsMoving = true;
		path++;
		if (path >= number)
		{
			path = 0;
		}
		verif = false;
	}
	verif = IsArrived(chemin[path]);



	if (normalisation.y > 0 )
		row = 0;	
	if (normalisation.y < 0)
		row = 3;	
	if (normalisation.x > 0 && normalisation.x > normalisation.y)
		row = 2;	
	if (normalisation.x < 0 && normalisation.x < normalisation.y)
		row = 1;	


	animation.Update( deltaTime, IsMoving, row , column);
	body.setTextureRect(animation.uvRect);
	body.move(normalisation);

}

void Ennemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}


