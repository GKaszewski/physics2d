#include "Obstacle.hpp"

Obstacle::Obstacle(sf::Vector2f position, sf::Vector2f size) {
	body.setPosition(position);
	body.setSize(size);
}

void Obstacle::draw(sf::RenderWindow& window) const {
	window.draw(body);
}
