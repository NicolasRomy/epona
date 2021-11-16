#pragma once
#include <SFML/Graphics.hpp>
#include "headers/Animation.h"
#include "headers/Sword.h"


/*
Annexe: en préparation du projet de physique, vous pouvez commencer a créer une classe vehicle, que le personnage peut rentrer et sortir grace
à la touche entrée.

*/
/*
Dans cette 4eme partie, il faudra afficher une barre de vie au dessus du héros et des ennemis, le texte de vie et animer l'épée du personnage.

L'épée devra être un Sprite. Lors de l'attaque, l'épée effectue une rotation de 180 degrés dans la direction face au personnage.
La durée de la rotation et sa vitesse doivent être configurables.
Ces fonctions vous aideront:

Sprite::setOrigin(Vector2f origin);
Sprite::setRotation(float degrees);

Lorsque l'épée touche l'ennemi, il perd de la vie.

Pour détecter la collision, un unique test de distance, effectué lorsque l'épée est en milieu de course, permet de savoir si l'ennemi est touché. Ce n'est pas précis, mais ca suffira pour le projet.
*/


Sword::Sword(sf::Texture* texture, float SwitchTime, float speed, int column) :
	animation(texture, SwitchTime)
{
	this->speed = speed;
	this->column = column;
	row = 0;
	IsMoving = false;

	sword.setPosition(0, 0);
	sword.setTexture(*texture);
}


void Sword::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	IsMoving = false;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		movement.y = -speed * deltaTime;
		IsMoving = true;
	}

	animation.Update(deltaTime, IsMoving, row, column);
	sword.setTextureRect(animation.uvRect);
	sword.move(movement);
}


void Sword::Draw(sf::RenderWindow& window)
{
	window.draw(sword);
}