#include <iostream>
#include "Tile.hpp"
#include "Resources.hpp"

Tile::Tile(int type) : mItems(), mLiving(){
	switch (type){
		case 0:
			mFloorSprite.setTexture(Resources::textures->get(Resources::grass));
			break;
		case 1:
			mFloorSprite.setTexture(Resources::textures->get(Resources::dirt));
			break;
		case 2:
			mFloorSprite.setTexture(Resources::textures->get(Resources::rock));
			break;
		case 3:
			mFloorSprite.setTexture(Resources::textures->get(Resources::wood));
			break;
		case 4:
			mFloorSprite.setTexture(Resources::textures->get(Resources::water));
			break;
	}
}

Tile::Tile(Tile&& tile) : 
mFloorSprite(tile.mFloorSprite),
mItems(std::move(tile.mItems)),       
mLiving(std::move(tile.mLiving)),
mTallSprite(tile.mTallSprite)
{
}

void Tile::draw(sf::RenderTarget& target, int tileX, int tileY, float camX, float camY){
	sf::Vector2f screenPos;
	screenPos.x = (float)(tileX - camX)*Sizes::TILE_SIZE.x;
	screenPos.y = (float)(tileY - camY)*Sizes::TILE_SIZE.y;
	sf::RenderStates states;
	sf::Transform transform;
	states.transform = transform.translate(screenPos);
	target.draw(mFloorSprite, states);

	for (ItemPtr& item : mItems){
		item->draw(target);
	}
	for (EntityPtr& entity : mLiving){
		std::cout << "Tile: " << tileX << ", " << tileY << " Player pos: " << entity->getPosition().x << ", " << entity->getPosition().y << std::endl;
		entity->draw(target);
	}

	target.draw(mTallSprite, states);
}

void Tile::update(sf::Time dt){
	for (EntityPtr& entity : mLiving){
		entity->update(dt);
	}
}

void Tile::dumpMoved(int tileX, int tileY, std::vector<ItemPtr>& itemsOut, std::vector<EntityPtr>& entitiesOut){
	sf::FloatRect tileRect((float)tileX, (float)tileY, 1.0f, 1.0f);
	for (auto it = mItems.begin(); it != mItems.end(); it++){
		if (!tileRect.contains((*it)->getPosition())){
			itemsOut.push_back(std::move(*it));
			it = mItems.erase(it);
			if (it == mItems.end()) break;
		}
	}
	for (auto it = mLiving.begin(); it != mLiving.end(); it++){
		if (!tileRect.contains((*it)->getPosition())){
			entitiesOut.push_back(std::move(*it));
			it = mLiving.erase(it);
			if (it == mLiving.end()) break;
		}
	}
}

void Tile::pushItem(ItemPtr itemIn){
	mItems.push_back(std::move(itemIn));
}

void Tile::pushLiving(EntityPtr entityIn){
	mLiving.push_back(std::move(entityIn));
}
