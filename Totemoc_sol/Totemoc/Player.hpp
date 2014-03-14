#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
public:
	
	Player();
	void update();

private:
	int direction;
	float speed;
	sf::Texture texturePlayer;
};