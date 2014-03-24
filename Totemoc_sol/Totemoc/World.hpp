#ifndef TOTEMOC_WORLD_HPP
#define TOTEMOC_WORLD_HPP

#include <SFML\System.hpp>
#include "SceneNode.hpp"
#include "Tilemap.hpp"

class Player;

class World : sf::NonCopyable{
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();

private:
	void buildScene();

private:
	sf::RenderWindow& mWindow;
	SceneNode mSceneGraph;
	Tilemap mTilemap;
	Player* mPlayer;
};

#endif //TOTEMOC_WORLD_HPP