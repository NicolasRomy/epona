#include <SFML/Graphics.hpp>
#include "headers/Player.h"
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;

/*
Dans cet example, vous allez devoir animer un personnage lors de son déplacement.
Toujours en utilisant Sprite::setTextureRect(), vous devrez alterner entre plusieurs sous régions de la texture fournie, à une fréquence adaptée.

Vous pouvez soit utiliser un sf::Timer avec Timer::getElapsedTime(), soit utiliser un accumulateur en float, sachant que SFML
peut verrouiller la fréquence d'affichage à 60.

Il faudra également choisir la texture appropriée en fonction de la direction de mouvement du personnage.
Il faudra penser à remettre la texture du héros dans son état de repos lorsque le personnage s'arrête.

En exercice supplémentaire, vous pouvez faire tourner une épée en demi cercle autour du personnage.

// https://imgur.com/a/vVmZnXt

*/

int main()
{

    RenderWindow window(VideoMode(100, 100), "SFML works!");


    Texture sprite;
    sprite.loadFromFile("characters.png");

    Player player(&sprite, 0.3f, 50, 2);

    float deltaTime = 0.0f;
    Clock clock;
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        window.setKeyRepeatEnabled(false);
        
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


        player.Update(deltaTime);

        window.clear();
        player.Draw(window);
        window.display();
    }

    return 0;
}