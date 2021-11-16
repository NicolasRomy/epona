#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture* texture, float SwitchTime, float speed, int column, float lifeMax);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void ShowLifebar(int nbBar, sf::RenderWindow& window);

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

