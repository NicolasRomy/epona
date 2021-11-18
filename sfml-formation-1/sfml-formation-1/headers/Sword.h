#include <SFML/Graphics.hpp>
#include "Ennemy.h"
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma once
class Sword {
public:
	int samarche;
	sf::RectangleShape body;
	sf::Texture texture;
	sf::Sprite sword;
	bool swordMovement(Player* player, sf::RenderWindow& window, Ennemy* enemy);
	void swordPlayer(Player* player, sf::RenderWindow& window);
	sf::Clock clockAttack;
	float as = 0.3f;
	float angle = 0.f;
	int dmg = 15;
	sf::Vector2f position = { 0.f, 0.f };
};