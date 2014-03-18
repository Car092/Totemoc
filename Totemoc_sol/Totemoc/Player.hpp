#ifndef TOTEMOC_PLAYER_HPP
#define TOTEMOC_PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player{

	private:
		sf::Vector2f mWorldPos;
		const sf::Vector2i mScreenPos;
		int direction;
		float speed;
		sf::Sprite mSpritePlayer;
		sf::Texture mTexturePlayer;

	public:
		Player();
		void update();
		void draw();
};
#endif //TOTEMOC_PLAYER_HPP