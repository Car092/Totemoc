#include "Player.hpp"

Player::Player() : Entity(),
	mSprite(),
	mScreenPos(Sizes::PLAYER_SCR_POS),
	mSpeed(3.0f)
{
	setPosition(20.0f, 15.0f);
	mSprite.setPosition(mScreenPos);
	mSprite.setTexture(Resources::textures->get(Resources::TextureID::player));
}

void Player::updateCurrent(const sf::Time& dt)
{
	setVelocity(sf::Vector2f(0.0f, 0.0f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		setVelocity(getVelocity() += sf::Vector2f(-1.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		setVelocity(getVelocity() += sf::Vector2f(1.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		setVelocity(getVelocity() += sf::Vector2f(0.0f, -1.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		setVelocity(getVelocity() += sf::Vector2f(0.0f, 1.0f));
	}

	if (getVelocity().x == 0.0f && getVelocity().y == 1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::player));
	}
	if (getVelocity().x == -1.0f && getVelocity().y == 0.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerLeft));
	}
	if (getVelocity().x == 1.0f && getVelocity().y == 0.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerRight));
	}
	if (getVelocity().x == 0.0f && getVelocity().y == -1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerBack));
	}
	if (getVelocity().x == -1.0f && getVelocity().y == -1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerBL));
	}
	if (getVelocity().x == 1.0f && getVelocity().y == -1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerBR));
	}
	if (getVelocity().x == -1.0f && getVelocity().y == 1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerFL));
	}
	if (getVelocity().x == 1.0f && getVelocity().y == 1.0f){
		mSprite.setTexture(Resources::textures->get(Resources::TextureID::playerFR));
	}
	move(getVelocity()*mSpeed*dt.asSeconds());
}

void Player::drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const{
	target.draw(mSprite);
}