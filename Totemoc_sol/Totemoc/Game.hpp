#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Game {
public:

	Game();
	void run();

private:
	sf::RenderWindow mWindow;
	Player mPlayer;

	void processEvents();
	void update();
	void render();

}