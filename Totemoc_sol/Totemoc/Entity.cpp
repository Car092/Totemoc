#include "Entity.hpp"
#include "Tilemap.hpp"

Entity::Entity() {

}

void Entity::update(const sf::Time& dt, Tilemap* tilemap){

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

void Entity::checkCollisions(Tilemap* tilemap){

}