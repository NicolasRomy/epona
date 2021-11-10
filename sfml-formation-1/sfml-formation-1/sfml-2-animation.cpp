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
Dans cet example, vous allez devoir animer un personnage lors de son d�placement.
Toujours en utilisant Sprite::setTextureRect(), vous devrez alterner entre plusieurs sous r�gions de la texture fournie, � une fr�quence adapt�e.

Vous pouvez soit utiliser un sf::Timer avec Timer::getElapsedTime(), soit utiliser un accumulateur en float, sachant que SFML
peut verrouiller la fr�quence d'affichage � 60.

Il faudra �galement choisir la texture appropri�e en fonction de la direction de mouvement du personnage.
Il faudra penser � remettre la texture du h�ros dans son �tat de repos lorsque le personnage s'arr�te.

En exercice suppl�mentaire, vous pouvez faire tourner une �p�e en demi cercle autour du personnage.

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