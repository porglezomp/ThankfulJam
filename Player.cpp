#include "Player.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "vec2.h"

//Initializer for the playermotion struct
playermotion::playermotion() : left(false), right(false), up(false), down(false), xrecent(0), yrecent(0) { }

//Player constructor
Player::Player() : pos(0), motion(playermotion()), angle(0), speed(.1) { }

//Draw the player
void Player::draw() {
	//Save the matrix
	glPushMatrix();
	//Modify the matrix for the character
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angle, 0, 0, 1);

	glColor3f(0, 0, 0);
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
			//Process is the same for all motion keys
			//So only described for the right key
			if (event.key.keysym.sym == SDLK_RIGHT ||
			    event.key.keysym.sym == SDLK_d) {
				//Say that the right arrow (or D) is pressed
				motion.right = true;
				//Set the most recent key pressed to right
				motion.xrecent = PM_RIGHT;
			}
			if (event.key.keysym.sym == SDLK_LEFT ||
			    event.key.keysym.sym == SDLK_a) {
				motion.left = true;
				motion.xrecent = PM_LEFT;
			}
			if (event.key.keysym.sym == SDLK_UP ||
			    event.key.keysym.sym == SDLK_w) {
				motion.up = true;
				motion.yrecent = PM_UP;
			}
			if (event.key.keysym.sym == SDLK_DOWN ||
			    event.key.keysym.sym == SDLK_s) {
				motion.down = false;
				motion.yrecent = PM_DOWN;
			}
			break;
		case SDL_KEYUP:
			//Process is the same for all motion keys
			if (event.key.keysym.sym == SDLK_RIGHT ||
			    event.key.keysym.sym == SDLK_d) {
				//Stop moving to the right
				motion.right = false;
				//If the left key is also pressed, start moving to the left
				if (motion.left) motion.xrecent = PM_LEFT;
				//If it's not, you can just stop moving
				else motion.xrecent = PM_NONE;
			}
			if (event.key.keysym.sym == SDLK_LEFT ||
			    event.key.keysym.sym == SDLK_a) {
				motion.left = false;
				if (motion.right) motion.xrecent = PM_RIGHT;
				else motion.xrecent = PM_NONE;
			}
			if (event.key.keysym.sym == SDLK_UP ||
			    event.key.keysym.sym == SDLK_w) {
				motion.up = false;
				if (motion.down) motion.yrecent = PM_DOWN;
				else motion.yrecent = PM_NONE;
			}
			if (event.key.keysym.sym == SDLK_DOWN ||
			    event.key.keysym.sym == SDLK_s) {
				motion.down = false;
				if (motion.up) motion.yrecent = PM_UP;
				else motion.yrecent = PM_NONE;
			}
			break;
	}
}

//Handle player motion
void Player::update() {
	//Handle diagonal motion
	float fac = 1;
	if (motion.xrecent != PM_NONE && motion.yrecent != PM_NONE) fac = .7071067;
	//Move using the most recent key pressed on an axis
	//Left and right
	if (motion.xrecent == PM_RIGHT) {
		pos.x += speed * fac;
	} else if (motion.xrecent == PM_LEFT) {
		pos.x -= speed * fac;
	}
	//Up and down
	if (motion.yrecent == PM_UP) {
		pos.y += speed * fac;
	} else if (motion.yrecent == PM_DOWN) {
		pos.y -= speed * fac;
	}

	//Restrict the player inside the window
	if (pos.x < -12.83) pos.x = -12.83;
	if (pos.x > 12.83) pos.x = 12.83;
	if (pos.y < -9.5) pos.y = -9.5;
	if (pos.y > 9.5) pos.y = 9.5;
}
