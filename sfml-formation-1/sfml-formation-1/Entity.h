// Entity.h
#ifndef ENTITY_H_
#define ENTITY_H_

#include "SFML\Graphics.hpp"

class Lifebar : public sf::Drawable, public sf::Transformable {

public:

private:

    sf::VertexArray vertices;
    sf::Texture texture;
    sf::Sprite sprite;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates& states) const ;

};

#endif