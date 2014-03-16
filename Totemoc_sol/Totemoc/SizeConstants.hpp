#ifndef TOTEMOC_SIZECONSTANTS_HPP
#define TOTEMOC_SIZECONSTANTS_HPP

#include <SFML\System.hpp>

namespace Sizes{
	const sf::Vector2i WINDOW_RESOLUTION = sf::Vector2i(1024, 768);
	const sf::Vector2i TILE_SIZE = sf::Vector2i(50, 50);
	const sf::Vector2i TILES_PER_SCREEN = sf::Vector2i(20, 15);
	const sf::Vector2i EXTRA_TILES_PER_SCREEN = sf::Vector2i(25, 20);
	const sf::Vector2i PLAYER_SCR_POS = sf::Vector2i((TILES_PER_SCREEN.x / 2)*TILE_SIZE.x, (TILES_PER_SCREEN.y / 2)*TILE_SIZE.y);
}

#endif //TOTEMOC_SIZECONSTANTS_HPP