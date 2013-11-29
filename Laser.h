#ifndef TGJ_LASER_INCLUDED
#define TGJ_LASER_INCLUDED

#include "vec2.h"

class Laser {
	vec2 origin, dir;
	float angle, time;
public:
	Laser(vec2, float);
	Laser(vec2, vec2);
	void draw();
};

#endif