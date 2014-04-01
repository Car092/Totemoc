#ifndef TOTEMOC_PLAYER_HPP
#define TOTEMOC_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "SizeConstants.hpp"
#include "Resources.hpp"
#include "Entity.hpp"

class Player : public Entity 
{
private:
	const sf::Vector2f mScreenPos;
	float mSpeed;
	sf::Sprite mSprite;

public:
	Player();
	void update(sf::Time dt);
	void draw(sf::RenderTarget& target);
};

#endif //TOTEMOC_PLAYER_HPP