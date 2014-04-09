#ifndef TOTEMOC_SCENENODE_HPP
#define TOTEMOC_SCENENODE_HPP

#include <memory>
#include <vector>
#include <SFML\Graphics.hpp>

class Tilemap;

class SceneNode : public sf::Transformable, private sf::NonCopyable{

	public:
		enum class ColType{
			basic,
			unwalkable
		};
		SceneNode();
		void attachChild(SceneNode* child);
		SceneNode* detachLeaf(SceneNode* leaf);
		void update(const sf::Time& dt, Tilemap* tilemap);
		void draw(sf::RenderTarget& target, sf::Vector2f camera) const;
		void setColRect(sf::Vector2f size, sf::Vector2f posRel = sf::Vector2f(0.0f, 0.0f));
		void setColType(SceneNode::ColType colType);
		const sf::FloatRect& getColRect();
		SceneNode::ColType getColType();

	private:
		void updateChildren(const sf::Time& dt, Tilemap* tilemap);
		void drawChildren(sf::RenderTarget& target, sf::Vector2f camera) const;
		virtual void updateCurrent(const sf::Time& dt, Tilemap* tilemap);
		virtual void drawCurrent(sf::RenderTarget& target, sf::Vector2f camera) const;
		virtual void checkCollisions(Tilemap* tilemap);
		
	private:
		std::vector<SceneNode*> mChildren;
		SceneNode* mParent;

	protected:
		sf::FloatRect mColRect;
		SceneNode::ColType mColType;

};

#endif //TOTEMOC_SCENENODE_HPP