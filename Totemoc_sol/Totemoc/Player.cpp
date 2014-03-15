#include "Player.hpp"

Player::Player() : 
	sf::Sprite(),
	mWorldPos(0, 0),
	mScreenPos(568, 384)
{
	this->setPosition(498.0f, 344.0f);
	if (!texturePlayer.loadFromFile("Resource Files/player.png")){
		throw std::runtime_error("Player::Player failed to load its sprite Files/player.png");
	}
	this->setTexture(texturePlayer);
}

void Player::update()
{


}

sf::Vector2f Player::getWorldPos(){
	return mWorldPos;
}