#include "Player.hpp"

Player::Player() : 
	mSprite(),
	mWorldPos(20, 15),
	mWorldDest(0, 0),
	mScreenPos(Sizes::PLAYER_SCR_POS),
	mSpeed(3.0f),
	mDir()
{
	mSprite.setPosition(mScreenPos);
	if (!mTexture.loadFromFile("Resource Files/player.png")){
		throw std::runtime_error("Player::Player failed to load its sprite Files/player.png");
	}
	mSprite.setTexture(mTexture);
}

void Player::update(sf::Time dt)
{
	bool movKey = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		mDir = sf::Vector2f(-1.0f, 0.0f);
		movKey = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		mDir = sf::Vector2f(1.0f, 0.0f);
		movKey = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		mDir = sf::Vector2f(0.0f, -1.0f);
		movKey = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		mDir = sf::Vector2f(0.0f, 1.0f);
		movKey = true;
	}
	if (!movKey){
		mDir = sf::Vector2f(0.0f, 0.0f);
	}
	mWorldPos += mSpeed*mDir*dt.asSeconds();
}

void Player::draw(sf::RenderWindow& window){
	window.draw(mSprite);
}

sf::Vector2f Player::getWorldPos(){
	return mWorldPos;
}