#include "Game.hpp"

Game::Game() :
mWindow(sf::VideoMode(1024, 768), "pTotemoc", sf::Style::Close)
, mPlayer(), mTilemap()
{

}

void Game::run(){
	while (mWindow.isOpen()){
		processEvents();
		update();
		render();
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
	mPlayer.update();
}

void Game::render(){
	mWindow.clear();
	mTilemap.draw(mWindow, (int)mPlayer.getWorldPos().x, (int)mPlayer.getWorldPos().y);
	mWindow.draw(mPlayer);
	mWindow.display();
}