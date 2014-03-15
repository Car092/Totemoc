#include <SFML/Graphics.hpp>

class Player
{

private:
	sf::Vector2f mWorldPos;
	sf::Vector2f mWorldDest;
	const sf::Vector2f mScreenPos;
	sf::Vector2f mDir;
	float mSpeed;
	sf::Sprite mSprite;
	sf::Texture mTexture;
public:
	Player();
	void update(sf::Time dt);
	sf::Vector2f getWorldPos();
	void draw(sf::RenderWindow& window);
};