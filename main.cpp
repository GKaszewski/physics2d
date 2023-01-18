#include <SFML/Graphics.hpp>
#include <vector>

#include "Obstacle.hpp"
#include "Player.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Physics2D");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	bool running = true;
	Player player;
	Obstacle ground({ 0.f, 550.f }, sf::Vector2f(800, 50));
	Obstacle box({ 400.f, 486.f }, sf::Vector2f(60.f, 64.f));

	std::vector<Obstacle> obstacles;

	obstacles.push_back(ground);
	obstacles.push_back(box);

	sf::Clock clock;
	float deltaTime;

	while (running) {
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.f / 20.f) {
			deltaTime = 1.f / 20.f;
		}
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				running = false;
			}
		}

		if (!window.hasFocus()) continue;

		player.update(deltaTime);
		sf::Vector2f dir;
		sf::Vector2f box_dir;

		for (int i = 0; i < obstacles.size(); i++) {
			auto player_collider = player.get_collider();
			auto obstacle_collider = obstacles[i].get_collider();
			if (i == 1) {
				obstacle_collider.check_collision(player_collider, dir, .25f);
			} else {
				obstacle_collider.check_collision(player_collider, dir, 1.f);
			}
			player.on_collision(dir);
		}

		auto box_collider = obstacles[0].get_collider();
		obstacles[1].get_collider().check_collision(box_collider, box_dir, 0.f);

		window.clear();
		for (const auto& obstacle : obstacles) {
			obstacle.draw(window);
		}

		player.draw(window);
		window.display();
	}
	return 0;
}
