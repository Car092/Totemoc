#include "PlayerController.hpp"
#include "Player.hpp"

PlayerController::PlayerController(Player* player){
	mPlayer = player;
}

void PlayerController::handleRealtimeInput(){
		mPlayer->setVelocity(sf::Vector2f(0.0f, 0.0f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		mPlayer->setVelocity(mPlayer->getVelocity() += sf::Vector2f(-1.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		mPlayer->setVelocity(mPlayer->getVelocity() += sf::Vector2f(1.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		mPlayer->setVelocity(mPlayer->getVelocity() += sf::Vector2f(0.0f, -1.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		mPlayer->setVelocity(mPlayer->getVelocity() += sf::Vector2f(0.0f, 1.0f));
	}
}

void PlayerController::handleEvent(const sf::Event& event){
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Right){
		mPlayer->attack(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y));
	}
}