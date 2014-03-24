#include "World.hpp"
#include "Player.hpp"

World::World(sf::RenderWindow& window) 
: mWindow(window),
mPlayer(nullptr),
mSceneGraph()
{
	buildScene();
}

void World::buildScene(){
	std::unique_ptr<Player> player(new Player());
	mSceneGraph.attachChild(std::unique_ptr<Tilemap>(new Tilemap(player.get())));
	mPlayer = player.get();
	mSceneGraph.attachChild(std::move(player));
}

void World::draw(){
	mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt){
	mSceneGraph.update(dt);
}

