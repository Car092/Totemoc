#include "Tile.hpp"
#include "Resources.hpp"

Tile::Tile(int type){
	switch (type){
		case 0:
			mSprite.setTexture(Resources::textures->get(Resources::TextureID::grass));
			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

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