#ifndef TOTEMOC_UTILMATH_HPP
#define TOTEMOC_UTILMATH_HPP

#include <SFML\System\Vector2.hpp>
#include <math.h>

namespace tot{
	namespace{
		float calcLength(sf::Vector2f vector){
			return sqrtf(vector.x * vector.x + vector.y * vector.y);
		}

		float dot(sf::Vector2f v1, sf::Vector2f v2){
			return v1.x * v2.x + v1.y * v2.y;
		}

		sf::Vector2f normalize(sf::Vector2f vector){
			return vector / calcLength(vector);
		}
	}
}
#endif //TOTEMOC_UTILMATH_HPP