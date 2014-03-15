#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	const sf::Time TIME_P_FRAME;

	void processEvents();
	void update();
	void render();

};