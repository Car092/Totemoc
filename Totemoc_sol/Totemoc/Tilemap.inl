template<typename Func>
void Tilemap::forEach_In_Zone(const sf::Vector2f& center, const sf::Vector2i& size, Func funcToDo){
	float activeZoneX = center.x - (size.x / 2);
	float activeZoneY = center.y - (size.y / 2);
	for (int j = 0; j < size.y; j++){
		for (int i = 0; i < size.x; i++){
			int tileX = (int)activeZoneX + i;
			int tileY = (int)activeZoneY + j;
			if (tileX < 0 || tileY < 0 || tileX >= (int)mMap[0].size() || tileY >= (int)mMap.size()){
				continue;
			}
			funcToDo(mMap[tileY][tileX], tileX, tileY);
		}
	}
}