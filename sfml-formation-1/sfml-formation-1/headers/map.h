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
    std::vector <sf::Sprite> middleground;
    sf::Texture texture2;
    sf::Vector2i size = { 16, 16 };
    sf::Vector2i emptyspace{ 6, 9 };
    bool isleaf;
    void drawmap(sf::RenderWindow &window, monde map2);
    void drawmap2(sf::RenderWindow& window, monde map2);
};