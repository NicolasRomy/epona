#include "headers/Animation.h"
#include <iostream>


Animation::Animation(sf::Texture* texture, float SwitchTime, int uvRectW, int uvRectH )
{
	this->SwitchTime = SwitchTime;
	this->uvRectW = uvRectW;
	this->uvRectH = uvRectH;
	totalTime = 0.0f;
	uvRect.width = uvRectW;
	uvRect.height = uvRectH;
	currentImage.x = column;
}

void Animation::Update(float deltaTime, bool IsMoving, int row, int column)
{	
	currentImage.y = row;
	totalTime += deltaTime;

	if (IsMoving == true)
	{
		if (totalTime >= SwitchTime)
		{
			totalTime -= SwitchTime;
			currentImage.x++;

			if (currentImage.x >= 3 + column)
			{
				currentImage.x = column;
			}
		}
	}
	else {
		currentImage.x = column + 1;
		totalTime = 0.3f;
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

} 

