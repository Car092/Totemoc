#ifndef TOTEMOC_ENTITY_HPP
#define TOTEMOC_ENTITY_HPP

#include <SFML\Graphics.hpp>
#include "ConvexPolygon.hpp"
#include <memory>

class Tilemap;

class Entity : public sf::Transformable{
	public:
		enum ColType{
			basic,
			nonwalkable
		};
		enum EntityType{
			entity,
			sprite,
			player,
			creature
		};
		Entity(Tilemap* tilemap);
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity();
		virtual void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
		virtual void update(const sf::Time& dt);
		virtual Entity::EntityType getType();
		void setColType(Entity::ColType colType);
		ConvexPolygon& getColPoly();
		Entity::ColType getColType();
		virtual void checkCollisions();
		void checkNonwalkable();
		virtual void destroySelf();

	protected:
		void putAttack(std::unique_ptr<Entity> attack, ConvexPolygon& attackPoly, float rotAngle, sf::Vector2f worldPos);

	protected:
		sf::Vector2f mVelocity;
		ConvexPolygon mColPoly;
		Entity::ColType mColType;
		Tilemap* mTilemap;
		bool mIsDead;
};
#endif //TOTEMOC_ENTITY_HPP