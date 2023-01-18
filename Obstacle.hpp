#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class Obstacle {
public:
	Obstacle(sf::Vector2f position, sf::Vector2f size);

	void draw(sf::RenderWindow& window) const;

	Collider get_collider() { return Collider(body); }
private:
	sf::RectangleShape body;
};

