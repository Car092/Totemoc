#ifndef TOTEMOC_TILEMAP_HPP
#define TOTEMOC_TILEMAP_HPP

#include "Tile.hpp"


class Tilemap{
	private:
		std::vector<std::vector<Tile>> mMap;
		const sf::Vector2i mOffscreenTSize;
		const sf::Vector2i mScreenTSize;
	public:
		Tilemap();
		bool loadMap(std::string tilemap);
		void draw(sf::RenderWindow& window, int playerX, int playerY);
};

#endif //TOTEMOC_TILEMAP_HPP