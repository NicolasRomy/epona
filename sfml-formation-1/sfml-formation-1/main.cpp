#include <SFML/Graphics.hpp>
#include "headers/Player.h"
#include "headers/Sword.h"
#include "headers/Ennemy.h"
#include "headers/map.h"
#include "headers/Pickup.h"
#include <SFML/Audio.hpp>
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
const int View_height = 180.0f;
const int View_Weight = 128.0f;

void ResizeView(RenderWindow& window, View& view)
{
    float Ratio = float(window.getSize().x)/ float(window.getSize().y);

    view.setSize(View_height * Ratio, View_height);
}

int main()
{    
    vector<Vector2f>
        chemin = {
        sf::Vector2f(20.f, 0.f),
        sf::Vector2f(120.f, 0.f),
        sf::Vector2f(120.f, 100.f),

        };

    RenderWindow window(VideoMode(16 * 50, 9 * 50), "SFML works!");

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_height, View_Weight));


    float Ratio = float(window.getSize().x) / float(window.getSize().y);

    
    float FrameDuration = 0.3f;
    int speed = 50;
    int lifePlayer = 100;
    int lifeEnnemy = 50;
    int spritePersoX = 16;
    int spritePersoY = 16;
    bool isdead = false;
    int spritePotionX = 10;
    int spritepotionY = 10;

    Texture spritePlayer;
    spritePlayer.loadFromFile("characters.png");
    Player player(&spritePlayer, FrameDuration , speed, 3, lifePlayer, spritePersoX, spritePersoY, View_height, View_Weight, Ratio);

    monde map2;
    map2.texture2.loadFromFile("foresttiles2-t.png");

    Texture spriteEnnemy;
    spriteEnnemy.loadFromFile("characters.png");
    Ennemy ennemy(&spriteEnnemy, FrameDuration , speed, 9, spritePersoX, spritePersoY, chemin);

    Texture spritePotion;
    spritePotion.loadFromFile("potions.png");
    HealthPotion potion(&spritePotion, FrameDuration - 0.1 , 0, spritePotionX, spritepotionY);

    float deltaTime = 0.0f;
    Clock clock;
    window.setFramerateLimit(60);

    Sword sword;
    sword.texture.loadFromFile("sword.png");

    sf::Music music;
    music.openFromFile("music.WAV");
    music.play();
    music.setLoop(true);


    while (window.isOpen())
    {
        window.setKeyRepeatEnabled(false);
        
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type) 
            {
            case Event::Closed:
                 window.close(); 
                 break;            
            
            case Event::Resized:
                 ResizeView(window, view);
                 break;
            }
            
        }

        window.setView(view);    
        view.setCenter(player.getPosition());

        player.Update(deltaTime);
        potion.Update(deltaTime, &player);
       

        window.clear();

        map2.drawmap(window, map2);
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            sword.swordPlayer(&player, window);
        }     
        
        potion.Draw(window);
        
        if (player.Isattacking == true) {

            window.draw(sword.body);
        }

        sword.swordMovement(&player, window, &ennemy);
        
        player.Draw(window);
        if (ennemy.isdead == false) {
            ennemy.Update(deltaTime, chemin, &player);
            ennemy.Draw(window);

        }
       
        
        map2.drawmap2(window, map2);
        player.ShowLifebar(5, window);
        window.display();
        
    }

    return 0;
}