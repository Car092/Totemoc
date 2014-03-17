#include <sstream>
#include "Statistics.hpp"

Statistics::Statistics():
mRenderFrames(),
mLogicFrames(),
mTimeRender(),
mTimeLogic(){
	mText.setFont(Resources::fonts->get(Resources::FontID::estre));
	mText.setString("Calculating statistics");
	mText.setColor(sf::Color::White);
	mText.setPosition(0.0f, 0.0f);
}

void Statistics::updateRender(sf::Time dt){
	mRenderFrames++;
	mTimeRender += dt;
}

void Statistics::updateLogic(sf::Time dt){
	mLogicFrames++;
	mTimeLogic += dt;
}

void Statistics::draw(sf::RenderWindow& window){
	if (mTimeLogic >= sf::seconds(1.0f) || mTimeRender > sf::seconds(1.0f)){
		std::stringstream updateMsg;
		updateMsg << "Render FPS: " << mRenderFrames << "\n";
		updateMsg << "Logic FPS: " << mLogicFrames;
		mText.setString(updateMsg.str());
		mTimeLogic = sf::Time::Zero;
		mTimeRender = sf::Time::Zero;
		mLogicFrames = 0;
		mRenderFrames = 0;
	}
	window.draw(mText);
}