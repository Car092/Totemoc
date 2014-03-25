#include "Tile.hpp"
#include "Resources.hpp"

Tile::Tile(int type){
	switch (type){
		case 0:
			mSprite.setTexture(Resources::textures->get(Resources::TextureID::grass));
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

	}
}

void Tile::draw(sf::RenderTarget& target, int tileX, int tileY, float camX, float camY) const {
	sf::Vector2f screenPos;
	screenPos.x = (float)(tileX - camX)*Sizes::TILE_SIZE.x;
	screenPos.y = (float)(tileY - camY)*Sizes::TILE_SIZE.y;
	sf::RenderStates states;
	sf::Transform transform;
	states.transform = transform.translate(screenPos);
	target.draw(mSprite, states);
}