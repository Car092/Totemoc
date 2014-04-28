#include "Game.hpp"

Game::Game() :
mWindow(sf::VideoMode(Sizes::WINDOW_RESOLUTION.x, Sizes::WINDOW_RESOLUTION.y), "pTotemoc", sf::Style::Close), 
mStats(),
mWorld(mWindow),
mPlayerController(mWorld.getPlayer()),
mIsPaused(false)
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
			processInput();
			if(!mIsPaused) update();
			mStats.updateLogic(clockLogic.restart());
		}
		render();
		mStats.updateRender(clockRender.restart());
		//sleep some of the extra time if frame was rendered faster than 120fps
		float leftOver = Times::TIME_P_FRAME.asSeconds() - fixedStepClock.getElapsedTime().asSeconds();
		if (leftOver > 0)
		{
//			sf::sleep(sf::seconds(leftOver*0.5f));
		}
	}
}

void Game::processInput(){
	sf::Event event;
	while (mWindow.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			mWindow.close();
		if (event.type == sf::Event::LostFocus)
			mIsPaused = true;
		if (event.type == sf::Event::GainedFocus)
			mIsPaused = false;
		mPlayerController.handleEvent(event);
	}
	mPlayerController.handleRealtimeInput();
}

void Game::update(){
	mWorld.update(Times::TIME_P_FRAME);
}

void Game::render(){
	mWindow.clear();
	mWorld.draw();
	mStats.draw(mWindow);
	mWindow.display();
}