#ifndef	TGJ_PLAYER_INC
#define TGJ_PLAYER_INC
#include <SDL/SDL.h>
#include "vec2.h"

#define PM_NONE	0
#define PM_LEFT	1
#define PM_RIGHT	2
#define PM_UP	4
#define PM_DOWN	8

struct playermotion {
	bool left, right, up, down;
	int xrecent, yrecent;
	playermotion();
};

class Player {
	vec2 pos;
	float angle;
	float speed;
	playermotion motion;
public:
	Player();
	void draw();
	void input(SDL_Event);
	void update();
};

#endif
