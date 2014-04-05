#include <iostream>
#include "Tile.hpp"
#include "Resources.hpp"

Tile::Tile(int type) : mItems(), mLiving(){
	mFloorSprite = SpritePtr(new SpriteNode(type));
	mTallSprite = SpritePtr(new SpriteNode(10));
}

Tile::Tile(Tile&& tile) : 
mPosition(tile.mPosition),
mFloorSprite(std::move(tile.mFloorSprite)),
mItems(std::move(tile.mItems)),       
mLiving(std::move(tile.mLiving)),
mTallSprite(std::move(tile.mTallSprite))
{
}

void Tile::dumpMoved(int tileX, int tileY, std::vector<EntityPtr>& itemsOut, std::vector<EntityPtr>& livingOut){
	sf::FloatRect tileRect((float)tileX, (float)tileY, 1.0f, 1.0f);
	for (auto it = mItems.begin(); it != mItems.end(); ){
		if (!tileRect.contains((*it)->getPosition())){
			itemsOut.push_back(std::move(*it));
			it = mItems.erase(it);
		}
		else{
			it++;
		}
	}
	for (auto it = mLiving.begin(); it != mLiving.end(); ){
		if (!tileRect.contains((*it)->getPosition())){
			livingOut.push_back(std::move(*it));
			it = mLiving.erase(it);
		}
		else{
			it++;
		}
	}
}

void Tile::pushItem(EntityPtr itemIn){
	mItems.push_back(std::move(itemIn));
}

void Tile::pushLiving(EntityPtr entityIn){
	mLiving.push_back(std::move(entityIn));
}

void Tile::packInVectors(SpriteNode*& floorTile, std::vector<Entity*>& items,
	                     std::vector<Entity*>& living, SpriteNode*& tallTile)
{
	floorTile = mFloorSprite.get();
	for (EntityPtr& item : mItems){
		items.push_back(item.get());
	}
	for (EntityPtr& livingElem : mLiving){
		living.push_back(livingElem.get());
	}
	tallTile = mTallSprite.get();
}

void Tile::setPosition(sf::Vector2i pos){
	mPosition = pos;
	mFloorSprite->setPosition((float)pos.x, (float)pos.y);
	mTallSprite->setPosition((float)pos.x, (float)pos.y);
}

const sf::Vector2i& Tile::getPosition(){
	return mPosition;
}