#include <iostream>
#include "Tile.hpp"
#include "Resources.hpp"

Tile::Tile(Tilemap* tilemap, int type) : mItems(), mLiving(){
	mFloorSprite = SpritePtr(new SpriteEntity(tilemap, type));
	mTallSprite = SpritePtr(new SpriteEntity(tilemap, 10));
}

Tile::Tile(Tile&& tile) : 
mPosition(tile.mPosition),
mFloorSprite(std::move(tile.mFloorSprite)),
mItems(std::move(tile.mItems)),       
mLiving(std::move(tile.mLiving)),
mTallSprite(std::move(tile.mTallSprite))
{
}

void Tile::update(const sf::Time& dt){
	mFloorSprite->update(dt);
	for (EntityPtr& item : mItems){
		item->update(dt);
	}
	for (EntityPtr& living : mLiving){
		living->update(dt);
	}
	mTallSprite->update(dt);
}

void Tile::drawLayer1(sf::RenderWindow& window, const sf::Vector2f& camPos){
	mFloorSprite->draw(window, camPos);
}

void Tile::drawLayer2(sf::RenderWindow& window, const sf::Vector2f& camPos){
	for (EntityPtr& item : mItems){
		item->draw(window, camPos);
	}
}

void Tile::drawLayer3(sf::RenderWindow& window, const sf::Vector2f& camPos){
	for (EntityPtr& living : mLiving){
		living->draw(window, camPos);
	}
}

void Tile::drawLayer4(sf::RenderWindow& window, const sf::Vector2f& camPos){
	mTallSprite->draw(window, camPos);
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

void Tile::setPosition(sf::Vector2i pos){
	mPosition = pos;
	mFloorSprite->setPosition((float)pos.x, (float)pos.y);
	mTallSprite->setPosition((float)pos.x, (float)pos.y);
}

const sf::Vector2i& Tile::getPosition(){
	return mPosition;
}

Tile& Tile::operator=(Tile&& tile){
	mFloorSprite = std::move(tile.mFloorSprite);
	mItems = std::move(tile.mItems);
	mLiving = std::move(tile.mLiving);
	mTallSprite = std::move(tile.mTallSprite);
	return *this;
}

Tile::SpritePtr& Tile::getFloorSprite(){
	return mFloorSprite;
}

std::vector<Tile::EntityPtr>& Tile::getItems(){
	return mItems;
}

std::vector<Tile::EntityPtr>& Tile::getLiving(){
	return mLiving;
}

Tile::SpritePtr& Tile::getTallSprite(){
	return mTallSprite;
}