#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SizeConstants.hpp"
#include "TimeConstants.hpp"
#include "Player.hpp"
#include "Tilemap.hpp"
#include "Statistics.hpp"

class Game {
public:
	Game();
	void run();

private:
	sf::RenderWindow mWindow;
	Player mPlayer;
	Tilemap mTilemap;
	Statistics mStats;

	void processEvents();
	void update();
	void render();

};