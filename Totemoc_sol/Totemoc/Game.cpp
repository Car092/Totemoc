#include "Game.hpp"

Game::Game() :
mWindow(sf::VideoMode(1024, 768), "pTotemoc", sf::Style::Close)
, mPlayer()
{
	mPlayer.setPosition(100.f, 100.f);
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
	mWindow.draw(mPlayer);
	mWindow.display();
}