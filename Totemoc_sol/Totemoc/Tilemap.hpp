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
		void draw(sf::RenderWindow& window, const sf::Vector2f& playerPos);
		void update(const sf::Time& dt, Tilemap* tilemap, const sf::Vector2f& playerPos);
		Tile& getTile(int tileX, int tileY);
		template<typename Func>
		void forEach_In_Zone(const sf::Vector2f& center, const sf::Vector2i& size, Func funcToDo);
};

#include "Tilemap.inl"

#endif //TOTEMOC_TILEMAP_HPP