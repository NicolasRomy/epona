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
				enemy->loseHealth(dmg);
				return(true);

			}
		}
	}
	if (clockAttack.getElapsedTime() > sf::seconds(as))
	{
		player->Isattacking = false;
		return(false);
	}
}
void Sword::swordPlayer(Player* player, sf::RenderWindow& window)
{
	if (player->getGlobalRow() == 1)   //  gauche   
	{
		body.setRotation(180);
		position.x = player->getPosition().x +3  ; 
		position.y = player->getPosition().y +11 ;
	}
	if (player->getGlobalRow() == 2)// droite
	{
		body.setRotation(90);
		position.x = player->getPosition().x;
		position.y = player->getPosition().y +12;
	}
	if (player->getGlobalRow() == 0)//droite
	{
		body.setRotation(400);
		position.x = player->getPosition().x+8;
		position.y = player->getPosition().y+20;
	}
	if (player->getGlobalRow() == 3)//dessus
	{
		body.setRotation(300);
		position.x = player->getPosition().x+10;
		position.y = player->getPosition().y+13;
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