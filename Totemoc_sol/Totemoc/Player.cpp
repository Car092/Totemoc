#include "Player.hpp"
#include "Tilemap.hpp"
#include "TimeConstants.hpp"

Player::Player() : Entity(),
	mSprite(),
	mSpeed(2.0f)
{
	setPosition(20.0f, 15.0f);
	mSprite.setPosition(Sizes::TILE_SIZE.x*Sizes::TILES_PER_SCREEN.x/2.0f, Sizes::TILE_SIZE.y*Sizes::TILES_PER_SCREEN.y/2.0f);
	mSprite.setTexture(Resources::textures->get(Resources::TextureID::player));
	setColRect(sf::Vector2f(1.0f, 1.0f));
}

void Player::updateCurrent(const sf::Time& dt, Tilemap* tilemap)
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
	checkCollisions(tilemap);
}

void Player::drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const{
	target.draw(mSprite);
}

void Player::checkCollisions(Tilemap* tilemap){
	std::vector<SpriteNode*> floorTilesPtrs;
	std::vector<Entity*> itemsPtrs;
	std::vector<Entity*> livingPtrs;
	std::vector<SpriteNode*> tallTilesPtrs;
	tilemap->forEach_In_Zone(getPosition(), sf::Vector2i(4, 4), [&](Tile& tile, int tileX, int tileY)
	{
		tile.packInVectors(floorTilesPtrs, itemsPtrs, livingPtrs, tallTilesPtrs);
	});
	for (SpriteNode* floorTile : floorTilesPtrs){
		if (floorTile->getColType() == SceneNode::ColType::unwalkable){
			if (getColRect().intersects(floorTile->getColRect())){
				move(getVelocity()*(mSpeed * -1.0f)*Times::TIME_P_FRAME.asSeconds());
				return;
			}
		}
	}
	for (Entity* item : itemsPtrs){
		if (item->getColType() == SceneNode::ColType::unwalkable){
			if (getColRect().intersects(item->getColRect())){
				move(getVelocity()*(mSpeed * -1.0f)*Times::TIME_P_FRAME.asSeconds());
				return;
			}
		}
	}
	for (Entity* livingElem : livingPtrs){
		if (livingElem->getColType() == SceneNode::ColType::unwalkable){
			if (getColRect().intersects(livingElem->getColRect())){
				move(getVelocity()*(mSpeed * -1.0f)*Times::TIME_P_FRAME.asSeconds());
				return;
			}
		}
	}
	for (SpriteNode* tallTile : tallTilesPtrs){
		if (tallTile->getColType() == SceneNode::ColType::unwalkable){
			if (getColRect().intersects(tallTile->getColRect())){
				move(getVelocity()*(mSpeed * -1.0f)*Times::TIME_P_FRAME.asSeconds());
//				move(sf::Vector2f(1.0f, 0.0f));
				return;
			}
		}
	}
}
