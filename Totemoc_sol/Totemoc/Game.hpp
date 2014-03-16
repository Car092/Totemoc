#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SizeConstants.hpp"
#include "TimeConstants.hpp"
#include "Player.hpp"
#include "Tilemap.hpp"

class Game {
public:
	Game();
	void run();

private:
	sf::RenderWindow mWindow;
	Player mPlayer;
	Tilemap mTilemap;

	void processEvents();
	void update();
	void render();

};