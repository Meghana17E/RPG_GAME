#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
	//Initialize
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "RPG Game");
	sf::Texture playerTexture;
	sf::Sprite playerSprite(playerTexture);
	if (playerTexture.loadFromFile("Assets/Player/spritesheet.png")) {
		std::cout << "Texture Loaded " << std::endl;
		//Dimensions of the spritesheet : 48,64
		//Dimesions of the sprite : 16,16 (48/3, 64/4)
		int xIndex = 0, yIndex = 0;
		playerSprite.setTextureRect(sf::IntRect({ xIndex * 16, yIndex * 16 }, { 16, 16 }));
		playerSprite.scale(sf::Vector2f(10, 10));
	}
	else {
		std::cout << "Texture not loaded!!!!" << std::endl;
	}

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
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
		//Draw
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
	}
	return 0;
}
