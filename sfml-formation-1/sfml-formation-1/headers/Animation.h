#pragma once
#include <SFML/Graphics.hpp>

class Animation
{

public: 
	Animation(sf::Texture* texture, float SwitchTime, int column, int row);
	void Update(int row, int column, float deltaTime, bool FaceRight);
	sf::IntRect uvRect;

private:
	sf::Vector2u currentImage;

	float totalTime;
	float SwitchTime;
};

