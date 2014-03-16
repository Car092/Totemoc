#include "Resources.hpp"

ResourceHolder<sf::Texture, Resources::TextureID> Resources::textures = ResourceHolder<sf::Texture, Resources::TextureID>();
ResourceHolder<sf::Font, Resources::FontID> Resources::fonts = ResourceHolder<sf::Font, Resources::FontID>();

Resources::Resources(){
	fonts.load(Resources::FontID::estre, "Resource Files/estre.ttf");
	textures.load(Resources::TextureID::player, "Resource Files/Old_Outfit_Male.png");
}