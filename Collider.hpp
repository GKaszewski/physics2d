#pragma once
#include <SFML/Graphics.hpp>

class Collider {
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	bool check_collision(Collider& other, sf::Vector2f& direction, float push);
	sf::Vector2f get_position() const { return body.getPosition(); }
	sf::Vector2f get_half_size() const { return body.getSize() / 2.0f; }
	sf::Vector2f get_size() const { return body.getSize(); }

	void move(sf::Vector2f& direction) { body.move(direction); }
	void move(float dx, float dy) { body.move(dx, dy); }

	void draw(sf::RenderWindow& window) const;
private:
	sf::RectangleShape& body;
};

