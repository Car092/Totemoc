#ifndef TOTEMOC_TILEMAP_HPP
#define TOTEMOC_TILEMAP_HPP

#include "Tile.hpp"
#include "SizeConstants.hpp"
#include "SceneNode.hpp"

class Player;

class Tilemap : public SceneNode{
	private:
		Player* mPlayer;
		std::vector<std::vector<Tile>> mMap;
	public:
		Tilemap(Player* player);
		void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //TOTEMOC_TILEMAP_HPP