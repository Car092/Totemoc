#include "Entity.hpp"
#include "Tilemap.hpp"

Entity::Entity(Tilemap* tilemap) {
	mTilemap = tilemap;
}

void Entity::update(const sf::Time& dt){

}

void Entity::draw(sf::RenderWindow& window, const sf::Vector2f& camPos){
	
}

void Entity::setVelocity(sf::Vector2f velocity){
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy){
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity(){
	return mVelocity;
}

ConvexPolygon& Entity::getColPoly(){
	mColPoly.updateWorldPos(getPosition());
	return mColPoly;
}

Entity::ColType Entity::getColType(){
	return mColType;
}

void Entity::setColType(Entity::ColType colType){
	mColType = colType;
}

void Entity::checkCollisions(){

}

void Entity::checkNonwalkable(){
	std::vector<SpriteEntity*> floorTilesPtrs;
	std::vector<Entity*> itemsPtrs;
	std::vector<Entity*> livingPtrs;
	std::vector<SpriteEntity*> tallTilesPtrs;
	mColPoly.updateWorldPos(getPosition());
	mTilemap->forEach_In_Zone(getPosition(), sf::Vector2i(4, 4), [&](Tile& tile, int tileX, int tileY)
	{
		floorTilesPtrs.push_back(tile.getFloorSprite().get());
		for (Tile::EntityPtr& item : tile.getItems()){
			if (item.get() != this)
				itemsPtrs.push_back(item.get());
		}
		for (Tile::EntityPtr& living : tile.getLiving()){
			if (living.get() != this)
				livingPtrs.push_back(living.get());
		}
		tallTilesPtrs.push_back(tile.getTallSprite().get());
	});
	for (SpriteEntity* floorTile : floorTilesPtrs){
		if (floorTile->getColType() == Entity::ColType::nonwalkable){
			floorTile->getColPoly().updateWorldPos(floorTile->getPosition());
			sf::Vector2f displVec = mColPoly.checkUnwalkable(floorTile->getColPoly());
			move(displVec);
		}
	}
	for (Entity* item : itemsPtrs){
		if (item->getColType() == Entity::ColType::nonwalkable){
			item->getColPoly().updateWorldPos(item->getPosition());
			sf::Vector2f displVec = mColPoly.checkUnwalkable(item->getColPoly());
			move(displVec);
		}
	}
	for (Entity* livingElem : livingPtrs){
		if (livingElem->getColType() == Entity::ColType::nonwalkable){
			livingElem->getColPoly().updateWorldPos(livingElem->getPosition());
			sf::Vector2f displVec = mColPoly.checkUnwalkable(livingElem->getColPoly());
			move(displVec);
		}
	}
	for (SpriteEntity* tallTile : tallTilesPtrs){
		if (tallTile->getColType() == Entity::ColType::nonwalkable){
			tallTile->getColPoly().updateWorldPos(tallTile->getPosition());
			sf::Vector2f displVec = mColPoly.checkUnwalkable(tallTile->getColPoly());
			move(displVec);
		}
	}
}

Entity::EntityType Entity::getType(){
	return Entity::entity;
}

void Entity::putAttack(std::unique_ptr<Entity> attack, ConvexPolygon& attackPoly, float rotAngle, sf::Vector2f worldPos){
	attack->setPosition(worldPos);
	attackPoly.rotate(rotAngle);
	attackPoly.updateWorldPos(attack->getPosition());
	attackPoly.calcNormals();
	attack->getColPoly() = attackPoly;
	mTilemap->addLiving(std::move(attack));
}