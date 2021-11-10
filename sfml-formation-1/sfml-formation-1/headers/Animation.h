#pragma once
#include <SFML/Graphics.hpp>

class Animation
{

public: 
	Animation(sf::Texture* texture, float SwitchTime);
	void Update(float deltaTime, bool IsMoving, int row, int column);
	sf::IntRect uvRect;

private:
	sf::Vector2u currentImage;
	int column;
	float totalTime;
	float SwitchTime;
};

