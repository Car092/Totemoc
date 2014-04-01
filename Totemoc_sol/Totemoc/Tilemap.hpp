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
		void loadMap(std::vector<std::vector<int>>& map);
		void draw(sf::RenderTarget& target, sf::Vector2f playerPos);
		void update(sf::Time dt, sf::Vector2f playerPos);
		void updateMovingLayer(int tileX,int tileY);
		Tile& getTile(int tileX, int tileY);
};

#endif //TOTEMOC_TILEMAP_HPP