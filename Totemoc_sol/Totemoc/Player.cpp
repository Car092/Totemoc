#include "Player.hpp"
#include "Tilemap.hpp"
#include "TimeConstants.hpp"
#include "Attack.hpp"
#include <iostream>

Player::Player(Tilemap* tilemap) : Entity(tilemap),
	mSprite(),
	mSpeed(3.0f)
{
	setPosition(20.0f, 15.0f);
	mSprite.setPosition(Sizes::TILE_SIZE.x*Sizes::TILES_PER_SCREEN.x/2.0f, Sizes::TILE_SIZE.y*Sizes::TILES_PER_SCREEN.y/2.0f);
	mSprite.setTexture(Resources::textures->get(Resources::TextureID::player));
	mColPoly.addVertex(sf::Vector2f(0.0f, 0.2f));
	mColPoly.addVertex(sf::Vector2f(0.2f, 0.0f));
	mColPoly.addVertex(sf::Vector2f(1.0f, 0.8f));
	mColPoly.addVertex(sf::Vector2f(0.8f, 1.0f));
	mColPoly.calcNormals();
	setColType(Entity::ColType::nonwalkable);
}

void Player::update(const sf::Time& dt)
{
	if (mVelocity.x == 0.0f && mVelocity.y == 1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::player));
	}
	if (mVelocity.x == -1.0f && mVelocity.y == 0.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerLeft));
	}
	if (mVelocity.x == 1.0f && mVelocity.y == 0.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerRight));
	}
	if (mVelocity.x == 0.0f && mVelocity.y == -1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerBack));
	}
	if (mVelocity.x == -1.0f && mVelocity.y == -1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerBL));
		mVelocity /= std::sqrtf(2.0f);
	}
	if (mVelocity.x == 1.0f && mVelocity.y == -1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerBR));
		mVelocity /= std::sqrtf(2.0f);
	}
	if (mVelocity.x == -1.0f && mVelocity.y == 1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerFL));
		mVelocity /= std::sqrtf(2.0f);
	}
	if (mVelocity.x == 1.0f && mVelocity.y == 1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerFR));
		mVelocity /= std::sqrtf(2.0f);
	}
	move(mVelocity*mSpeed*dt.asSeconds());
	checkCollisions();
}

void Player::draw(sf::RenderWindow& window, const sf::Vector2f& camPos){
	window.draw(mSprite);
	mColPoly.debugDraw(window, camPos);
}

void Player::checkCollisions(){
	checkNonwalkable();
}

void Player::attack(sf::Vector2f mousePos){
	std::unique_ptr<Entity> attack(new Attack(mTilemap));
	ConvexPolygon attackPolySide;

	attackPolySide.addVertex(sf::Vector2f(0.0f, 0.0f));
	attackPolySide.addVertex(sf::Vector2f(0.8f, -1.0f));
	attackPolySide.addVertex(sf::Vector2f(1.0f, 0.0f));
	attackPolySide.addVertex(sf::Vector2f(0.8f, 1.0f));

	sf::FloatRect northWest(mSprite.getPosition() + sf::Vector2f(-200.0f, -200.0f), sf::Vector2f(200.0f, 200.0f));
	sf::FloatRect north(mSprite.getPosition() + sf::Vector2f(0.0f, -200.0f), sf::Vector2f(mSprite.getLocalBounds().width, 200.0f));
	sf::FloatRect northEast(mSprite.getPosition() + sf::Vector2f(mSprite.getLocalBounds().width, -200.0f), sf::Vector2f(200.0f, 200.0f));
	sf::FloatRect east(mSprite.getPosition() + sf::Vector2f(mSprite.getLocalBounds().width, 0.0f), sf::Vector2f(200.0f, mSprite.getLocalBounds().height));
	sf::FloatRect southEast(mSprite.getPosition() + sf::Vector2f(mSprite.getLocalBounds().width, mSprite.getLocalBounds().height), sf::Vector2f(200.0f, 200.0f));
	sf::FloatRect south(mSprite.getPosition() + sf::Vector2f(0.0f, mSprite.getLocalBounds().height), sf::Vector2f(mSprite.getLocalBounds().width, 200.0f));
	sf::FloatRect southWest(mSprite.getPosition() + sf::Vector2f(-200.0f, mSprite.getLocalBounds().height), sf::Vector2f(200.0f, 200.0f));
	sf::FloatRect west(mSprite.getPosition() + sf::Vector2f(-200.0f, 0.0f), sf::Vector2f(200.0f, mSprite.getLocalBounds().height));

	if (northWest.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 225.0f, getPosition());
	}
	else if (north.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 270.0f, getPosition() + sf::Vector2f(0.5f, 0.0f));
	}
	else if (northEast.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 315.0f, getPosition() + sf::Vector2f(1.0f, 0.0f));
	}
	else if (east.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 0.0f, getPosition() + sf::Vector2f(1.0f, 0.5f));
	}
	else if (southEast.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 45.0f, getPosition() + sf::Vector2f(1.0f, 1.0f));
	}
	else if (south.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 90.0f, getPosition() + sf::Vector2f(0.5f, 1.0f));
	}
	else if (southWest.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 135.0f, getPosition() + sf::Vector2f(0.0f, 1.0f));
	}
	else if (west.contains(mousePos)){
		putAttack(std::move(attack), attackPolySide, 180.0f, getPosition() + sf::Vector2f(0.0f, 0.5f));
	}
}

Entity::EntityType Player::getType(){
	return Entity::player;
}