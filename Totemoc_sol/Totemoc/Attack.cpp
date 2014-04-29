#include "Attack.hpp"
#include "Tilemap.hpp"

Attack::Attack(Tilemap* tilemap) : Entity(tilemap){

}

void Attack::draw(sf::RenderWindow& window, const sf::Vector2f& camPos){
	mColPoly.debugDraw(window, camPos);
}

void Attack::update(const sf::Time& dt){
	if (mIsDead) return;
	move(mVelocity * dt.asSeconds());
	mColPoly.updateWorldPos(getPosition());
	destroySelf();
}

void Attack::destroySelf(){
	mTilemap->destroyLiving(this);
	mIsDead = true;
}