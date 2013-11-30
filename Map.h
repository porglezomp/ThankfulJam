#ifndef TGJ_MAP_INCLUDED
#define TGJ_MAP_INCLUDED

class Tile;

class Map {
	Tile *data;
	int w, h;
	float screensize;
public:
	Map(int, int);
	~Map();
	Tile& getTile(int, int);
};

#endif