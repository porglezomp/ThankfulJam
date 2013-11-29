#include <SDL/SDL.h>

//variables
float worldsize = 10;
int width = 640, height = 480;
float aspect = width/(float)height;

//Functions:
void quit(int);
void mouse(float*, float*);

//Quits and handles cleanup
//Because apparently atexit() is evil
void quit(int rc) {
	SDL_Quit();
	exit(rc);
}

//Get the mouse in worldspace
void mouse(float *x, float *y) {
	int px, py;
	SDL_GetMouseState(&px, &py);
	*x = ((px / (float)width) * (worldsize*2) - worldsize) * aspect;
	*y = (1 - (py / (float)height)) * (worldsize*2) - worldsize;
}
