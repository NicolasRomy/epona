#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include <vector>


class Ennemy
{
public:

	void Update(float deltaTime, Player* player);
	void Draw(sf::RenderWindow& window);
	Ennemy(sf::Texture* texture, float SwitchTime, float speed, int column, int uvRectW, int uvRectH, std::vector<sf::Vector2f> chemin);
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
	std::vector<sf::Vector2f> chemin;
};

