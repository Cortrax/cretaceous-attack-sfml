#ifndef DINOSAURS_HPP
#define DINOSAURS_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>

class Dinosaurs
{
public:
	Dinosaurs(float dino_width, float dino_height);
	void spawnDinosaurs(float screen_width, float screen_height, float& dino_width, float& dino_height);
	void drawTo(sf::RenderWindow& window);
	void moveDinosaurs(int dino_speed);
	void killDinosaurs(bool& dino_dead, Player& player_rect, int& lives_left);
	sf::Sprite dinosaur;

private:
	sf::Vector2f direction;

	// Coordinates for spawn locations on four sides of window
	int random_side;
	sf::Vector2f side_spawn;
	int placement_correction = 20;

	sf::Texture top_dino_texture;
	sf::Texture bottom_dino_texture;
	sf::Texture left_dino_texture;
	sf::Texture right_dino_texture;

	bool move_up;
	bool move_down;
	bool move_left;
	bool move_right;
};

#endif