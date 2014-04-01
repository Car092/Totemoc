#include "Item.hpp"

void Item::draw(sf::RenderTarget& target){
	target.draw(mSprite);
}

void Item::setSprite(sf::Sprite& sprite){
	mSprite = sprite;
}