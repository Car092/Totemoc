#ifndef TOTEMOC_CREATURE_HPP
#define TOTEMOC_CREATURE_HPP

#include "Entity.hpp"

class Player;

class Creature : public Entity{
public:
	Creature(Tilemap* tilemap, float speed, sf::Vector2f pos, Player* player);
	virtual void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
	virtual void update(const sf::Time& dt);
	virtual void checkCollisions();
	void trackPlayer();
	void attack();
	Entity::EntityType getType();

private:
	sf::Sprite mSprite;
	float mSpeed;
	Player* mPlayer;
	sf::Clock mAtkTimer;
};

#endif //TOTEMOC_CREATURE_HPP