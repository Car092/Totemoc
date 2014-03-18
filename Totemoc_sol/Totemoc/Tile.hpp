#ifndef TOTEMOC_TILE_HPP
#define TOTEMOC_TILE_HPP

#include "SFML/Graphics.hpp"
#include "SizeConstants.hpp"

class Tile{
	private:
		sf::Color mColor;
		sf::RectangleShape mShape;
	public:
		Tile(int type);
		void draw(sf::RenderWindow& window, int tileX, int tileY, float camX, float camY);
};

#endif //TOTEMOC_TILE_HPP