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
	void updateCurrent(const sf::Time& dt, Tilemap* tilemap);
	void drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const;
	void checkCollisions(Tilemap* tilemap);
	void correctCol(sf::FloatRect rect);
};

#endif //TOTEMOC_PLAYER_HPP