#ifndef TOTEMOC_PLAYERCONTROLLER_HPP
#define TOTEMOC_PLAYERCONTROLLER_HPP

#include <SFML\Window\Event.hpp>

class Player;

class PlayerController
{

public:
	PlayerController(Player* player);

	void					handleEvent(const sf::Event& event);
	void					handleRealtimeInput();

private:
	Player* mPlayer;
};

#endif // TOTEMOC_PLAYERCONTROLLER_HPP