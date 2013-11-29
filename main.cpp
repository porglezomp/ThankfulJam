#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "Player.h"

//Variables:
SDL_Surface *screen;
bool running = true;
//Used for FPS capping:
int FPS = 60;
Uint32 start;
//The player
Player player;
//What to do right now
int gamemode = 1;

int width = 640, height = 480;

//Functions:
void quit(int);
void render();
void events();
void matchfps();
int mainloop();

//main
int main(int argc, char *argv[]) {
	//Setup SDL and OpenGL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) quit(1);
	screen = SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
	if (screen == NULL) quit(2);
	SDL_WM_SetCaption("Thankful Jam", NULL);
	glColor3f(0, 0, 0);

	//Set the view dimensions
	float aspect = screen->w/(float)screen->h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10 * aspect, 10 * aspect, -10, 10, -1, 1);
	glMatrixMode(GL_MODELVIEW);

	while (running) {
		start = SDL_GetTicks();
		if (gamemode == 1) gamemode = mainloop();
		matchfps();
	}

	quit(0);
}

void render() {
	//Clear
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw the player
	player.draw();
	//Update the screen
	SDL_GL_SwapBuffers();
}

//Handle events
void events() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			//Handle quit events
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				player.input(event);
				//Also quit on the escape key
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				break;
			case SDL_KEYUP:
				player.input(event);
				break;
		}
	}
}

//Quits and handles cleanup
//Because apparently atexit() is evil
void quit(int rc) {
	SDL_Quit();
	exit(rc);
}

//Waits for the remainder of the frame (until 1/FPS of a second)
void matchfps() {
	if(1000/FPS > SDL_GetTicks()-start){
		SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
	}
}

//The only loop right now
int mainloop() {
	player.update();
	render();
	events();
	//Stay in the mainloop
	return 1;
}
