#include "Player.h"
#include "Math.h"
#include <iostream>

void Player::Load()
{
	
	if (texture.loadFromFile("Assets/Player/spritesheet.png")) {
		std::cout << "Player Texture Loaded " << std::endl;
		//Dimensions of the spritesheet : 48,64
		//Dimesions of the sprite : 16,16 (48/3, 64/4)
		int xIndex = 0, yIndex = 0;
		sprite.setTextureRect(sf::IntRect({ xIndex * 16, yIndex * 16 }, { 16, 16 }));
		sprite.scale(sf::Vector2f(10, 10));
		sprite.setPosition(sf::Vector2f({ 100,400 }));
	}
	else {
		std::cout << "Texture not loaded!!!!" << std::endl;
	}
}
void Player::Update(Enemy& enemy)
{
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		sprite.setPosition(position + sf::Vector2f({ 1,0 }));
		//playerSprite.move(sf::Vector2f({ 1,0 }));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		sprite.move(sf::Vector2f({ -1,0 }));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		sprite.move(sf::Vector2f({ 0,  -1 }));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		sprite.move(sf::Vector2f({ 0, 1 }));
	}
	//Fire Bullets
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		bullets.push_back(sf::RectangleShape(sf::Vector2f({ 50,25 })));
		size_t i = bullets.size() - 1;
		//std::ptrdiff_t i = static_cast<std::ptrdiff_t>(bullets.size()) - 1;
		bullets[i].setPosition(sprite.getPosition());
		//bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
		//bulletDirection = normalize(bulletDirection);
	}
	for (int i = 0; i < bullets.size(); i++) {
		sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::normalize(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletspeed);

	}
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	//window.draw(bullet);
	for (int i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}
}