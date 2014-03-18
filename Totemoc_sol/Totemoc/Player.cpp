#include "Player.hpp"

Player::Player()
{

}

void Player::update()
{
	if (direction == 1 && speed>0)
		this->mSpritePlayer.move(0, -.01 * speed);
	if (direction == 2 && speed>0)
		this->mSpritePlayer.move(0,  .01 * speed);
	if (direction == 3 && speed>0)
		this->mSpritePlayer.move(.01 * speed, 0);
	if (direction == 4 && speed>0)
		this->mSpritePlayer.move(-.01 * speed, 0);
}

void Player::draw()
{

}