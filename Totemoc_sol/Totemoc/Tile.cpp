#include "Tile.hpp"

Tile::Tile(int type){
	switch (type){
		case 0:
			mColor = sf::Color::Green;
			break;
		case 1:
			mColor = sf::Color::Red;
			break;
		case 2:
			mColor = sf::Color::Yellow;
			break;
		case 3:
			mColor = sf::Color::Black;
			break;
		default:
			mColor = sf::Color::Cyan;
	}
	mShape.setFillColor(mColor);
	mShape.setSize(sf::Vector2f((float)Sizes::TILE_SIZE.x, (float)Sizes::TILE_SIZE.y));
}

void Tile::draw(sf::RenderTarget& target, int tileX, int tileY, float camX, float camY) const {
	sf::Vector2f screenPos;
	screenPos.x = (float)(tileX - camX)*Sizes::TILE_SIZE.x;
	screenPos.y = (float)(tileY - camY)*Sizes::TILE_SIZE.y;
	sf::RenderStates states;
	sf::Transform transform;
	states.transform = transform.translate(screenPos);
	target.draw(mShape, states);
}