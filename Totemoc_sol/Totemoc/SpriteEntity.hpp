#ifndef TOTEMOC_SPRITEENTITY_HPP
#define TOTEMOC_SPRITEENTITY_HPP

#include "Entity.hpp"

class SpriteEntity : public Entity{
private:
	sf::Sprite mSprite;

public:
	SpriteEntity(Tilemap* tilemap, int type);
	void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
};

#endif //TOTEMOC_SPRITEENTITY_HPP