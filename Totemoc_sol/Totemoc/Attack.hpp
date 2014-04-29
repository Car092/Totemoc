#ifndef TOTEMOC_ATTACK_HPP
#define TOTEMOC_ATTACK_HPP

#include "Entity.hpp"

class Attack : public Entity{
public:
	Attack(Tilemap* tilemap);
	void draw(sf::RenderWindow& window, const sf::Vector2f& camPos);
	void update(const sf::Time& dt);
	void destroySelf();
};

#endif //TOTEMOC_ATTACK_HPP