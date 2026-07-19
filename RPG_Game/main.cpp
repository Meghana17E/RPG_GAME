#include <SFML/Graphics.hpp>
int main() {
	//Initialize
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "RPG Game");
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Green);
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(sf::Color(250, 150, 100));
	//sf::Texture texture;
	//shape.setTexture(&texture);
	//shape.setTextureRect(sf::IntRect({ 10,10 }, { 100,100 }));
	sf::RectangleShape rectangle({ 120.f, 60.f });
	rectangle.setPosition(sf::Vector2f(100.f,0.f));
	rectangle.setFillColor(sf::Color::Magenta);
	//rectangle.setSize({ 100.f, 100.f });
	//change the radius of the circle 
	shape.setRadius(200.f);
	//change the number of sides (points) to 100
	shape.setPointCount(100);
	sf::CircleShape triangle(80.f, 3);
	sf::CircleShape square(80.f, 4);
	sf::CircleShape pentagon(80.f, 5);
	sf::CircleShape hexagon(80.f, 6);
	sf::CircleShape heptagon(80.f, 7);
	sf::CircleShape octagon(80.f, 8);
	triangle.setFillColor(sf::Color::Red);
	triangle.setPosition(sf::Vector2f(150.f, 150.f));
	square.setFillColor(sf::Color::Red);
	square.setPosition(sf::Vector2f(0.f, 150.f));
	pentagon.setFillColor(sf::Color::Red);
	pentagon.setPosition(sf::Vector2f(350.f, 150.f));
	hexagon.setFillColor(sf::Color::Red);
	hexagon.setPosition(sf::Vector2f(500.f, 250.f));
	heptagon.setFillColor(sf::Color::Red);
	heptagon.setPosition(sf::Vector2f(650.f, 350.f));
	octagon.setFillColor(sf::Color::Red);
	octagon.setPosition(sf::Vector2f(150.f, 350.f));

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}
		//Draw
		window.clear(sf::Color::Black);

		window.draw(shape);
		window.draw(rectangle);
		window.draw(square);
		window.draw(triangle);
		window.draw(pentagon);
		window.draw(hexagon);
		window.draw(heptagon);
		window.draw(octagon);
		window.display();

	}
	return 0;
}