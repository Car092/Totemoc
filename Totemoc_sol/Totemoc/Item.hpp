#ifndef TOTEMOC_ITEM_HPP
#define TOTEMOC_ITEM_HPP

#include <SFML\Graphics.hpp>
#include "Entity.hpp"

class Item : public Entity{
private:
	sf::Sprite mSprite;

public:
	void draw(sf::RenderTarget& target);
	void setSprite(sf::Sprite& sprite);
};

#endif //TOTEMOC_ITEM_HPP