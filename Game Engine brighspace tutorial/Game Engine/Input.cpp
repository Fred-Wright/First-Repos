#include "Input.h"
#include "SDL.h"

Input::Input() {

}

Input::~Input() {

}

bool Input::keyIsPressed(Keys_Pressed_List k) {
	return false;
}

void Input::Update() {

	while (SDL_PollEvent(&event) != NULL) {
		if (event.type == SDL_KEYDOWN) {

			SDL_Keycode keyPressed = event.key.keysym.sym;

			switch (keyPressed) {
			case SDLK_ESCAPE:
				keysPressed[KEY_ESCAPE] = true;
				break;

			case SDLK_r:
				keysPressed[KEY_R] = true;
				break;

			case SDLK_g:
				keysPressed[KEY_G] = true;
				break;

			case SDLK_b:
				keysPressed[KEY_B] = true;
				break;

			}
		}
		else if (event.type == SDL_KEYUP) 
		{
			SDL_Keycode keyPressed = event.key.keysym.sym;

			switch (keyPressed) {
			
			case SDLK_r:
				keysPressed[KEY_R] = false;
				break;

			case SDLK_g:
				keysPressed[KEY_G] = false;
				break;

			case SDLK_b:
				keysPressed[KEY_B] = false;
				break;

			}
		}

		
	}


}