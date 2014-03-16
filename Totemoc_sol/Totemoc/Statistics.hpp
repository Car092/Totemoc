#ifndef TOTEMOC_STATISTICS_HPP
#define TOTEMOC_STATISTICS_HPP

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Resources.hpp"

class Statistics{
private:
	sf::Text mText;
	sf::Time mTimeRender;
	sf::Time mTimeLogic;
	int mRenderFrames;
	int mLogicFrames;

public:
	Statistics();
	void updateRender(sf::Time dt);
	void updateLogic(sf::Time dt);
	void draw(sf::RenderWindow& window);
};

#endif //TOTEMOC_STATISTICS_HPP