#include "SpriteNode.hpp"
#include "Resources.hpp"

SpriteNode::SpriteNode(int type){
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

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const{
	sf::Vector2f screenPos = getPosition() - camera;
	screenPos *= 50.0f;
	sf::RenderStates states;
	states.transform.translate(screenPos);
	target.draw(mSprite, states);
}