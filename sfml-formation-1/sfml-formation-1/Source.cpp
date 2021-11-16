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
