#include "Resources.hpp"

ResourceHolder<sf::Texture, Resources::TextureID>* Resources::textures = new ResourceHolder<sf::Texture, Resources::TextureID>();
ResourceHolder<sf::Font, Resources::FontID>* Resources::fonts = new ResourceHolder<sf::Font, Resources::FontID>();

Resources::Resources(){
	fonts->load(Resources::FontID::estre, "Resource Files/estre.ttf");
	textures->load(Resources::TextureID::player, "Resource Files/Old_Outfit_Male.png");
	textures->load(Resources::TextureID::playerRight, "Resource Files/Old_Outfit_MaleRight.png");
	textures->load(Resources::TextureID::playerLeft, "Resource Files/Old_Outfit_MaleLeft.png");
	textures->load(Resources::TextureID::playerBack, "Resource Files/Old_Outfit_MaleBack.png");
}

Resources::~Resources(){
	delete textures;
	delete fonts;
}