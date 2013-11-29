#include "Laser.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "vec2.h"

Laser::Laser(vec2 origin, vec2 dir) : origin(origin), dir(dir), angle(dir.degrees()) { }
Laser::Laser(vec2 origin, float deg) : origin(origin), dir(deg2vec(deg)), angle(deg) { }

void Laser::draw() {
	glPushMatrix();
	glColor3f(1, .2, .1);
	//Translate and rotate the matrix
	glTranslatef(origin.x, origin.y, 0);
	glRotatef(angle, 0, 0, 1);
	//Draw the laser
	glBegin(GL_TRIANGLES);
	glVertex2f(0, .1);
	glVertex2f(100, .1);
	glVertex2f(100, -.1);
	glVertex2f(100, -.1);
	glVertex2f(0, -.1);
	glVertex2f(0, .1);
	glEnd();
	//Return to normal rendering
	glPopMatrix();
}