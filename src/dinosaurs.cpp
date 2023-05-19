#include "dinosaurs.hpp"

Dinosaurs::Dinosaurs(float dino_width, float dino_height)
{
	dinosaur.setSize(sf::Vector2f(dino_width, dino_height));
	dinosaur.setOrigin(dino_width / 2, dino_height / 2);
	dinosaur.setFillColor(sf::Color(255, 255, 255));
}

void Dinosaurs::spawnDinosaurs(float screen_width, float screen_height)
{
	// Spawn dinosaur on side corresponding to random number generated
	if (random_side == 0)
	{
		side_one.x = screen_width / 2;
		side_one.y = 0;
		dinosaur.setPosition(side_one);
		move_down = true;
	}
	else if (random_side == 1)
	{
		side_two.x = screen_width;
		side_two.y = screen_height / 2;
		dinosaur.setPosition(side_two);
		move_left = true;
	}
	else if (random_side == 2)
	{
		side_three.x = screen_width / 2;
		side_three.y = screen_height;
		dinosaur.setPosition(side_three);
		move_up = true;
	}
	else if (random_side == 3)
	{
		side_four.x = 0;
		side_four.y = screen_height / 2;
		dinosaur.setPosition(side_four);
		move_right = true;
	}
}

void Dinosaurs::drawTo(sf::RenderWindow& window)
{
	window.draw(dinosaur);
}

void Dinosaurs::moveDinosaurs(float dino_speed)
{
	// Move in direction corresponding to side generated
	if (move_down)
	{
		direction.x = 0;
		direction.y = dino_speed;
	}
	if (move_left)
	{
		direction.x = -dino_speed;
		direction.y = 0;
	}
	if (move_up)
	{
		direction.x = 0;
		direction.y = -dino_speed;
	}
	if (move_right)
	{
		direction.x = dino_speed;
		direction.y = 0;
	}
	dinosaur.move(direction);
}
