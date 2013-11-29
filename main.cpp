#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

//Variables:
SDL_Surface *screen;
bool running = true;
//Used for FPS capping:
int FPS = 60;

Uint32 start;

//Functions:
void quit(int);
void render();
void events();
void matchfps();

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) quit(1);
	screen = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
	SDL_WM_SetCaption("Thankful Jam", NULL);
	while (running) {
		start = SDL_GetTicks();
		render();
		events();
		matchfps();
	}
	quit(0);
}

void render() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapBuffers();
}

void events() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
				break;
		}
	}
}

void quit(int rc) {
	exit(rc);
}

void matchfps() {
	if(1000/FPS > SDL_GetTicks()-start){
		SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
	}
}
