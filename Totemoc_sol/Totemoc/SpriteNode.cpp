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
	}
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const{
	sf::Vector2f screenPos = getPosition() - camera;
	screenPos *= 50.0f;
	sf::RenderStates states;
	states.transform.translate(screenPos);
	target.draw(mSprite, states);
}