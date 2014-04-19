#include "ConvexPolygon.hpp"

float calcLength(sf::Vector2f vector){
	return std::sqrtf(vector.x * vector.x + vector.y * vector.y);
}

float dot(sf::Vector2f v1, sf::Vector2f v2){
	return v1.x * v2.x + v1.y * v2.y;
}

ConvexPolygon::ConvexPolygon(){
	mDebugShape.setScale(50.0f, 50.0f);
	mDebugShape.setFillColor(sf::Color::Magenta);
	mDebugShape.setOutlineThickness(-0.05f);
	mDebugShape.setOutlineColor(sf::Color::Black);
}

void ConvexPolygon::addVertex(sf::Vector2f vertex){
	mVertices.push_back(vertex);
	mDebugShape.setPointCount(mVertices.size());
	mDebugShape.setPoint(mVertices.size() - 1, vertex);
}

void ConvexPolygon::calcNormals(){
	mNormals.clear();
	for (auto vertexIt = mVertices.begin(); vertexIt != mVertices.end();){
		sf::Vector2f v1 = *vertexIt;
		sf::Vector2f v2 = *(++vertexIt != mVertices.end() ? vertexIt : mVertices.begin());
		sf::Vector2f sepAxis = v1 - v2;
		float temp = sepAxis.x;
		sepAxis.x = sepAxis.y;
		sepAxis.y = temp * -1.0f;
		sepAxis /= calcLength(sepAxis);
		mNormals.push_back(sepAxis);
	}
}

std::vector<sf::Vector2f> ConvexPolygon::getNormals() const{
	return mNormals;
}

sf::Vector2f ConvexPolygon::calcProjInterval(const sf::Vector2f& normal) const{
	sf::Vector2f projInterval;
	float min = dot(mVertices[0] + mWorldPos, normal);
	float max = min;
	for (auto vertIt = ++mVertices.begin(); vertIt != mVertices.end(); vertIt++){
		float length = dot(*vertIt + mWorldPos, normal);
		if ( length > max){
			max = length;
		} else if (length < min){
			min = length;
		}
	}
	return sf::Vector2f(min, max);
}

void ConvexPolygon::updateWorldPos(sf::Vector2f pos){
	mWorldPos = pos;
}

bool ConvexPolygon::intersects(const ConvexPolygon& polyB) const{
	return false;
}

sf::Vector2f ConvexPolygon::checkUnwalkable(const ConvexPolygon& polyB) const{
	std::vector<sf::Vector2f> axesB = polyB.getNormals();
	std::vector<sf::Vector2f> axes = getNormals();
	axes.insert(axes.cend(), axesB.cbegin(), axesB.cend());
	float minPen = 10000.0f;
	sf::Vector2f mtv;
	for (sf::Vector2f axis : axes){
		float pen = 0.0f;
		sf::Vector2f intervalA = calcProjInterval(axis);
		sf::Vector2f intervalB = polyB.calcProjInterval(axis);
		if (intervalA.y > intervalB.x && intervalB.y > intervalA.x){
			if (intervalA.y - intervalB.x < intervalB.y - intervalA.x){
				pen = (intervalA.y - intervalB.x) * -1.0f;
			}
			else{
				pen = intervalB.y - intervalA.x;
			}
		}
		else{
			return sf::Vector2f(0.0f, 0.0f);
		}
		if (std::abs(pen) < std::abs(minPen)){
			minPen = pen;
			mtv = axis*minPen;
		}
	}
	return mtv;
}

void ConvexPolygon::debugDraw(sf::RenderWindow& window, sf::Vector2f camPos){
	mDebugShape.setPosition((mWorldPos - camPos) * 50.0f);
	window.draw(mDebugShape);
}

void ConvexPolygon::rotate(float degrees){
	sf::Transform transform;
	transform.rotate(degrees);
	for (unsigned i = 0; i < mVertices.size(); i++){
		mVertices[i] = transform * mVertices[i];
		mDebugShape.setPoint(i, mVertices[i]);
	}
}

