/*// Entity.cpp
#include "Entity.h"

// Miscellaneous functions

void Lifebar::draw(sf::RenderTarget& target, sf::RenderStates& states) const {
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(vertices, states);
}*/