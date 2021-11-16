#pragma once
#include <SFML/Graphics.hpp>
#include "headers/Animation.h"
#include <vector>



class Pickup
{
	Pickup(sf::Texture* texture, float SwitchTime, int column);
	Animation animation;

};

