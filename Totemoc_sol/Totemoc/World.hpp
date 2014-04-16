#ifndef TOTEMOC_WORLD_HPP
#define TOTEMOC_WORLD_HPP

#include <SFML\System.hpp>
#include "Tilemap.hpp"

class Player;

class World : sf::NonCopyable{
public:
	explicit World(sf::RenderWindow& window);
	void update(const sf::Time& dt);
	void draw();
	Player* getPlayer();

private:
	void initWorld();
	void refreshTiles();

private:
	sf::RenderWindow& mWindow;
	Tilemap mTilemap;
	Player* mPlayer;
	sf::Clock mTimeSinceActivate;
};

#endif //TOTEMOC_WORLD_HPP