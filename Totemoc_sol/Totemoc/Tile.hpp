#ifndef TOTEMOC_TILE_HPP
#define TOTEMOC_TILE_HPP

#include "SFML/Graphics.hpp"
#include "SizeConstants.hpp"

class Tile{
	private:
		sf::Sprite mSprite;
	public:
		Tile(int type);
		void draw(sf::RenderTarget& target, int tileX, int tileY, float camX, float camY) const;
};

#endif //TOTEMOC_TILE_HPP