#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include<math.h>
sf::Vector2f normalize(sf::Vector2f vector) {
	float m = sqrt(vector.x * vector.x + vector.y * vector.y);
	if (m != 0) {
		return sf::Vector2f(vector.x / m, vector.y /m);
	}
	else {
		return sf::Vector2f(0, 0);
	}
}
int main() {
	//Initialize
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "RPG Game");
	//Bullet
	//sf::RectangleShape bullet(sf::Vector2f({50,25}));
	//Multi bullet entities
	std::vector<sf::RectangleShape> bullets;
	//Single bullet entity
	//bullet.setPosition(sf::Vector2f({ 170,390 }));
	float bulletspeed = 0.5f;
	//-------------------Load
	//----------------Load Enemy
	sf::Texture enemyTexture;
	sf::Sprite enemySprite(enemyTexture);
	if (enemyTexture.loadFromFile("Assets/Player/spritesheet.png")) {
		std::cout << "Enemy Texture Loaded " << std::endl;
		//Dimensions of the spritesheet : 48,64
		//Dimesions of the sprite : 16,16 (48/3, 64/4)
		int xIndex = 0, yIndex = 1;
		enemySprite.setTextureRect(sf::IntRect({ xIndex * 16, yIndex * 16 }, { 16, 16 }));
		enemySprite.scale(sf::Vector2f(10, 10));
		enemySprite.setPosition(sf::Vector2f({ 500,400 }));
	}
	else {
		std::cout << "Texture not loaded!!!!" << std::endl;
	}
	//----------------Load Player
	sf::Texture playerTexture;
	sf::Sprite playerSprite(playerTexture);
	if (playerTexture.loadFromFile("Assets/Player/spritesheet.png")) {
		std::cout << "Player Texture Loaded " << std::endl;
		//Dimensions of the spritesheet : 48,64
		//Dimesions of the sprite : 16,16 (48/3, 64/4)
		int xIndex = 0, yIndex = 0;
		playerSprite.setTextureRect(sf::IntRect({ xIndex * 16, yIndex * 16 }, { 16, 16 }));
		playerSprite.scale(sf::Vector2f(10, 10));
		playerSprite.setPosition(sf::Vector2f({ 100,400 }));
	}
	else {
		std::cout << "Texture not loaded!!!!" << std::endl;
	}
	//Calculation of direction of bullet
	sf::Vector2f direction = enemySprite.getPosition() - playerSprite.getPosition();
	direction = normalize(direction);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		//bullet.setPosition(bullet.getPosition() + direction * bulletspeed);
		
		sf::Vector2f position = playerSprite.getPosition();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
			playerSprite.setPosition(position + sf::Vector2f({ 1,0 }));
			//playerSprite.move(sf::Vector2f({ 1,0 }));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			playerSprite.move(sf::Vector2f({ -1,0 }));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			playerSprite.move(sf::Vector2f({0,  -1}));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			playerSprite.move(sf::Vector2f({ 0, 1}));
		}
		//Fire Bullets
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			bullets.push_back(sf::RectangleShape(sf::Vector2f({ 50,25 })));
			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());
			//bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
			//bulletDirection = normalize(bulletDirection);
		}
		for (int i = 0; i < bullets.size(); i++){
			sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
			bulletDirection = normalize(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletspeed);

		}
		//Draw
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(enemySprite);
		//window.draw(bullet);
		for (int i = 0; i < bullets.size(); i++) {
			window.draw(bullets[i]);
		}
		window.display();
	}
	return 0;
}
