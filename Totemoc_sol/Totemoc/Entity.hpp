#ifndef TOTEMOC_ENTITY_HPP
#define TOTEMOC_ENTITY_HPP

#include <SFML\Graphics.hpp>

class Entity : public sf::Transformable{
	public:
		Entity();
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity();
		virtual void draw(sf::RenderTarget& target);
		virtual void update(sf::Time dt);

	private:
		sf::Vector2f mVelocity;
};
#endif //TOTEMOC_ENTITY_HPP