#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class Player {
public:
	Player();
	~Player();

	void update(float dt);
	void draw(sf::RenderWindow& window) const;

	sf::Vector2f get_position() const;
	void set_position(sf::Vector2f position);

	Collider get_collider() { return Collider(body); }

	void on_collision(sf::Vector2f direction);

private:
	sf::RectangleShape body;
	float speed = 120.f;
	bool canJump{};
	float jumpHeight;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;
	sf::Vector2f position;

	const float ACCELERATION = 0.5f;
	const float MAX_SPEED = 50.f;
	const float GRAVITY = 1000.f;
};

