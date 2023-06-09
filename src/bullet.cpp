#include "bullet.hpp"
#include "dinosaurs.hpp"
#include "player.hpp"

Bullet::Bullet(float bullet_width, float bullet_height, float bullet_x, float bullet_y)
{
	bullet.setPosition(sf::Vector2f(bullet_x, bullet_y));
	bullet.setSize(sf::Vector2f(bullet_width, bullet_height));
	bullet.setFillColor(sf::Color(5, 5, 5));
}

void Bullet::drawTo(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::fireBullet(Player& player_rect, int bullet_speed)
{
	auto player = player_rect.player;

	// Fire Bullets in the direction the player is facing
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		bullet_dir.x = -bullet_speed;
		bullet_dir.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		bullet_dir.x = bullet_speed;
		bullet_dir.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		bullet_dir.x = 0;
		bullet_dir.y = -bullet_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		bullet_dir.x = 0;
		bullet_dir.y = bullet_speed;
	}
}

void Bullet::bulletCollision(Dinosaur& dino_rect, bool& dino_dead, bool& bullet_dead, int& score, float screen_width, float screen_height)
{
	auto dinosaur = dino_rect.dinosaur;

	// If bullet collides with dinosaur, delete bullet and dinosaur
	if (bullet.getGlobalBounds().intersects(dinosaur.getGlobalBounds()))
	{
		bullet_dead = true;
		dino_dead = true;
		score++;
	}

	// If bullet goes beyond window border, delete bullet
	if (bullet.getPosition().x > screen_width
		|| bullet.getPosition().x < 0
		|| bullet.getPosition().y > screen_height
		|| bullet.getPosition().y < 0)
	{
		bullet_dead = true;
	}
}

void Bullet::moveBullet(float dt)
{
	bullet.move(bullet_dir * dt);
}

void Bullet::getGunshotSound()
{
	// Fetch gunshot sound from file
	if (!gunshot_sound_buffer.loadFromFile("content/gunshot_sound.wav"))
	{
		std::cout << "ERROR:: Could not load gunshot sound";
	}

	gunshot_sound.setBuffer(gunshot_sound_buffer);
}

void Bullet::playGunshotSound()
{
	gunshot_sound.play();
}