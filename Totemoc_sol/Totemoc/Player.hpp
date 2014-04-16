#ifndef TOTEMOC_PLAYER_HPP
#define TOTEMOC_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "SizeConstants.hpp"
#include "Resources.hpp"
#include "Entity.hpp"

class Player : public Entity 
{
private:
	float mSpeed;
	sf::Sprite mSprite;

public:
	Player();
	void update(const sf::Time& dt, Tilemap* tilemap);
	void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void checkCollisions(Tilemap* tilemap);
	void correctCol(sf::FloatRect rect);
};

#endif //TOTEMOC_PLAYER_HPP