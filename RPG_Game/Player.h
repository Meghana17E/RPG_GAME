#pragma once
#include<SFML/Graphics.hpp>
#include "Enemy.h"
class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletspeed = 0.5f;
public:
	sf::Sprite sprite;
public:
	Player() : sprite(texture) {};
	void Initialize();
	void Draw(sf::RenderWindow& window);
	void Update(Enemy& enemy);
	void Load();
};