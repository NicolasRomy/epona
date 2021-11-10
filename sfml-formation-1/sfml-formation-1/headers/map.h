#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma once
class monde {
public:
    sf::Sprite map_objects;
    sf::Sprite map_background;
    std::vector <sf::Sprite> forground;
    std::vector <sf::Sprite> background;
    sf::Texture texture2;
    sf::Vector2i size = { 16, 16 };
    sf::Vector2i emptyspace{ 6, 9 };
    void drawmap(sf::RenderWindow &window, std::vector <sf::Sprite> map_objects, std::vector <sf::Sprite> map_background);
};