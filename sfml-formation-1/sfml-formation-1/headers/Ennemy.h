#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include <vector>


class Ennemy
{
public:

	void Update(float deltaTime, std::vector<sf::Vector2f> chemin , Player* player);
	void Draw(sf::RenderWindow& window);
	Ennemy(sf::Texture* texture, float SwitchTime, float speed, int column, int uvRectW, int uvRectH, std::vector<sf::Vector2f> chemin);
	bool IsArrived(sf::Vector2f);
	sf::Clock invincibleclock;
	bool invicible;
	
	bool loseHealth(int pvLose);
	sf::FloatRect getGlobalBound();

	bool isdead;
private:
	float totalTime = 0.0f;
	Animation animation;

	sf::Sprite body;
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

