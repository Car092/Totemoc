#ifndef TOTEMOC_ENTITY_HPP
#define TOTEMOC_ENTITY_HPP

#include <SFML\System\Vector2.hpp>
#include "SceneNode.hpp"

class Entity : public SceneNode{
	public:
		Entity();
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity();
	private:
		virtual void updateCurrent(sf::Time dt);
		sf::Vector2f mVelocity;
};
#endif //TOTEMOC_ENTITY_HPP