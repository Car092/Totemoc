#include "Game.hpp"

Game::Game() :
mWindow(sf::VideoMode(Sizes::WINDOW_RESOLUTION.x, Sizes::WINDOW_RESOLUTION.y), "pTotemoc", sf::Style::Close), 
mPlayer(), 
mTilemap(),
mStats()
{

}

void Game::run(){
	sf::Clock clockLogic;
	sf::Clock clockRender;
	sf::Clock fixedStepClock;
	sf::Time fixedStepTime;
	while (mWindow.isOpen()){
		fixedStepTime += fixedStepClock.restart();
		while (fixedStepTime > Times::TIME_P_FRAME){
			fixedStepTime -= Times::TIME_P_FRAME;
			processEvents();
			update();
			mStats.updateLogic(clockLogic.restart());
		}
		render();
		mStats.updateRender(clockRender.restart());
		//sleep some of the extra time if frame was rendered faster than 120fps
		float leftOver = Times::TIME_P_FRAME.asSeconds() - fixedStepClock.getElapsedTime().asSeconds();
		if (leftOver > 0)
		{
			sf::sleep(sf::seconds(leftOver*0.5f));
		}
	}
}

void Game::processEvents(){
	sf::Event event;
	while (mWindow.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::update(){
	mPlayer.update(Times::TIME_P_FRAME);
}

void Game::render(){
	mWindow.clear();
	mTilemap.draw(mWindow, mPlayer.getWorldPos().x, mPlayer.getWorldPos().y);
	mPlayer.draw(mWindow);
	mStats.draw(mWindow);
	mWindow.display();
}