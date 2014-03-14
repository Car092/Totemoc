#include "Player.hpp"

Player::Player() : sf::Sprite()
{
	sf::Texture tex;
	tex.loadFromFile("Resource Files/player.png");
	this->setTexture(tex);
}

void Player::update()
{


}