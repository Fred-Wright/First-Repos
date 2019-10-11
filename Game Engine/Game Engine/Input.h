#pragma once
#include "SDL.h"

enum Keys_Pressed_List {
	KEY_ESCAPE, KEY_R, KEY_G, KEY_B, SIZE_OF_KEYS_PRESSED_ENUM
};

class Input 
{
public:
	void Update(void);
	bool keyIsPressed(Keys_Pressed_List key);

	Input();
	~Input();

private:
	SDL_Event event;
	bool keysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
};