#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
public:
	
	Player();
	void update();

private:
	sf::Vector2f mWorldPos;
	const sf::Vector2i mScreenPos;
	int direction;
	float speed;
	sf::Texture texturePlayer;
};