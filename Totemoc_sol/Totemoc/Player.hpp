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
	void updateCurrent(sf::Time dt);
	void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //TOTEMOC_PLAYER_HPP