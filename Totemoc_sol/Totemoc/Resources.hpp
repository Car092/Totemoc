#ifndef TOTEMOC_RESOURCES_HPP
#define TOTEMOC_RESOURCES_HPP

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"

class Resources{
public:
	enum TextureID{
		player
	};
	enum FontID{
		estre
	};
	Resources();
	static ResourceHolder<sf::Texture, TextureID> textures;
	static ResourceHolder<sf::Font, FontID> fonts;
};

#endif //TOTEMOC_RESOURCES_HPP