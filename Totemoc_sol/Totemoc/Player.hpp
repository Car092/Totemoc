#ifndef TOTEMOC_PLAYER_HPP
#define TOTEMOC_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "SizeConstants.hpp"
#include "Resources.hpp"
#include "Entity.hpp"

class Attack;

class Player : public Entity 
{
private:
	float mSpeed;
	sf::Sprite mSprite;

public:
	Player(Tilemap* tilemap);
	void update(const sf::Time& dt);
	void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void checkCollisions();
	void attack(sf::Vector2f mousePos);
	Entity::EntityType getType();

};

#endif //TOTEMOC_PLAYER_HPP