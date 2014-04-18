#ifndef TOTEMOC_ENTITY_HPP
#define TOTEMOC_ENTITY_HPP

#include <SFML\Graphics.hpp>
#include "ConvexPolygon.hpp"

class Tilemap;

class Entity : public sf::Transformable{
	public:
		enum ColType{
			basic,
			nonwalkable
		};
		Entity();
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity();
		virtual void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
		virtual void update(const sf::Time& dt, Tilemap* tilemap);
		void setColType(Entity::ColType colType);
		ConvexPolygon& getColPoly();
		Entity::ColType getColType();
		virtual void checkCollisions(Tilemap* tilemap);

	protected:
		sf::Vector2f mVelocity;
		ConvexPolygon mColPoly;
		Entity::ColType mColType;
};
#endif //TOTEMOC_ENTITY_HPP