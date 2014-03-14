#include "Tile.hpp"

Tile::Tile(int type):mWidth(50), mHeight(50){
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
}

void Tile::draw(sf::RenderWindow& window, int tileX, int tileY, int camX, int camY){
	sf::Vector2f screenPos;
	screenPos.x = (float)(tileX - camX)*mWidth;
	screenPos.y = (float)(tileY - camY)*mHeight;
	mShape.setPosition(screenPos);
	window.draw(mShape);
}