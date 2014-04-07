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
	forEach_In_ActiveZone(playerPos, [&](Tile& tile, int tileX, int tileY){tile.dumpMoved(tileX, tileY, itemsMoved, livingMoved);});
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

Tile& Tilemap::getTile(int tileX, int tileY){
	return mMap[tileY][tileX];
}