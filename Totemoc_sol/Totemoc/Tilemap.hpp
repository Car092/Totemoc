#ifndef TOTEMOC_TILEMAP_HPP
#define TOTEMOC_TILEMAP_HPP

#include "Tile.hpp"


class Tilemap{
	private:
		std::vector<std::vector<Tile>> mMap;

	public:
		Tilemap();
		bool loadMap(std::string tilemap);
		void draw(int playerX, int playerY);
};

#endif //TOTEMOC_TILEMAP_HPP