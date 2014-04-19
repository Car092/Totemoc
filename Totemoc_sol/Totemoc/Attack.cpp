#include "Attack.hpp"

Attack::Attack(Tilemap* tilemap) : Entity(tilemap){

}

void Attack::draw(sf::RenderWindow& window, const sf::Vector2f& camPos){
	mColPoly.debugDraw(window, camPos);
}