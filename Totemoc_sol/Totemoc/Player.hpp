#ifndef TOTEMOC_PLAYER_HPP
#define TOTEMOC_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "SizeConstants.hpp"
#include "Resources.hpp"

class Player
{

private:
	sf::Vector2f mWorldPos;
	sf::Vector2f mWorldDest;
	const sf::Vector2f mScreenPos;
	sf::Vector2f mDir;
	float mSpeed;
	sf::Sprite mSprite;
public:
	Player();
	void update(sf::Time dt);
	sf::Vector2f getWorldPos();
	void draw(sf::RenderWindow& window);
};

#endif //TOTEMOC_PLAYER_HPP