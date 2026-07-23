#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Enemy.h"

//#include <cstddef> // for std::ptrdiff_t
//#include <limits>

int main() {
	//Initialize
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "RPG Game");
	
	Player player;
	Enemy enemy;
	
	//Initialize
	//player.Initialize();
	//enemy.Initialize();
	//Load
	player.Load();
	enemy.Load();
	//Calculation of direction of bullet
	//sf::Vector2f direction = enemy.sprite.getPosition() - player.sprite.getPosition();
	//direction = Math::normalize(direction);
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		//bullet.setPosition(bullet.getPosition() + direction * bulletspeed);
		player.Update(enemy);
		enemy.Update();
		//Draw
		window.clear(sf::Color::Black);
		player.Draw(window);
		enemy.Draw(window);
		window.display();
	}
	return 0;
}
