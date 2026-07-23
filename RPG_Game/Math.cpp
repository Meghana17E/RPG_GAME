#include "Math.h"

sf::Vector2f Math::normalize(sf::Vector2f vector) {
	float m = sqrt(vector.x * vector.x + vector.y * vector.y);
	if (m != 0) {
		return sf::Vector2f(vector.x / m, vector.y / m);
	}
	else {
		return sf::Vector2f(0, 0);
	}
}