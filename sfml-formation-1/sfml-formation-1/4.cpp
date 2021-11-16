/*
Dans cet example, il faudra faire déplacer un ennemi le long d'une série de points configurables.
L'ennemi devra faire une pause d'une durée configurable à chaque arrêt, et faire demi tour selon le même tracé.

La vitesse du monstre doit être configurable.

Vous n'êtes pas obligé d'animer le sprite, mais cela sera un bon bonus.

Afin de bien débugguer, il faudra afficher des petits points représentants l'itinéraire du monstre, avec aussi un tracé.
Il faudra donc utiliser sf::RectangleShape et sf::VertexArray, ainsi que sf::Timer.

Vous devrez donc créer un class enemy{} ou struct enemy{}, avec un constructeur, 
et les méthodes membres update(float delta) et draw(sf::RenderWindow & window).

Lorsque le personnage touche un monstre, la partie se finit avec un message game over en Texte via sf::Text, et le jeu recommence de zéro.
Il faudra vous aider de la fonction Sprite::getGlobalBounds() et FloatRect::intersects()

Vous devrez réutiliser, de préférence, le code de chargement de texte que vous avez écrit dans vos précédents projets.
*/

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
