#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

using namespace std;

struct button{
	int x, y, w, h;
	button(int x, int y, bool clicked): x(x), y(y), w(w), h(h){ }
};