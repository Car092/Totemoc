#ifndef TOTEMOC_ENTITY_HPP
#define TOTEMOC_ENTITY_HPP

#include <SFML\Graphics.hpp>

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
		void setColRect(sf::Vector2f size, sf::Vector2f posRel = sf::Vector2f(0.0f, 0.0f));
		void setColType(Entity::ColType colType);
		sf::FloatRect getColRect();
		Entity::ColType getColType();
		virtual void checkCollisions(Tilemap* tilemap);

	protected:
		sf::Vector2f mVelocity;
		sf::FloatRect mColRect;
		Entity::ColType mColType;
};
#endif //TOTEMOC_ENTITY_HPP