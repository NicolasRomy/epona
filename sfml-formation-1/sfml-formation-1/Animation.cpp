#include "headers/Animation.h"
#include <iostream>


Animation::Animation(sf::Texture* texture, float SwitchTime, int column) 
{
	this->SwitchTime = SwitchTime;
	totalTime = 0.0f;
	uvRect.width = 16;
	uvRect.height = 16;
	int numberFrame = 1;
	currentImage.x = column;
	currentImage.y = row;
}

void Animation::Update(int row, int column, float deltaTime, bool FaceRight)
{	

	currentImage.y = row;

	totalTime += deltaTime;
	if (FaceRight == true)
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
	else
		currentImage.x = column + 1;


	std::cout << currentImage.x << " " << currentImage.y << " "<< deltaTime << std::endl;
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

} 
