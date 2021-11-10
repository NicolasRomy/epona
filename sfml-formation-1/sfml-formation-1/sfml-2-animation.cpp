#include <SFML/Graphics.hpp>
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



int main()
{
    RenderWindow window(VideoMode(100, 100), "SFML works!");
    Texture sprite;
    sprite.loadFromFile("ghost.png");
    Sprite player(sprite);

    Clock clock;

    // limite les FPS à 60
    window.setFramerateLimit(60);
    float playerMovementSpeed = 100;
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        float deltaTime = clock.restart().asSeconds();

        if (Keyboard::isKeyPressed(Keyboard::Up) && player.getPosition().y > 0)
        {
            player.move(0.f, -playerMovementSpeed * deltaTime);

        }

        if (Keyboard::isKeyPressed(Keyboard::Down) && player.getPosition().y < 84)
        {
            player.move(0.f, playerMovementSpeed * deltaTime);
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) && player.getPosition().x > 0)
        {
            player.move(-playerMovementSpeed * deltaTime, 0.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Right) && player.getPosition().x < 108)
        {
            player.move(playerMovementSpeed * deltaTime, 0.f);
        }


        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;

    */