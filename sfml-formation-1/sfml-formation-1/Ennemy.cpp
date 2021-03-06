#include "headers/Ennemy.h"
#include <iostream>

Ennemy::Ennemy(sf::Texture* texture, float SwitchTime, float speed, int column, int uvRectW, int uvRectH, std::vector<sf::Vector2f> chemin):
	animation(texture, SwitchTime, uvRectW, uvRectH)
{
	this->speed = speed;
	this->column = column;
	this->chemin = chemin;
	row = 0;
	turn = false;
	IsMoving = false;

	body.setPosition(chemin.back().x, chemin.back().y);
	body.setTexture(*texture);

}


bool Ennemy::IsArrived(sf::Vector2f path)
{
	float range = 1.f;
	sf::Vector2f sizeTarget(range, range);
	sf::FloatRect r1(path, sizeTarget);
	return body.getGlobalBounds().intersects(r1);
}



void Ennemy::Update(float deltaTime, Player* player)
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

	player->getGlobalBound();
	if (body.getGlobalBounds().intersects(player->getGlobalBound())) {
		player->loseHealth(1);
	}
}

void Ennemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}


