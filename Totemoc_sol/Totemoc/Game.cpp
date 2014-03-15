#include "Game.hpp"

Game::Game() :
mWindow(sf::VideoMode(1024, 768), "pTotemoc", sf::Style::Close)
, 
mPlayer(), 
mTilemap(),
TIME_P_FRAME(sf::Time(sf::seconds(1.0f/120.0f)))
{

}

void Game::run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()){
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIME_P_FRAME){
			timeSinceLastUpdate -= TIME_P_FRAME;
			processEvents();
			update();
		}
		render();
		//sleep some of the extra time if frame was rendered faster than 120fps
		float leftOver = TIME_P_FRAME.asSeconds() - clock.getElapsedTime().asSeconds();
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
	mPlayer.update(TIME_P_FRAME);
}

void Game::render(){
	mWindow.clear();
	mTilemap.draw(mWindow, (int)mPlayer.getWorldPos().x, (int)mPlayer.getWorldPos().y);
	mPlayer.draw(mWindow);
	mWindow.display();
}