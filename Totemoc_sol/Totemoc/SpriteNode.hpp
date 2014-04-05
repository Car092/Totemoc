#ifndef TOTEMOC_SPRITENODE_HPP
#define TOTEMOC_SPRITENODE_HPP

#include "SceneNode.hpp"

class SpriteNode : public SceneNode{
private:
	sf::Sprite mSprite;

public:
	SpriteNode(int type);
	void drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const;
};

#endif //TOTEMOC_SPRITENODE_HPP