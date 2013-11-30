#ifndef TGJ_MENU_INC
#define TGJ_MENU_INC

struct button{
	float x, y, w, h;
	button(float, float, float, float);
	bool wasClicked(float, float);
};

#endif
