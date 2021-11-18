#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include "headers/Ennemy.h"
#include "headers/Player.h"
#include "headers/Sword.h"
bool Sword::swordMovement(Player* player, sf::RenderWindow& window, Ennemy* enemy)
{

	if (player->Isattacking == true)
	{
		body.setRotation(-(clockAttack.getElapsedTime() / sf::seconds(as) * 120) + angle );
		if (clockAttack.getElapsedTime() / sf::seconds(as) > 0.2 && clockAttack.getElapsedTime() / sf::seconds(as) < 0.3 && enemy->getGlobalBound().intersects(player->getGlobalBound()))
		{
			if (!enemy->invicible)
			{
				enemy->invincibleclock.restart();
				enemy->invicible = true;
				//enemy->loseHealth(dmg);
				std::cout << "al";
                enemy->isdead = true;
				return(enemy->isdead);

			}
		}
	}
	if (clockAttack.getElapsedTime() > sf::seconds(as))
	{
		player->Isattacking = false;
	}

}
void Sword::swordPlayer(Player* player, sf::RenderWindow& window)
{
    if (player->getGlobalRow() == 1)   //  gauche
    {
        body.setRotation(180);
        position.x = player->getPosition().x + 4;
        position.y = player->getPosition().y + 5;
    }
    if (player->getGlobalRow() == 2)// droite
    {
        body.setRotation(0);
        position.x = player->getPosition().x + 10;
        position.y = player->getPosition().y + 10;
    }
    if (player->getGlobalRow() == 0)// bas
    {
        body.setRotation(90);
        position.x = player->getPosition().x + 5;
        position.y = player->getPosition().y + 10;
    }
    if (player->getGlobalRow() == 3)//dessus
    {
        body.setRotation(270);
        position.x = player->getPosition().x + 10;
        position.y = player->getPosition().y + 3;
    }

    body.setTexture(&texture);
    body.setSize({ 24,11 });
    angle = body.getRotation();

    body.setOrigin(0, 0);
    body.setScale(0.7, 0.7);
    player->Isattacking = true;
    clockAttack.restart();
    body.setPosition(position);

}