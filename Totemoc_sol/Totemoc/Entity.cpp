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

void Entity::setColRect(sf::Vector2f size, sf::Vector2f posRel){
	mColRect = sf::FloatRect(posRel, size);
}

sf::FloatRect Entity::getColRect(){
	sf::FloatRect colRect;
	colRect.width = mColRect.width;
	colRect.height = mColRect.height;
	colRect.left = getPosition().x + mColRect.left;
	colRect.top = getPosition().y + mColRect.top;
	return colRect;
}

Entity::ColType Entity::getColType(){
	return mColType;
}

void Entity::setColType(Entity::ColType colType){
	mColType = colType;
}

void Entity::checkCollisions(Tilemap* tilemap){

}