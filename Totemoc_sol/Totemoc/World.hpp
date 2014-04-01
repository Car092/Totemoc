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
	void initWorld();

private:
	sf::RenderWindow& mWindow;
	Tilemap mTilemap;
	Player* mPlayer;
};

#endif //TOTEMOC_WORLD_HPP