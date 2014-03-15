#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{

private:
	sf::Vector2f mWorldPos;
	const sf::Vector2i mScreenPos;
	int direction;
	float speed;
	sf::Texture texturePlayer;

public:
	Player();
	void update();
	sf::Vector2f getWorldPos();
};