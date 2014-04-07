#include "World.hpp"
#include "Player.hpp"

World::World(sf::RenderWindow& window)
: mWindow(window),
mPlayer(nullptr),
mSceneGraph(),
mActiveTiles()
{
	std::unique_ptr<Player> player(new Player);
	mPlayer = player.get();
	initWorld();
	initScene();
	mTilemap.getTile(20, 20).pushLiving(std::move(player));
	mPlayer->setPosition(20, 20);
	mTilemap.getTile(21, 21).mTallSprite = std::unique_ptr<SpriteNode>(new SpriteNode(5));
	mTilemap.getTile(22, 21).mTallSprite = std::unique_ptr<SpriteNode>(new SpriteNode(5));
	mTilemap.getTile(20, 20).mTallSprite = std::unique_ptr<SpriteNode>(new SpriteNode(6));
}

void World::initWorld(){
	std::vector<std::vector<int>> map = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 2, 2, 2, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 0, 2, 2, 2, 2, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 4, 4, 4, 4, 4 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 4, 4, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 2, 0, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 2, 0, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 2, 0, 2, 0, 0, 0, 0, 0 }
	};

	mTilemap.loadMap(map);

}

void World::initScene(){
	mSceneGraph.attachChild(&mFloorTileLayer);
	mSceneGraph.attachChild(&mItemLayer);
	mSceneGraph.attachChild(&mLivingLayer);
	mSceneGraph.attachChild(&mTallTileLayer);
}

void World::draw(){
	float activeZoneX = mPlayer->getPosition().x - (float)Sizes::TILES_PER_SCREEN.x / 2;
	float activeZoneY = mPlayer->getPosition().y - (float)Sizes::TILES_PER_SCREEN.y / 2;
	mSceneGraph.draw(mWindow, sf::Vector2f(activeZoneX, activeZoneY));
}

void World::update(sf::Time dt){
	mSceneGraph.update(dt);
	if (mTimeSinceActivate.getElapsedTime() > sf::seconds(0.3f)){
		refreshTiles();
		deactivateTiles();
		activateTiles();
		mTimeSinceActivate.restart();
	}
}

void World::refreshTiles(){
	mTilemap.refreshTiles(mPlayer->getPosition());
}

void World::deactivateTiles(){
	float activeZoneX = mPlayer->getPosition().x - (Sizes::EXTRA_TILES_PER_SCREEN.x / 2);
	float activeZoneY = mPlayer->getPosition().y - (Sizes::EXTRA_TILES_PER_SCREEN.y / 2);
	sf::FloatRect activeZone(sf::Vector2f(activeZoneX, activeZoneY), sf::Vector2f((float)Sizes::EXTRA_TILES_PER_SCREEN.x, (float)Sizes::EXTRA_TILES_PER_SCREEN.y));
	std::vector<SpriteNode*> floorTilesPtrs;
	std::vector<Entity*> itemsPtrs;
	std::vector<Entity*> livingPtrs;
	std::vector<SpriteNode*> tallTilesPtrs;
	auto it = mActiveTiles.begin();
	while (it != mActiveTiles.end()){
		deactivateTile(it, floorTilesPtrs, itemsPtrs, livingPtrs, tallTilesPtrs, activeZone);
	}
	for (SpriteNode* floorTile : floorTilesPtrs){
		mFloorTileLayer.detachLeaf(floorTile);
	}
	for (Entity* item : itemsPtrs){
		mItemLayer.detachLeaf(item);
	}
	for (Entity* livingElem : livingPtrs){
		mLivingLayer.detachLeaf(livingElem);
	}
	for (SpriteNode* tallTile : tallTilesPtrs){
		mTallTileLayer.detachLeaf(tallTile);
	}
}
void World::activateTiles(){
	std::vector<SpriteNode*> floorTilesPtrs;
	std::vector<Entity*> itemsPtrs;
	std::vector<Entity*> livingPtrs;
	std::vector<SpriteNode*> tallTilesPtrs;
	mTilemap.forEach_In_ActiveZone(mPlayer->getPosition(), [&](Tile& tile, int tileX, int tileY){
		activateTile(&tile, floorTilesPtrs, itemsPtrs, livingPtrs, tallTilesPtrs); 
	});
	for (SpriteNode* floorTile : floorTilesPtrs){
		mFloorTileLayer.attachChild(floorTile);
	}
	for (Entity* item : itemsPtrs){
		mItemLayer.attachChild(item);
	}
	for (Entity* livingElem : livingPtrs){
		mLivingLayer.attachChild(livingElem);
	}
	for (SpriteNode* tallTile : tallTilesPtrs){
		mTallTileLayer.attachChild(tallTile);
	}
}

void World::deactivateTile(std::vector<Tile*>::iterator& tileIter, std::vector<SpriteNode*>& floorTiles,
	std::vector<Entity*>& items, std::vector<Entity*>& living, std::vector<SpriteNode*>& tallTiles, const sf::FloatRect& activeZone){
	if (!activeZone.contains((float)(*tileIter)->getPosition().x, (float)(*tileIter)->getPosition().y)){
		(*tileIter)->packInVectors(floorTiles, items, living, tallTiles);
		tileIter = mActiveTiles.erase(tileIter);
	}
	else{
		tileIter++;
	}
}

void World::activateTile(Tile* tile, std::vector<SpriteNode*>& floorTiles,
	std::vector<Entity*>& items, std::vector<Entity*>& living, std::vector<SpriteNode*>& tallTiles){
	bool found = false;
	for (auto it = mActiveTiles.begin(); it != mActiveTiles.end(); it++){
		if (tile->getPosition() == (*it)->getPosition()){
			found = true;
		}
	}
	if (!found){
		mActiveTiles.push_back(tile);
		tile->packInVectors(floorTiles, items, living, tallTiles);
	}
}

