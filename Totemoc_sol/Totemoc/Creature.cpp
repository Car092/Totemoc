#include "Creature.hpp"
#include "Resources.hpp"
#include "Tilemap.hpp"
#include "UtilMath.hpp"
#include "Player.hpp"
#include "Attack.hpp"

Creature::Creature(Tilemap* tilemap, float speed, sf::Vector2f pos, Player* player) : Entity(tilemap){
	mSpeed = speed;
	setPosition(pos);
	mPlayer = player;
	mSprite.setTexture(Resources::textures->get(Resources::TextureID::player));
}

void Creature::update(const sf::Time& dt)
{
	trackPlayer();
	attack();
	move(mVelocity*mSpeed*dt.asSeconds());
	checkCollisions();
}

void Creature::draw(sf::RenderWindow& window, const sf::Vector2f& camPos){
	mSprite.setPosition((getPosition() - camPos) * 50.0f);
	window.draw(mSprite);
//	mColPoly.debugDraw(window, camPos);
}

void Creature::checkCollisions(){
	checkNonwalkable();
}

void Creature::trackPlayer(){
	sf::Vector2f distance = mPlayer->getPosition() - getPosition();
	sf::Vector2f dir = tot::normalize(distance);
	float mag = tot::calcLength(distance);

	if (mag > 4 && mag < 8){
		setVelocity(dir);
	}
	else if (mag < 8){
		setVelocity(sf::Vector2f(-dir.y, dir.x));
	}
	else{
		setVelocity(sf::Vector2f(0.0f, 0.0f));
	}
}

void Creature::attack(){
	if (mAtkTimer.getElapsedTime().asSeconds() > 1.0f){
		sf::Vector2f distance = mPlayer->getPosition() - getPosition();
		sf::Vector2f dir = tot::normalize(distance);
		std::unique_ptr<Attack> attack(new Attack(mTilemap));
		ConvexPolygon poly;
		attack->setVelocity(dir * 10.0f);
		poly.addVertex(sf::Vector2f(0.0f, 0.0f));
		poly.addVertex(sf::Vector2f(1.0f, 0.0f));
		poly.addVertex(sf::Vector2f(1.0f, 1.0f));
		poly.addVertex(sf::Vector2f(0.0f, 1.0f));
		putAttack(std::move(attack), poly, 0.0f, getPosition() + sf::Vector2f(5.0f, 0.0f));
		mAtkTimer.restart();
	}
}

Entity::EntityType Creature::getType(){
	return Entity::creature;
}