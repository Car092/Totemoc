#include "SceneNode.hpp"
#include <algorithm>
#include <cassert>

SceneNode::SceneNode() : Transformable(),
mParent(nullptr),
mChildren(){
}

void SceneNode::attachChild(SceneNode* child){
	child->mParent = this;
	mChildren.push_back(child);
}

SceneNode* SceneNode::detachLeaf(SceneNode* node){
	auto found = std::find_if(mChildren.begin(), mChildren.end(), 
		[&](SceneNode* p)->bool{return p == node; });
	assert(found != mChildren.end());
	SceneNode* nodeFound = *found;
	mChildren.erase(found);
	return nodeFound;
}

void SceneNode::draw(sf::RenderTarget& target, sf::Vector2f camera) const{
	drawCurrent(target, camera);
	drawChildren(target, camera);
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const{
	
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::Vector2f camera) const{
	for (const SceneNode* child : mChildren){
		child->draw(target, camera);
	}
}

void SceneNode::update(const sf::Time& dt){
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(const sf::Time& dt){

}

void SceneNode::updateChildren(const sf::Time& dt){
	for (SceneNode* child : mChildren){
		child->update(dt);
	}
}