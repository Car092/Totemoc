#ifndef TOTEMOC_RESOURCES_HPP
#define TOTEMOC_RESOURCES_HPP

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"

class Resources{
public:
	enum TextureID{
		player,
		playerRight,
		playerLeft,
		playerBack,
		playerFR,
		playerFL,
		playerBR,
		playerBL,
		grass,
		dirt,
		water,
		rock,
		wood,
		wall,
		stoneWall
	};
	enum FontID{
		estre
	};
	static ResourceHolder<sf::Texture, TextureID>* textures;
	static ResourceHolder<sf::Font, FontID>* fonts;

	Resources();
	~Resources();
};

#endif //TOTEMOC_RESOURCES_HPP