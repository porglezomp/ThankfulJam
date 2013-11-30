#include "Map.h"
#include "Tile.h"
#include "Util.h"

Map::Map(int w, int h) : w(w), h(h), data(new Tile[w*h]) { }
Map::~Map() { delete[] data; }

Tile& Map::getTile(int x, int y) {
	x = clamp(x, 0, w);
	y = clamp(y, 0, h);
	return data[x + y*w];
}