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

void SceneNode::update(const sf::Time& dt, Tilemap* tilemap){
	updateCurrent(dt, tilemap);
	updateChildren(dt, tilemap);
}

void SceneNode::updateCurrent(const sf::Time& dt, Tilemap* tilemap){

}

void SceneNode::updateChildren(const sf::Time& dt, Tilemap* tilemap){
	for (SceneNode* child : mChildren){
		child->update(dt, tilemap);
	}
}

void SceneNode::setColRect(sf::Vector2f size, sf::Vector2f posRel){
	mColRect = sf::FloatRect(posRel, size);
}

const sf::FloatRect& SceneNode::getColRect(){
	mColRect.left = getPosition().x;
	mColRect.top = getPosition().y;
	return mColRect;
}

void SceneNode::checkCollisions(Tilemap* tilemap){

}

SceneNode::ColType SceneNode::getColType(){
	return mColType;
}

void SceneNode::setColType(SceneNode::ColType colType){
	mColType = colType;
}