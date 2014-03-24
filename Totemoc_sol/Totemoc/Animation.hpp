#ifndef TOTEMOC_ANIMATION_HPP
#define TOTEMOC_ANIMATION_HPP

#include <SFML/Graphics.hpp>

class Animation : public sf::Drawable, public sf::Transformable
{
public:
	
private:
	
	sf::Sprite mSprite;
	sf::Vector2i mFrameSize;
	std::size_t mNumFrames;
	std::size_t mCurrentFrame;
	sf::Time mDuration;
	sf::Time mElapsedTime;
	bool mRepeat;
	void update(sf::Time dt);
};
#endif //TOTEMOC_ANIMATION_HPP