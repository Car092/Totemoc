#ifndef TOTEMOC_TILEMAP_HPP
#define TOTEMOC_TILEMAP_HPP

#include "Tile.hpp"
#include "SizeConstants.hpp"

class Player;

class Tilemap {
	private:
		std::vector<std::vector<Tile>> mMap;
	public:
		Tilemap();
		void draw(sf::RenderTarget& target, sf::Vector2f playerPos) const;
};

#endif //TOTEMOC_TILEMAP_HPP