#include "Enemy.h"
#include <iostream>
void Enemy::Initialize()
{
}

void Enemy::Load()
{

	if (texture.loadFromFile("Assets/Player/spritesheet.png")) {
		std::cout << "Enemy Texture Loaded " << std::endl;
		//Dimensions of the spritesheet : 48,64
		//Dimesions of the sprite : 16,16 (48/3, 64/4)
		int xIndex = 0, yIndex = 1;
		sprite.setTextureRect(sf::IntRect({ xIndex * 16, yIndex * 16 }, { 16, 16 }));
		sprite.scale(sf::Vector2f(10, 10));
		sprite.setPosition(sf::Vector2f({ 500,400 }));
	}
	else {
		std::cout << "Texture not loaded!!!!" << std::endl;
	}
}
void Enemy::Update()
{
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}