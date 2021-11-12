#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <vector>


class Ennemy
{
public:

	Ennemy(sf::Texture* texture, float SwitchTime, float speed, int column);
	void Update(float deltaTime, std::vector<sf::Vector2f> chemin);
	void Draw(sf::RenderWindow& window);
	bool IsArrived(sf::Vector2f);

private:
	float totalTime = 0.0f;
	sf::Sprite body;
	Animation animation;
	float speed;
	int column;
	bool IsMoving;
	bool verif = true;
	bool turn;
	sf::Vector2f normalisation;
	int path = 0;
	int row = 0;
};

