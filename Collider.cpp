#include "Collider.hpp"

Collider::Collider(sf::RectangleShape& body) : body(body) {}

Collider::~Collider() = default;

bool Collider::check_collision(Collider& other, sf::Vector2f& direction, float push) {
	auto other_position = other.get_position();
	auto other_half_size = other.get_half_size();
	auto this_position = get_position();
	auto this_half_size = get_half_size();

	sf::Vector2f delta_position = { (other_position.x + other_half_size.x) - (this_position.x + this_half_size.x),
		(other_position.y + other_half_size.y) - (this_position.y + this_half_size.y) };
	auto intersect_x = abs(delta_position.x) - (other_half_size.x + this_half_size.x);
	auto intersect_y = abs(delta_position.y) - (other_half_size.y + this_half_size.y);


	if (intersect_x < 0.f && intersect_y < 0.f) {
		push = std::clamp(push, 0.f, 1.f);
		if (intersect_x > intersect_y) {
			if (delta_position.x > 0.f) {
				move(intersect_x * (1.f - push), 0.f);
				other.move(-intersect_x * push, 0.f);
				direction.x = 1.f;
				direction.y = 0.f;
			} else {
				move(-intersect_x * (1.f - push), 0.f);
				other.move(intersect_x * push, 0.f);
				direction.x = -1.f;
				direction.y = 0.f;
			}
		} else {
			if (delta_position.y > 0.f) {
				move(0.f, intersect_y * (1.f - push));
				other.move(0.f, -intersect_y * push);
				direction.y = 1.f;
				direction.x = 0.f;
			}
			else {
				move(0.f, -intersect_y * (1.f - push));
				other.move(0.f, intersect_y * push);
				direction.y = -1.f;
				direction.x = 0.f;
			}
		}
		return true;
	}

	return false;
}
