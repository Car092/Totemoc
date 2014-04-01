#include "Tilemap.hpp"
#include "Player.hpp"

Tilemap::Tilemap(){

}

void Tilemap::loadMap(std::vector<std::vector<int>>& map)
{
	for (int i = 0; i < (int)map.size(); i++){
		std::vector<Tile> row;
		for (int j = 0; j < (int)map[0].size(); j++){
			row.push_back(Tile(map[i][j]));
		}
		mMap.push_back(std::move(row));
	}
}

void Tilemap::draw(sf::RenderTarget& window, sf::Vector2f playerPos) {
	float offscreenCamX = playerPos.x - (Sizes::EXTRA_TILES_PER_SCREEN.x / 2);
	float offscreenCamY = playerPos.y - (Sizes::EXTRA_TILES_PER_SCREEN.y / 2);
	float camX = playerPos.x - (Sizes::TILES_PER_SCREEN.x / 2);
	float camY = playerPos.y - (Sizes::TILES_PER_SCREEN.y / 2);
	for (int j = 0; j < Sizes::EXTRA_TILES_PER_SCREEN.y; j++){
		for (int i = 0; i < Sizes::EXTRA_TILES_PER_SCREEN.x; i++){
			int tileX = (int)offscreenCamX + i;
			int tileY = (int)offscreenCamY + j;
			if (tileX < 0 || tileY < 0 || tileX >= (int)mMap[0].size() || tileY >= (int)mMap.size()){
				continue;
			}
			mMap[tileY][tileX].draw(window, tileX, tileY, camX, camY);
		}
	}
}

void Tilemap::update(sf::Time dt, sf::Vector2f playerPos){
	float offscreenCamX = playerPos.x - (Sizes::EXTRA_TILES_PER_SCREEN.x / 2);
	float offscreenCamY = playerPos.y - (Sizes::EXTRA_TILES_PER_SCREEN.y / 2);
	float camX = playerPos.x - (Sizes::TILES_PER_SCREEN.x / 2);
	float camY = playerPos.y - (Sizes::TILES_PER_SCREEN.y / 2);
	for (int j = 0; j < Sizes::EXTRA_TILES_PER_SCREEN.y; j++){
		for (int i = 0; i < Sizes::EXTRA_TILES_PER_SCREEN.x; i++){
			int tileX = (int)offscreenCamX + i;
			int tileY = (int)offscreenCamY + j;
			if (tileX < 0 || tileY < 0 || tileX >= (int)mMap[0].size() || tileY >= (int)mMap.size()){
				continue;
			}
			mMap[tileY][tileX].update(dt);
			updateMovingLayer(tileX, tileY);
		}
	}
}

void Tilemap::updateMovingLayer(int tileX, int tileY){
	std::vector<Tile::ItemPtr> itemsMoved;
	std::vector<Tile::EntityPtr> livingMoved;
	mMap[tileY][tileX].dumpMoved(tileX, tileY, itemsMoved, livingMoved);
	for (Tile::ItemPtr& item : itemsMoved){
		int tileX = (int)item->getPosition().x;
		int tileY = (int)item->getPosition().y;
		mMap[tileY][tileX].pushItem(std::move(item));
	}
	for (Tile::EntityPtr& entity : livingMoved){
		int tileX = (int)entity->getPosition().x;
		int tileY = (int)entity->getPosition().y;
		mMap[tileY][tileX].pushLiving(std::move(entity));
	}
}

Tile& Tilemap::getTile(int tileX, int tileY){
	return mMap[tileY][tileX];
}
