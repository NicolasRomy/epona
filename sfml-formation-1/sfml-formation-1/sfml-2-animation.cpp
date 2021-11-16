#include <SFML/Graphics.hpp>
#include "headers/Player.h"
#include "headers/Ennemy.h"
#include "headers/map.h"
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

    vector<Vector2f>
        chemin = {
        sf::Vector2f(20.f, 0.f),
        sf::Vector2f(120.f, 0.f),
        sf::Vector2f(120.f, 100.f),
        sf::Vector2f(20.f, 100.f),
        };



    RenderWindow window(VideoMode(180,128), "SFML works!");
    sf::Vector2u scaleWindow(180*5,128* 5);
    window.setSize(scaleWindow);

    float FrameDuration = 0.3f;
    int speed = 50;
    int lifePlayer = 100;

    Texture spritePlayer;
    spritePlayer.loadFromFile("characters.png");
    Player player(&spritePlayer, FrameDuration , speed, 3, lifePlayer);

    monde map2;
    map2.texture2.loadFromFile("foresttiles2-t.png");

    Texture spriteEnnemy;
    spriteEnnemy.loadFromFile("characters.png");
    Ennemy ennemy(&spriteEnnemy, FrameDuration , speed, 9);

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
        ennemy.Update(deltaTime, chemin);
        
        window.clear();

        map2.drawmap(window, map2);
        player.Draw(window);
        ennemy.Draw(window);
        map2.drawmap2(window, map2);
        player.ShowLifebar(5, window);
        window.display();
    }

    return 0;
}