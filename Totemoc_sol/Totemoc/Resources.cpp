#include "Resources.hpp"

ResourceHolder<sf::Texture, Resources::TextureID>* Resources::textures = new ResourceHolder<sf::Texture, Resources::TextureID>();
ResourceHolder<sf::Font, Resources::FontID>* Resources::fonts = new ResourceHolder<sf::Font, Resources::FontID>();

Resources::Resources(){
	fonts->load(Resources::FontID::estre, "Resource Files/estre.ttf");
	textures->load(Resources::TextureID::player, "Resource Files/tib.png");
	textures->load(Resources::TextureID::playerRight, "Resource Files/tib_right.png");
	textures->load(Resources::TextureID::playerLeft, "Resource Files/tib_left.png");
	textures->load(Resources::TextureID::playerBack, "Resource Files/tib_up.png");
	textures->load(Resources::TextureID::playerFR, "Resource Files/charEnfDer.png");
	textures->load(Resources::TextureID::playerFL, "Resource Files/charEnfIzq.png");
	textures->load(Resources::TextureID::playerBR, "Resource Files/charAtrasDer.png");
	textures->load(Resources::TextureID::playerBL, "Resource Files/charAtrasIzq.png");
	textures->load(Resources::TextureID::grass, "Resource Files/grass.png");
	textures->load(Resources::TextureID::dirt, "Resource Files/dirt.png");
	textures->load(Resources::TextureID::water, "Resource Files/water.png");
	textures->load(Resources::TextureID::rock, "Resource Files/rock.png");
	textures->load(Resources::TextureID::wood , "Resource Files/wood.png");
	textures->load(Resources::TextureID::wall, "Resource Files/wall.png");
	textures->load(Resources::TextureID::stoneWall, "Resource Files/stoneWall.png");
}

Resources::~Resources(){
	delete textures;
	delete fonts;
}