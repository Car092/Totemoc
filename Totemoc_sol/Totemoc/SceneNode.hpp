#ifndef TOTEMOC_SCENENODE_HPP
#define TOTEMOC_SCENENODE_HPP

#include <memory>
#include <vector>
#include <SFML\Graphics.hpp>

class SceneNode : public sf::Transformable, private sf::NonCopyable{

	public:
		SceneNode();
		void attachChild(SceneNode* child);
		SceneNode* detachLeaf(SceneNode* leaf);
		void update(const sf::Time& dt);
		void draw(sf::RenderTarget& target, sf::Vector2f camera) const;

	private:
		void updateChildren(const sf::Time& dt);
		void drawChildren(sf::RenderTarget& target, sf::Vector2f camera) const;
		virtual void updateCurrent(const sf::Time& dt);
		virtual void drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const;
		
	private:
		std::vector<SceneNode*> mChildren;
		SceneNode* mParent;
};

#endif //TOTEMOC_SCENENODE_HPP