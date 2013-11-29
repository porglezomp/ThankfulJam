#include "Player.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

//Initializer for the playermotion struct
playermotion::playermotion() : left(false), right(false), up(false), down(false), xrecent(0), yrecent(0) { }

//Player constructor
Player::Player() : x(0), y(0), motion(playermotion()), angle(0), speed(.1) { }

//Draw the player
void Player::draw() {
	//Save the matrix
	glPushMatrix();
	//Modify the matrix for the character
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);

	//Draw the character
	glBegin(GL_TRIANGLES);
	glVertex2f(-.5, -.5);
	glVertex2f(-.5, .5);
	glVertex2f(.5, .5);
	glVertex2f(.5, .5);
	glVertex2f(.5, -.5);
	glVertex2f(-.5, -.5);
	glEnd();

	//Reset the matrix
	glPopMatrix();
}

//Input handling
void Player::input(SDL_Event event) {
	switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_RIGHT ||
			    event.key.keysym.sym == SDLK_d) {
				motion.right = true;
				motion.xrecent = PM_RIGHT;
			}
	}
}

void Player::update() {
	if (motion.xrecent == PM_RIGHT) {
		x += speed;
	} else if (motion.xrecent == PM_LEFT) {
		x -= speed;
	}
	if (motion.yrecent == PM_UP) {
		y += speed;
	} else if (motion.yrecent == PM_DOWN) {
		y -= speed;
	}
}
