#ifndef TOTEMOC_GAME_HPP
#define TOTEMOC_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hpp"

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

};
#endif //TOTEMOC_GAME_HPP