#ifndef TOTEMOC_TILE_HPP
#define TOTEMOC_TILE_HPP

#include <memory>
#include "SFML/Graphics.hpp"
#include "SizeConstants.hpp"
#include "Item.hpp"
#include "Entity.hpp"

class Tile{
public:
	typedef std::unique_ptr<Item> ItemPtr;
	typedef std::unique_ptr<Entity> EntityPtr;

private:
	sf::Sprite mFloorSprite;
	std::vector<ItemPtr> mItems;
	std::vector<EntityPtr> mLiving;
	sf::Sprite mTallSprite;

public:
	Tile(int type);
	Tile(Tile&& tile);
	void draw(sf::RenderTarget& target, int tileX, int tileY, float camX, float camY);
	void update(sf::Time dt);
	void dumpMoved(int tileX, int tileY, std::vector<ItemPtr>& itemsOut, std::vector<EntityPtr>& entitiesOut);
	void pushItem(ItemPtr itemIn);
	void pushLiving(EntityPtr entityIn);
};

#endif //TOTEMOC_TILE_HPP