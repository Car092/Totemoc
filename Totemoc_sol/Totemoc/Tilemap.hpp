#ifndef TOTEMOC_TILEMAP_HPP
#define TOTEMOC_TILEMAP_HPP

#include "Tile.hpp"
#include "SizeConstants.hpp"

class Player;

class Tilemap {
	private:
		std::vector<std::vector<Tile>> mMap;
		std::vector<Tile::EntityPtr> mAddItemQueue;
		std::vector<Tile::EntityPtr> mAddLivingQueue;
		std::vector<Entity*> mDestroyItemQueue;
		std::vector<Entity*> mDestroyLivingQueue;
	public:
		Tilemap();
		void loadMap(std::vector<std::vector<int>>& map);
		void refreshTiles(const sf::Vector2f& playerPos);
		void draw(sf::RenderWindow& window, const sf::Vector2f& playerPos);
		void update(const sf::Time& dt, const sf::Vector2f& playerPos);
		Tile& getTile(int tileX, int tileY);
		template<typename Func>
		void forEach_In_Zone(const sf::Vector2f& center, const sf::Vector2i& size, Func funcToDo);
		void addItem(Tile::EntityPtr item);
		void addLiving(Tile::EntityPtr living);
		void destroyItem(Entity* item);
		void destroyLiving(Entity* living);
	
	private:
		void addNewEntities();
		void destroyOldEntities();
};

#include "Tilemap.inl"

#endif //TOTEMOC_TILEMAP_HPP