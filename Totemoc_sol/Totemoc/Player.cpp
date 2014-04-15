#include "Player.hpp"
#include "Tilemap.hpp"
#include "TimeConstants.hpp"

Player::Player() : Entity(),
	mSprite(),
	mSpeed(3.0f)
{
	setPosition(20.0f, 15.0f);
	mSprite.setPosition(Sizes::TILE_SIZE.x*Sizes::TILES_PER_SCREEN.x/2.0f, Sizes::TILE_SIZE.y*Sizes::TILES_PER_SCREEN.y/2.0f);
	mSprite.setTexture(Resources::textures->get(Resources::TextureID::player));
	setColRect(sf::Vector2f(1.0f, 1.0f));
}

void Player::updateCurrent(const sf::Time& dt, Tilemap* tilemap)
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
				correctCol(floorTile->getColRect());
				return;
			}
		}
	}
	for (Entity* item : itemsPtrs){
		if (item->getColType() == SceneNode::ColType::unwalkable){
			if (getColRect().intersects(item->getColRect())){
				correctCol(item->getColRect());
				return;
			}
		}
	}
	for (Entity* livingElem : livingPtrs){
		if (livingElem->getColType() == SceneNode::ColType::unwalkable){
			if (getColRect().intersects(livingElem->getColRect())){
				correctCol(livingElem->getColRect());
				return;
			}
		}
	}
	for (SpriteNode* tallTile : tallTilesPtrs){
		if (tallTile->getColType() == SceneNode::ColType::unwalkable){
			if (getColRect().intersects(tallTile->getColRect())){
				correctCol(tallTile->getColRect());
				return;
			}
		}
	}
}

void Player::correctCol(sf::FloatRect rectB){
	sf::FloatRect rectA = getColRect();
	float aMin_x = rectA.left;
	float aMax_x = rectA.left + rectA.width;
	float bMin_x = rectB.left;
	float bMax_x = rectB.left + rectB.width;
	float aMin_y = rectA.top;
	float aMax_y = rectA.top + rectA.height;
	float bMin_y = rectB.top;
	float bMax_y = rectB.top + rectB.height;
	sf::Vector2f correctVec;
	if (aMax_x - bMin_x < bMax_x - aMin_x){
		correctVec.x = (aMax_x - bMin_x) * -1.0f;
	}
	else{
		correctVec.x = bMax_x - aMin_x;
	}
	if (aMax_y - bMin_y < bMax_y - aMin_y){
		correctVec.y = (aMax_y - bMin_y) * -1.0f;
	}
	else{
		correctVec.y = bMax_y - aMin_y;
	}
	if (std::abs(correctVec.x) < std::abs(correctVec.y)){
		correctVec.y = 0.0f;
	}
	else{
		correctVec.x = 0.0f;
	}
	move(correctVec);
}