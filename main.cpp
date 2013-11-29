#include <SDL/SDL.h>
#include <SDL/SDL_main.h>

SDL_Surface *screen;

void quit(int);

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) quit(1);
	screen = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
	SDL_GL_SwapBuffers();
	SDL_Delay(1000);
	quit(0);
}

void quit(int rc) {
	exit(rc);
}
