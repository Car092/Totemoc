#ifndef TOTEMOC_GAME_HPP
#define TOTEMOC_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SizeConstants.hpp"
#include "TimeConstants.hpp"
#include "Statistics.hpp"
#include "World.hpp"
#include "PlayerController.hpp"

class Game {
public:
	Game();
	void run();

private:
	sf::RenderWindow mWindow;
	Statistics mStats;
	World mWorld;
	PlayerController mPlayerController;
	bool mIsPaused;

	void processInput();
	void update();
	void render();

};

#endif //TOTEMOC_GAME_HPP