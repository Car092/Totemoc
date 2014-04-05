#ifndef TOTEMOC_TILE_HPP
#define TOTEMOC_TILE_HPP

#include <memory>
#include "SFML/Graphics.hpp"
#include "SizeConstants.hpp"
#include "SpriteNode.hpp"
#include "Entity.hpp"

class Tile{
public:
	typedef std::unique_ptr<Entity> EntityPtr;
	typedef std::unique_ptr<SpriteNode> SpritePtr;

private:
	sf::Vector2i mPosition;
	SpritePtr mFloorSprite;
	std::vector<EntityPtr> mItems;
	std::vector<EntityPtr> mLiving;
	SpritePtr mTallSprite;

public:
	Tile(int type);
	Tile(Tile&& tile);
	void setPosition(sf::Vector2i pos);
	const sf::Vector2i& getPosition();
	void dumpMoved(int tileX, int tileY, std::vector<EntityPtr>& itemsOut, std::vector<EntityPtr>& entitiesOut);
	void pushItem(EntityPtr itemIn);
	void pushLiving(EntityPtr entityIn);
	void packInVectors(SpriteNode*& floorTiles, std::vector<Entity*>& items,
		std::vector<Entity*>& living, SpriteNode*& tallTiles);
};

#endif //TOTEMOC_TILE_HPP