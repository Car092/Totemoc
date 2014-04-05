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
		void refreshTiles(const sf::Vector2f& playerPos);
		Tile& getTile(int tileX, int tileY);
		template<typename Func>
		void forEach_In_ActiveZone(const sf::Vector2f& playerPos, Func funcToDo);
};

#include "Tilemap.inl"

#endif //TOTEMOC_TILEMAP_HPP