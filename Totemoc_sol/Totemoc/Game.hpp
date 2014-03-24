#ifndef TOTEMOC_GAME_HPP
#define TOTEMOC_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SizeConstants.hpp"
#include "TimeConstants.hpp"
#include "Statistics.hpp"
#include "World.hpp"

class Game {
public:
	Game();
	void run();

private:
	sf::RenderWindow mWindow;
	Statistics mStats;
	World mWorld;

	void processEvents();
	void update();
	void render();

};

#endif //TOTEMOC_GAME_HPP