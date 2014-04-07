#ifndef TOTEMOC_WORLD_HPP
#define TOTEMOC_WORLD_HPP

#include <SFML\System.hpp>
#include "SceneNode.hpp"
#include "Tilemap.hpp"

class Player;

class World : sf::NonCopyable{
public:
	enum Layers{
		floorTilesLayer,
		onGroundLayer,
		standingLayer,
		tallTilesLayer
	};
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();

private:
	void initWorld();
	void initScene();
	void refreshTiles();
	void activateTiles();
	void activateTile(Tile* tile, std::vector<SpriteNode*>& floorTiles,
		std::vector<Entity*>& items, std::vector<Entity*>& living, std::vector<SpriteNode*>& tallTiles);
	void deactivateTiles();
	void deactivateTile(std::vector<Tile*>::iterator& tileIter, std::vector<SpriteNode*>& floorTiles,
		std::vector<Entity*>& items, std::vector<Entity*>& living, std::vector<SpriteNode*>& tallTiles, const sf::FloatRect& activeZone);

private:
	sf::RenderWindow& mWindow;
	Tilemap mTilemap;
	SceneNode mSceneGraph;
	SceneNode mFloorTileLayer;
	SceneNode mItemLayer;
	SceneNode mLivingLayer;
	SceneNode mTallTileLayer;
	std::vector<Tile*> mActiveTiles;
	Player* mPlayer;
	sf::Clock mTimeSinceActivate;
};

#endif //TOTEMOC_WORLD_HPP