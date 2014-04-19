#ifndef TOTEMOC_CONVEXPOLYGON_HPP
#define TOTEMOC_CONVEXPOLYGON_HPP

#include <vector>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

class ConvexPolygon{
public:
	ConvexPolygon();
	void calcNormals();
	void addVertex(sf::Vector2f vertex);
	std::vector<sf::Vector2f> getNormals() const;
	sf::Vector2f calcProjInterval(const sf::Vector2f& normal) const;
	void updateWorldPos(sf::Vector2f pos);
	bool intersects(const ConvexPolygon& polyB) const;
	sf::Vector2f checkUnwalkable(const ConvexPolygon& polyB) const;
	void debugDraw(sf::RenderWindow& window, sf::Vector2f camPos);
	void rotate(float degrees);

private:
	std::vector<sf::Vector2f> mVertices;
	std::vector<sf::Vector2f> mNormals;
	sf::Vector2f mWorldPos;
	sf::ConvexShape mDebugShape;
};

#endif //TOTEMOC_CONVEXPOLYGON_HPP