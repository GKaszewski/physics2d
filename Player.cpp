#include "Player.hpp"

Player::Player() {
	body.setFillColor(sf::Color::Green);
	body.setSize({ 50.f, 50.f });
	body.setPosition(0.f, 400.f);
	jumpHeight = 200.f;
}

Player::~Player() = default;

void Player::update(float dt) {
	//damping
	velocity.x *= 0.5f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump) {
		velocity.y = -sqrtf(2.f * GRAVITY * jumpHeight);
		canJump = false;
	}

	velocity.y += GRAVITY * dt;
	
	body.move(velocity * dt);
}

void Player::draw(sf::RenderWindow& window) const {
	window.draw(body);
}

sf::Vector2f Player::get_position() const { return body.getPosition(); }

void Player::set_position(sf::Vector2f position) { this->position = position; }

void Player::on_collision(sf::Vector2f direction) {
	if (direction.x < 0.f) {
		velocity.x = 0.f;
	}
	else if (direction.x > 0.f) {
		velocity.x = 0.f;
	}

	if (direction.y < 0.f) {
		velocity.y = 0.f;
		canJump = true;
	}
	else if (direction.y > 0.f) {
		velocity.y = 0.f;
	}
}
