#ifndef TOTEMOC_TILE_HPP
#define TOTEMOC_TILE_HPP

#include "SFML/Graphics.hpp"

class Tile{
	private:
		const int mWidth;
		const int mHeight;
		sf::Color mColor;
		sf::RectangleShape mShape;
	public:
		Tile(int type);
		void draw(sf::RenderWindow& window, int tileX, int tileY, int camX, int camY);
};

#endif //TOTEMOC_TILE_HPP