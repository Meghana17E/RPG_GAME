#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;
public:
	Enemy() : sprite(texture) {};
	void Initialize();
	void Draw(sf::RenderWindow& window);
	void Update();
	void Load();
};

