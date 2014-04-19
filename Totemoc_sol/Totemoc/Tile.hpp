#ifndef TOTEMOC_TILE_HPP
#define TOTEMOC_TILE_HPP

#include <memory>
#include "SFML/Graphics.hpp"
#include "SizeConstants.hpp"
#include "SpriteEntity.hpp"
#include "Entity.hpp"

class Tilemap;

class Tile{
public:
	typedef std::unique_ptr<Entity> EntityPtr;
	typedef std::unique_ptr<SpriteEntity> SpritePtr;

public:
	sf::Vector2i mPosition;
	SpritePtr mFloorSprite;
	std::vector<EntityPtr> mItems;
	std::vector<EntityPtr> mLiving;
	SpritePtr mTallSprite;

public:
	Tile(Tilemap* tilemap, int type);
	Tile(Tile&& tile);
	void update(const sf::Time& dt);
	void drawLayer1(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void drawLayer2(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void drawLayer3(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void drawLayer4(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void setPosition(sf::Vector2i pos);
	const sf::Vector2i& getPosition();
	void dumpMoved(int tileX, int tileY, std::vector<EntityPtr>& itemsOut, std::vector<EntityPtr>& entitiesOut);
	void pushItem(EntityPtr itemIn);
	void pushLiving(EntityPtr entityIn);
	Tile& operator=(Tile&& tile);
	SpritePtr& getFloorSprite();
	std::vector<EntityPtr>& getItems();
	std::vector<EntityPtr>& getLiving();
	SpritePtr& getTallSprite();
};

#endif //TOTEMOC_TILE_HPP