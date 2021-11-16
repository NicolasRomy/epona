#pragma once
#include <SFML/Graphics.hpp>
#include "headers/Animation.h"
#include "headers/Sword.h"


/*
Annexe: en pr�paration du projet de physique, vous pouvez commencer a cr�er une classe vehicle, que le personnage peut rentrer et sortir grace
� la touche entr�e.

*/
/*
Dans cette 4eme partie, il faudra afficher une barre de vie au dessus du h�ros et des ennemis, le texte de vie et animer l'�p�e du personnage.

L'�p�e devra �tre un Sprite. Lors de l'attaque, l'�p�e effectue une rotation de 180 degr�s dans la direction face au personnage.
La dur�e de la rotation et sa vitesse doivent �tre configurables.
Ces fonctions vous aideront:

Sprite::setOrigin(Vector2f origin);
Sprite::setRotation(float degrees);

Lorsque l'�p�e touche l'ennemi, il perd de la vie.

Pour d�tecter la collision, un unique test de distance, effectu� lorsque l'�p�e est en milieu de course, permet de savoir si l'ennemi est touch�. Ce n'est pas pr�cis, mais ca suffira pour le projet.
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