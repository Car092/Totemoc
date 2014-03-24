#include "World.hpp"
#include "Player.hpp"

World::World(sf::RenderWindow& window)
: mWindow(window),
mPlayer(nullptr),
mTilemap(),
mSceneGraph()
{
	buildScene();
}

void World::buildScene(){
	std::unique_ptr<Player> player(new Player());
	mPlayer = player.get();
	mSceneGraph.attachChild(std::move(player));
}

void World::draw(){
	mTilemap.draw(mWindow, mPlayer->getWorldPosition());
	mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt){
	mSceneGraph.update(dt);
}

