#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture* texture, float SwitchTime, float speed, int column, float lifeMax, int uvRectW, int uvRectH, float viewheight, float viewweight, float ratio);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void ShowLifebar(int nbBar, sf::RenderWindow& window);
	void loseHealth(int pvLose);
	void maxHealth();
	sf::FloatRect getGlobalBound();
	sf::Vector2f getPosition() { return body.getPosition(); };

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
	sf::Vector2f normalisation;
	float viewheight;
	float viewweight;
	bool isAlive = true;
	float ratio;
};

