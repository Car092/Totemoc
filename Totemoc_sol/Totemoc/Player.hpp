#ifndef TOTEMOC_PLAYER_HPP
#define TOTEMOC_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "SizeConstants.hpp"
#include "Resources.hpp"
#include "Entity.hpp"

class Attack;

class Player : public Entity 
{
private:
	float mSpeed;
	sf::Sprite mSprite;

public:
	Player(Tilemap* tilemap);
	void update(const sf::Time& dt);
	void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void checkCollisions();
	void correctCol(const ConvexPolygon& polyB);
	void attack(sf::Vector2f mousePos);

private:
	void putAttack(std::unique_ptr<Entity> attack, ConvexPolygon& attackPoly, float rotAngle, sf::Vector2f worldPos);
};

#endif //TOTEMOC_PLAYER_HPP