#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class sword
{
public:
	sword(sf::Texture* texture, float SwitchTime, float speed, int column, float lifeMax, Player player);
	void Update(float deltaTime,Player player);
	void Draw(sf::RenderWindow& window);
	void ShowLifebar(int nbBar, sf::RenderWindow& window);
	void loseHealth(int pvLose);
	sf::FloatRect getGlobalBound();

private:
	sf::Sprite body;
	Animation animation;
	int row;
	float speed;
	int column;
	bool IsMoving;
	float lifeMax;
	int life;
	int rectToDraw;
};

