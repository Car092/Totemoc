template<typename Func>
void Tilemap::forEach_In_ActiveZone(const sf::Vector2f& playerPos, Func funcToDo){
	float activeZoneX = playerPos.x - (Sizes::EXTRA_TILES_PER_SCREEN.x / 2);
	float activeZoneY = playerPos.y - (Sizes::EXTRA_TILES_PER_SCREEN.y / 2);
	for (int j = 0; j < Sizes::EXTRA_TILES_PER_SCREEN.y; j++){
		for (int i = 0; i < Sizes::EXTRA_TILES_PER_SCREEN.x; i++){
			int tileX = (int)activeZoneX + i;
			int tileY = (int)activeZoneY + j;
			if (tileX < 0 || tileY < 0 || tileX >= (int)mMap[0].size() || tileY >= (int)mMap.size()){
				continue;
			}
			funcToDo(mMap[tileY][tileX], tileX, tileY);
		}
	}
}