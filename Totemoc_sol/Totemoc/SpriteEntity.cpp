#include "SpriteEntity.hpp"
#include "Resources.hpp"

SpriteEntity::SpriteEntity(int type){
	switch (type){
		case 0:
			mSprite.setTexture(Resources::textures->get(Resources::grass));
			break;
		case 1:
			mSprite.setTexture(Resources::textures->get(Resources::dirt));
			break;
		case 2:
			mSprite.setTexture(Resources::textures->get(Resources::rock));
			break;
		case 3:
			mSprite.setTexture(Resources::textures->get(Resources::wood));
			break;
		case 4:
			mSprite.setTexture(Resources::textures->get(Resources::water));
			break;
		case 5:
			mSprite.setTexture(Resources::textures->get(Resources::wall));
			mSprite.setOrigin(mSprite.getLocalBounds().width - 50.0f, mSprite.getLocalBounds().height - 50.0f);
			break;
		case 6:
			mSprite.setTexture(Resources::textures->get(Resources::stoneWall));
			mSprite.setOrigin(mSprite.getLocalBounds().width - 50.0f, mSprite.getLocalBounds().height - 50.0f);
			break;
	}
}

void SpriteEntity::draw(sf::RenderWindow& window, const sf::Vector2f& camPos){
	sf::Vector2f screenPos = getPosition() - camPos;
	screenPos *= 50.0f;
	sf::RenderStates states;
	states.transform.translate(screenPos);
	window.draw(mSprite, states);
}