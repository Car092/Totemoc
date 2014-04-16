#include "Tilemap.hpp"
#include "Player.hpp"

Tilemap::Tilemap(){

}

void Tilemap::loadMap(std::vector<std::vector<int>>& map)
{
	for (int i = 0; i < (int)map.size(); i++){
		std::vector<Tile> row;
		for (int j = 0; j < (int)map[0].size(); j++){
			Tile tile(map[i][j]);
			tile.setPosition(sf::Vector2i(j, i));
			row.push_back(std::move(tile));
		}
		mMap.push_back(std::move(row));
	}
}

void Tilemap::refreshTiles(const sf::Vector2f& playerPos){
	std::vector<Tile::EntityPtr> itemsMoved;
	std::vector<Tile::EntityPtr> livingMoved;
	forEach_In_Zone(playerPos, sf::Vector2i(Sizes::EXTRA_TILES_PER_SCREEN.x, Sizes::EXTRA_TILES_PER_SCREEN.x),
		[&](Tile& tile, int tileX, int tileY){tile.dumpMoved(tileX, tileY, itemsMoved, livingMoved); });
	for (Tile::EntityPtr& item : itemsMoved){
		int tileX = (int)item->getPosition().x;
		int tileY = (int)item->getPosition().y;
		mMap[tileX][tileY].pushItem(std::move(item));
	}
	for (Tile::EntityPtr& livingElem : livingMoved){
		int tileX = (int)livingElem->getPosition().x;
		int tileY = (int)livingElem->getPosition().y;
		mMap[tileY][tileX].pushLiving(std::move(livingElem));
	}
}

void Tilemap::update(const sf::Time& dt, Tilemap* tilemap, const sf::Vector2f& playerPos){
	forEach_In_Zone(playerPos, Sizes::EXTRA_TILES_PER_SCREEN, [&](Tile& tile, int tileX, int tileY){tile.update(dt, tilemap); });
}

void Tilemap::draw(sf::RenderWindow& window, const sf::Vector2f& playerPos){
	sf::Vector2f camPos = sf::Vector2f(playerPos.x - (float)Sizes::TILES_PER_SCREEN.x/2.0f, playerPos.y - (float)Sizes::TILES_PER_SCREEN.y/2.0f);
	forEach_In_Zone(playerPos, Sizes::EXTRA_TILES_PER_SCREEN, [&](Tile& tile, int tileX, int tileY){tile.drawLayer1(window, camPos); });
	forEach_In_Zone(playerPos, Sizes::EXTRA_TILES_PER_SCREEN, [&](Tile& tile, int tileX, int tileY){tile.drawLayer2(window, camPos); });
	forEach_In_Zone(playerPos, Sizes::EXTRA_TILES_PER_SCREEN, [&](Tile& tile, int tileX, int tileY){tile.drawLayer3(window, camPos); });
	forEach_In_Zone(playerPos, Sizes::EXTRA_TILES_PER_SCREEN, [&](Tile& tile, int tileX, int tileY){tile.drawLayer4(window, camPos); });
}

Tile& Tilemap::getTile(int tileX, int tileY){
	return mMap[tileY][tileX];
}